import scipy.io
import torch
from wood_ibp_learning_frontend import wood_ibp_learning_frontend

# for matlab code to run in vscode pip install https://www.mathworks.com/help/matlab/matlab_external/install-the-matlab-engine-for-python.html
data = scipy.io.loadmat("/home/ari/Desktop/BCL/BCL_spatial/input_2001_Exp1.mat")

X = data["X"]
V = data["V"]
X_test = data["Xtest"]
V_test = data["Vtest"]

N, T = X.shape

#params
lda = 0.999
eps = 0.01
sigmaU = 3
sigmaV = 3
sigmaC = 0.1
phi = 4
bAlpha = 1.0
bBeta = 1.0
alpha = 0.1
trainingLength = 12
Kmax = 1
wburn = 5
wsample = 10
stepNo = 10
burnIn = 0

Zpost, Ypost, Rpost, muCTpost, sigmaCTpost, Kmax, wburn, wsample = wood_ibp_learning_frontend(X[:, :trainingLength], V[:, :trainingLength, :], 
                                                                                                lda, eps, sigmaU, sigmaV, phi, sigmaC,alpha, 
                                                                                                bAlpha, bBeta, Kmax, wburn, wsample, stepNo, burnIn)
