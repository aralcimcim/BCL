import numpy as np

def calc_px_training(X, Y, Z, lda, eps, *args):
    nargs = len(args)
    isLog = args[0] if nargs > 0 else 0

    #print(Z.shape)

    # if Z.ndim == 1:
    #     Z = Z.reshape(1,-1)
    #     pp = (1 - ((1 - lda) ** (Z @ Y)) * (1 - eps)) * X + (((1 - lda) ** (Z @ Y)) * (1 - eps)) * (1 - X)
    # else:
    #     pp = (1 - ((1 - lda) ** (Z * Y)) * (1 - eps)) * X + (((1 - lda) ** (Z * Y)) * (1 - eps)) * (1 - X)

    if Z.ndim == 1:  #cases (1,)  (2,)  (3,) (4,)
        Z = Z.reshape(-1, 1) 
        pp = (1 - ((1 - lda) ** (Z.T @ Y)) * (1 - eps)) * X + (((1 - lda) ** (Z.T @ Y)) * (1 - eps)) * (1 - X)
    else:  #cases (12,1) (12,3)
        pp = (1 - ((1 - lda) ** (Z @ Y)) * (1 - eps)) * X + (((1 - lda) ** (Z @ Y)) * (1 - eps)) * (1 - X)

    #print(pp)
    
    if isLog == 0:
        p = np.prod(pp)
    else:
        pp = np.log(pp)
        p = np.sum(pp)

    return p
