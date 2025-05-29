import numpy as np
from calc_pv_training import calc_pv_training
from calc_px_training import calc_px_training

np.random.seed(0)

def wood_make_gibbs_y_spatial(Y, X, V, Z, R, lda, eps, sigmaU, sigmaV, phi, sigmaC):

    K, T = Y.shape
    Ynew = Y.copy()

    lpv_y = np.zeros((1, 2))
    lpx_y = np.zeros((1, 2))
    lpv_y_new, _, _, _ = calc_pv_training(X, V, Ynew, Z, sigmaU, sigmaV, phi, sigmaC, 0, 1)
    lpx_y_new = calc_px_training(X[:, 0:1], Ynew[:, 0:1], Z, lda, eps, 1)

    for t in range(1, T + 1):
        for k in range(1, K + 1):
            lpv_y[0, Ynew[k-1, t-1]] = lpv_y_new
            lpx_y[0, Ynew[k-1, t-1]] = lpx_y_new

            Ynew[k-1, t-1] = 1 - Ynew[k-1, t-1]

            lpv_y[0, Ynew[k-1, t-1]], _, _, _ = calc_pv_training(X, V, Ynew, Z, sigmaU, sigmaV, phi, sigmaC, 0, 1)
            lpx_y[0, Ynew[k-1, t-1]] = calc_px_training(X[:, t-1:t], Ynew[:, t-1:t], Z, lda, eps, 1)

            p = R[0, k-1]

            lPYk1_ZXYmk = np.log(p) + lpx_y[0, 1] + lpv_y[0, 1]
            lPYk0_ZXYmk = np.log(1 - p) + lpx_y[0, 0] + lpv_y[0, 0]

            rt = np.exp(lPYk1_ZXYmk - lPYk0_ZXYmk)

            if rt == np.inf:
                PYk_ZXYmk = 1
            else:
                PYk_ZXYmk = rt / (rt + 1)

            Ynew[k-1, t-1] = PYk_ZXYmk > np.random.rand(1,1)

            lpv_y_new = lpv_y[0, Ynew[k-1, t-1]]
            lpx_y_new = lpx_y[0, Ynew[k-1, t-1]]

    return Ynew