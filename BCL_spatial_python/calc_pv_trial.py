import numpy as np

def calc_pv_trial(x, v, y, Z, sigmaU, sigmaV, phi):
    N, K = Z.shape
    ZAct = Z * np.tile(y.flatten(), (N, 1))

    phi = phi * ZAct
    zc = np.logical_and(phi, x)

    xAct = np.where(x == 1)[0] + 1
    xActNo = len(xAct)
    A = phi / (1 + np.tile(np.sum(phi, axis=1, keepdims=True), (1,K)))

    sSq = (sigmaV ** 2 / (1 + np.sum(phi, axis=1)))
    ptAct  = np.where(np.sum(ZAct * (np.tile(x.flatten(), (K,1)).T), axis=0))[0] + 1 # to match matlab indexing
    ptNo = len(ptAct)

    SigmaInv = np.zeros((ptNo, ptNo, len(xAct)))
    omegaBU = np.zeros((N, N))
    diag_values = np.diag(sSq[xAct-1])
    omega = 1 / sigmaV**4 * diag_values

    availLinks = []
    availLinksRow = []
    availLinksCol = []

    if np.sum(Z) != 0:
        availLinksRow, availLinksCol = np.where(Z) # col, row = 1, 0 in matlab 2, 1
        availLinks = np.column_stack((availLinksRow+1, availLinksCol+1)) # to match matlab indexing of Z
        availLinkNo = availLinks.shape[0]
        SigmaCtllhInv = np.zeros((availLinkNo, availLinkNo))
        wt = np.zeros((availLinkNo, 2))
    else:
        availLinkNo = 0
        SigmaCtllhInv = 0
        wt = 0

    if ptNo > 0:
        for xi in range(1, len(xAct) + 1):
            row_indices = xAct[xi-1]-1
            col_indices = ptAct-1
            array = A[np.ix_([row_indices], col_indices)]
            array_T = array.T
            SigmaInv[:, :, xi-1] = (array * array_T) / sSq[xAct[xi-1]-1]
    
        SigmaCVInv = np.sum(SigmaInv, axis=2)
        SigmaCInv = SigmaCVInv + 1 / (sigmaU**2) * np.eye(ptNo)
        SigmaC = np.linalg.inv(SigmaCInv)

        # ptAct = ptAct[0]
        # A_submatrix = A[xAct - 1, ptAct - 1]
        # A_submatrix = A_submatrix.reshape(-1, 1)
        # omega -= (1 / sigmaV**4) * (A_submatrix @ (SigmaC @ A_submatrix.T))

        if SigmaC.size == 1:
            ptAct = ptAct[0]
            A_submatrix = A[xAct - 1, ptAct - 1]
            A_submatrix = A_submatrix.reshape(-1, 1)
            omega = omega - (1 / sigmaV**4) * (A_submatrix @ (SigmaC @ A_submatrix.T))
        else:
            A_submatrix = A[xAct - 1, :][:, ptAct - 1]
            omega = omega - 1 / sigmaV**4 * (A_submatrix @ SigmaC @ A_submatrix.T)

        omegaBU = np.zeros((N,N))
        omegaBU[np.ix_(xAct-1, xAct-1)] = omega

        for i in range(1, availLinkNo+1):
            for j in range(1, availLinkNo+1):
                if x[availLinks[i-1, 0]-1] == 1 and x[availLinks[j-1, 0]-1] == 1:
                    SigmaCtllhInv[i-1, j-1] = (omegaBU[availLinks[i-1, 0]-1, availLinks[j-1, 0]-1] * 
                                               phi[availLinks[i-1, 0]-1, availLinks[i-1, 1]-1] * 
                                               phi[availLinks[j-1, 0]-1, availLinks[j-1, 1]-1])

            vnan = np.nan_to_num(v)
            #v array shape in the beginning is (12,144,2) due to matlab slicing, using python's (12,2)
            first_term = phi[availLinks[i-1,0]-1, availLinks[i-1,1]-1]
            second_term = omegaBU[availLinks[i-1,0]-1,:]
            result1 = first_term * second_term
            result1 = result1.reshape(1,-1)

            third_term = np.sum(phi, axis=1) + 1
            fourth_term_wt1 = vnan[:,0]
            fourth_term_wt2 = vnan[:,1]

            result2_wt1 = third_term * fourth_term_wt1
            result2_wt2 = third_term * fourth_term_wt2
            final_result_wt1 = np.dot(result1, result2_wt1)
            final_result_wt2 = np.dot(result1, result2_wt2)

            wt[i-1, 0] = final_result_wt1
            wt[i-1, 1] = final_result_wt2

    else:
        SigmaC = 1

    if type(SigmaC) == int:
        det_SigmaC = 1
    else:
        det_SigmaC = np.linalg.det(SigmaC)

    Psit = np.zeros((1, 1, 2))
    vp = (1 + np.sum(phi, axis=1)) * v[:, 0]
    vpnan = np.nan_to_num(vp)
    Psit[:,:,0] = (2*np.pi)**(-xActNo/2) * sigmaU**(-ptNo) * 1/(np.sqrt(np.prod(sSq[xAct-1]))) * det_SigmaC**(0.5) * np.exp(-0.5 * np.dot(vpnan.T, np.dot(omegaBU, vpnan)))
    
    vp = (1 + np.sum(phi, axis=1)) * v[:, 1]
    vpnan = np.nan_to_num(vp)
    Psit[:,:,1] = (2*np.pi)**(-xActNo/2) * sigmaU**(-ptNo) * 1/(np.sqrt(np.prod(sSq[xAct-1]))) * det_SigmaC**(0.5) * np.exp(-0.5 * np.dot(vpnan.T, np.dot(omegaBU, vpnan)))
    
    return SigmaCtllhInv, wt, Psit, zc