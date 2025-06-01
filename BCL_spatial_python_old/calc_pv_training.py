import numpy as np
from calc_pv_trial import calc_pv_trial
from scipy.stats import multivariate_normal
from scipy.linalg import inv
from helper_funcs import calc_pv_training_cache

@calc_pv_training_cache
def calc_pv_training(x, v, y, Z, sigmaU, sigmaV, phi, sigmaC, *args):
    nargs = len(args)
    dims = args[0] if nargs > 0 else 0
    logOutput = args[1] if nargs > 1 else 0

    N, T = x.shape
    K = Z.shape[1]
    availLinkNo = int(np.sum(Z))
    zc = np.zeros((N, K), dtype=bool)
    zl = Z.astype(bool)
    SigmaCtllhInv = np.zeros((availLinkNo, availLinkNo, T))
    wt = np.zeros((availLinkNo, T, 2))
    Psit = np.zeros((1, T, 2))

    for t in range(1, T+1):

        SigmaCtllhInv[:, :, t-1], wt[:, t-1, :], Psit[:, t-1, :], zct = calc_pv_trial(x[:, t-1:t], v[:, t-1, :] , y[:, t-1:t], Z, sigmaU, sigmaV, phi)
        zc = np.bitwise_or(zc, zct)
       
    SigmaCTllhInv = np.sum(SigmaCtllhInv, axis=2)
    SigmaCTpostInv = SigmaCTllhInv + np.diag(np.ones(availLinkNo)) / (sigmaC ** 2)
    SigmaCTpost = np.linalg.inv(SigmaCTpostInv)
    muCTpost = np.dot(SigmaCTpost, np.sum(wt[:, :, 0], axis=1))
    muCTpost = muCTpost[:, np.newaxis]
    muCTpost = np.concatenate((muCTpost, np.dot(SigmaCTpost, np.sum(wt[:,:,1], axis=1))[:, np.newaxis]), axis=1)
   
    muCTpostX = muCTpost[:, 0]
    muCTpostY = muCTpost[:, 1]

    #matches the result in matlab mvnormdfln
    if np.sum(zc):
        zc_zl = zc[zl]
        nfx = multivariate_normal.logpdf(muCTpostX[zc_zl], mean=np.zeros(np.sum(zc)), cov=inv(SigmaCTpostInv[zc_zl, :][:, zc_zl]))
        nfy = multivariate_normal.logpdf(muCTpostY[zc_zl], mean=np.zeros(np.sum(zc)), cov=inv(SigmaCTpostInv[zc_zl, :][:, zc_zl]))
    else:
        nfx = 0
        nfy = 0

    if logOutput == 0:
        p1 = np.prod(Psit[:, :, 0]) * (2 * np.pi) ** (-np.sum(zc) / 2) * sigmaC ** (-np.sum(zc)) / np.exp(nfx)
        p2 = np.prod(Psit[:, :, 1]) * (2 * np.pi) ** (-np.sum(zc) / 2) * sigmaC ** (-np.sum(zc)) / np.exp(nfy)

        if dims == 0:
            p = p1 * p2
        elif dims == 1:
            p = p1
        elif dims == 2:
            p = p2
        else:
            raise ValueError('calc_pv_training: wrong setting for optional argument dims')
    else:
        lp1 = np.sum(np.log(Psit[:, :, 0])) + np.log((2 * np.pi) ** (-np.sum(zc) / 2) * sigmaC ** (-np.sum(zc))) - nfx
        lp2 = np.sum(np.log(Psit[:, :, 1])) + np.log((2 * np.pi) ** (-np.sum(zc) / 2) * sigmaC ** (-np.sum(zc))) - nfy

        if dims == 0:
            p = lp1 + lp2
        elif dims == 1:
            p = lp1
        elif dims == 2:
            p = lp2
        else:
            raise ValueError('calc_pv_training: wrong setting for optional argument dims')

    return p, muCTpost, SigmaCTpostInv, SigmaCTpost