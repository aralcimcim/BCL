import numpy as np
from scipy.stats import beta, poisson
from calc_pv_training import calc_pv_training
from calc_px_training import calc_px_training

np.random.seed(0)

def wood_make_gibbs_z_spatial(Y, X, V, Z, R, lda, eps, sigmaU, sigmaV, phi, sigmaC, bAlpha, bBeta, alpha, Kmax, wburn, wsample):
    
    N, K = Z.shape
    T = X.shape[1]

    Znew = Z.copy()
    lpv_y = np.zeros((1,2))
    lpx_y = np.zeros((1,2))

    wall = wburn + wsample

    for n in range(1, N + 1):
        Znew = Z.copy()
        lpv_y_new, _, _, _ = calc_pv_training(X, V, Y, Znew, sigmaU, sigmaV, phi, sigmaC, 0, 1)
        lpx_y_new = calc_px_training(X[n-1, :], Y, Znew[n-1, :], lda, eps, 1)

        for k in range(1, K + 1):
            if n - 1 < N - 1:
                m_mnk = np.sum(Znew[np.r_[0:n-1, n:N], k-1])
            else:
                m_mnk = np.sum(Znew[0:n-1, k-1])

            th_k = m_mnk / N

            if m_mnk > 0:
                lpv_y[0, int(Znew[n-1, k-1])] = lpv_y_new
                lpx_y[0, int(Znew[n-1, k-1])] = lpx_y_new

                Znew[n-1, k-1] = 1 - Znew[n-1, k-1]

                lpv_y[0, int(Znew[n-1, k-1])], _, _, _ = calc_pv_training(X, V, Y, Znew, sigmaU, sigmaV, phi, sigmaC, 0, 1)
                lpx_y[0, int(Znew[n-1, k-1])] = calc_px_training(X[n-1, :], Y, Znew[n-1, :], lda, eps, 1)

                lPznk1_XZmnkY = np.log(th_k) + lpx_y[0, 1] + lpv_y[0, 1]
                lPznk0_XZmnkY = np.log(1 - th_k) + lpx_y[0, 0] + lpv_y[0, 0]
                
                rt = np.exp(lPznk1_XZmnkY - lPznk0_XZmnkY)

                if rt == np.inf:
                    Pznk_XZmnkY = 1
                else:
                    Pznk_XZmnkY = rt / (rt + 1)
            else:
                Pznk_XZmnkY = 0

            # uni = 0.77 in python, matlab 0.27
            uni = np.random.rand()
            Znew[n-1, k-1] = Pznk_XZmnkY > uni

            lpv_y_new = lpv_y[0, int(Znew[n-1, k-1])]
            lpx_y_new = lpx_y[0, int(Znew[n-1, k-1])]

        Z = Znew.copy()
        for k in range(1, K + 1):
            R[0, k-1] = beta.rvs((bAlpha + np.sum(Y[k-1, :])), (bBeta + T - np.sum(Y[k-1, :])))

        PKnew_XZY = np.zeros((1, Kmax + 1))
        PKnew_XZY_an = np.zeros((1, Kmax + 1))
        PKnew_XZY_5 = np.zeros((1, Kmax + 1))

        Ysample = {}
        Rsample = {}

        for Knew in range(Kmax + 1):
            lpy_xz = np.zeros((1, wsample))
            ZAct = np.hstack((Z, np.zeros((N, Knew))))
            if Knew > 0:
                ZAct[n - 1, K:K + Knew] = 1
            RAdd = beta.rvs(bAlpha, bBeta, size=(1,Knew))
            RAct = np.hstack([R, RAdd])
            if RAdd.shape == (1,0):
                RAdd = 0

            # rng result is different here, in matlab [1,0], in python [1,1]
            YAct = np.vstack([Y, (np.random.rand(Knew, T) < np.tile(RAdd, (Knew, 1))).astype(int)])

            lpv_y_act = np.zeros((1,2))
            lpx_y_act = np.zeros((1,2))
            
            lpv_y_new, _, _, _ = calc_pv_training(X, V, YAct, ZAct, sigmaU, sigmaV, phi, sigmaC, 0, 1)
            lpx_y_new = calc_px_training(X[n-1, :], YAct, ZAct[n-1, :], lda, eps, 1)

            if Knew > 0:
                lpy_v = np.zeros(wsample)
                lpy_x = np.zeros(wsample)
                lpy_xv = np.zeros(wsample)
                for wi in range(1, wall+1):
                    for t in range(1, T + 1):
                        for k in range(1, Knew + 1):
                            lpv_y_act[0, int(YAct[K + k-1, t-1])] = lpv_y_new
                            lpx_y_act[0, int(YAct[K + k-1, t-1])] = lpx_y_new

                            YAct[K + k-1, t-1] = 1 - YAct[K + k-1, t-1]
                            lpv_y_act[0, int(YAct[K + k-1, t-1])], _, _, _ = calc_pv_training(X, V, YAct, ZAct, sigmaU, sigmaV, phi, sigmaC, 0, 1)
                            lpx_y_act[0, int(YAct[K + k-1, t-1])] = calc_px_training(X[n-1, :], YAct, ZAct[n-1, :], lda, eps, 1)
                            p = RAct[0, (K + k-1)]
                            lPYk1_ZXYmk = np.log(p) + lpx_y_act[0,1] + lpv_y_act[0,1]
                            lPYk0_ZXYmk = np.log(1 - p) + lpx_y_act[0,0] + lpv_y_act[0,0]

                            rt = np.exp(lPYk1_ZXYmk - lPYk0_ZXYmk)

                            if rt == np.inf:
                                PYk1_ZXYmk = 1
                            else:
                                PYk1_ZXYmk = rt / (rt + 1)

                            # uni in python 0.45, uni in matlab 0.79
                            uni = np.random.uniform(0,1)
                            YAct[K + k-1, t-1] = PYk1_ZXYmk > uni

                            lpv_y_new = lpv_y_act[0, int(YAct[K + k-1, t-1])]
                            lpx_y_new = lpx_y_act[0, int(YAct[K + k-1, t-1])]

                    for k in range(1, Knew + 1):
                        RAct[0, (K + k-1)] = beta.rvs(bAlpha + np.sum(YAct[K + k-1, :]), bBeta + T - np.sum(YAct[K + k-1, :]))

                    if wi > wburn:
                        lpy_v[wi - wburn - 1] = lpv_y_new
                        lpy_x[wi - wburn - 1] = lpx_y_new
                        lpy_xv[wi - wburn - 1] = lpx_y_new + lpv_y_new

            else:
                lpx_y_new = calc_px_training(X[n-1, :], YAct, ZAct[n-1, :], lda, eps, 1)
                lpv_y_new, _, _, _ = calc_pv_training(X, V, YAct, ZAct, sigmaU, sigmaV, phi, sigmaC, 0, 1)
                lpy_xv = lpx_y_new + lpv_y_new

            if Knew == 0:
                py_xzKnew_5 = lpy_xv
            else:
                py_xzKnew_5 = np.log(wsample) - np.log(1) + np.max(lpy_xv) - np.log(np.sum(1.0 / np.exp(lpy_xv - np.max(lpy_xv))))

            PKnew_XZY_5[0, Knew] = (py_xzKnew_5 + np.log(poisson.pmf(Knew, alpha / N)))

            Ysample[Knew] = YAct
            Rsample[Knew] = RAct

        lpdf_5 = PKnew_XZY_5 - np.max(PKnew_XZY_5)
        pdf_5 = np.exp(lpdf_5) / np.sum(np.exp(lpdf_5))

        bar = np.random.rand()
        #in MATLAB bar = 0.7792
        j = 1
        while np.sum(pdf_5.flatten()[:j]) < bar:
            j += 1
        Knew = j-1

        Znew = np.hstack((Z, np.zeros((N, Knew))))
        Znew[n-1, K:K + Knew] = 1

        Z = Znew.copy()
        Y = Ysample[Knew]
        R = Rsample[Knew]

        col_sums = np.sum(Z, axis=0)
        nodes2keep = np.nonzero(col_sums)[0]
        if nodes2keep.size > 0:
            Z = Z[:, nodes2keep]
            Y = Y[nodes2keep, :]
            R = R[0, nodes2keep].reshape(1,-1)
            K = Z.shape[1]
        else:
            Z = np.zeros((N, 1))
            Y = np.zeros((1, T))
            R = np.zeros((1, 1))
            K = Z.shape[1]

    Znew = Z
    Ynew = Y
    Rnew = R

    return Znew, Ynew, Rnew