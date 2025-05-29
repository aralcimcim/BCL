import numpy as np
from scipy.stats import beta
from wood_make_gibbs_y_spatial import wood_make_gibbs_y_spatial
from woods_make_gibbs_z_spatial import wood_make_gibbs_z_spatial
from calc_pv_training import calc_pv_training

np.random.seed(0)

def wood_ibp_learning_frontend(X, V, lda, eps, sigmaU, sigmaV, 
                               phi, sigmaC, alpha, bAlpha, bBeta, 
                               Kmax, wburn, wsample, stepNo, burnIn):
    

    initLatentNo = 1
    
    # 12 x 144
    N, T = X.shape

    # 12 x 1
    Znew = np.zeros((N, initLatentNo))

    # 1 x 1
    Rnew = beta.rvs(bAlpha, bBeta, size=(1, initLatentNo))
    # In MATLAB, betarnd gives this value, in Python it is 0.4491 both in scipy and numpy
    #Rnew = np.array([[0.683925723723900]])

    # 144 x 12
    Ynew = np.array((np.random.rand(initLatentNo, T) < np.tile(Rnew.T, (1, T))), dtype=int)
    #Ynew = np.array([[1,1,1]])
    #Ynew = np.array([[1,1,1,1,0,0]])
    
    Zpost = np.empty((1, stepNo - burnIn), dtype=object)
    Ypost = np.empty((1, stepNo - burnIn), dtype=object)
    Rpost = np.empty((1, stepNo - burnIn), dtype=object)
    muCTpost = np.empty((1, stepNo - burnIn), dtype=object)
    sigmaCTpost = np.empty((1, stepNo - burnIn), dtype=object)

    for i in range(1, stepNo+1):
        print("#" * 50)
        print(f"iteration: {i-1}")
        print(f"Znew = \n{Znew}\n")
        print(f"Rnew = \n{Rnew}")

        Ynew = wood_make_gibbs_y_spatial(Ynew, X, V, Znew, Rnew, lda, eps, sigmaU, sigmaV, phi, sigmaC)
        
        Znew, Ynew, Rnew = wood_make_gibbs_z_spatial(Ynew, X, V, Znew, Rnew, lda, eps, sigmaU, sigmaV, phi, sigmaC, bAlpha, bBeta, alpha, 
                                                     Kmax, wburn, wsample)

        pi, muCTposti, SigmaCTpostInvi, sigmaCTposti = calc_pv_training(X, V, Ynew, Znew, sigmaU, sigmaV, phi, sigmaC, 0, 1)

        if i > burnIn:
            Zpost[0, i - burnIn - 1] = Znew
            Ypost[0, i - burnIn - 1] = Ynew
            Rpost[0, i - burnIn - 1] = Rnew
            muCTpost[0, i - burnIn - 1] = muCTposti
            sigmaCTpost[0, i - burnIn - 1] = sigmaCTposti

    return Zpost, Ypost, Rpost, muCTpost, sigmaCTpost, Kmax, wburn, wsample
