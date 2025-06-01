if ~exist('results', 'dir')
    mkdir('results');
end

timestamp = datestr(now, 'dd.mm.yyyy_HHMM');
filename = ['results/results_' timestamp '.mat'];

lda = 0.999;
eps = 0.01;

sigmaU = 3;
sigmaV = 3;
sigmaC = 0.1;

phi = 4;
bAlpha = 1;
bBeta = 1;
alpha = 0.1;

[N,T] = size(X);
trainingLength = 12;

Kmax = 1;
wburn = 5;
wsample = 10;
stepNo = 5;
burnIn = 0;

[Zpost, Ypost, Rpost, muCTpost, SigmaCTpost, runTimes, Kmax, wburn, wsample] = ...
    wood_ibp_learning_frontend(X(:,1:trainingLength),V(:,1:trainingLength,:),...
    lda,eps,sigmaU,sigmaV,phi,sigmaC, ...
    alpha,bAlpha,bBeta,Kmax,wburn,wsample,stepNo,burnIn);

save(filename, 'Zpost', 'Ypost', 'Rpost', 'muCTpost', 'SigmaCTpost', 'runTimes', ...
     'Kmax', 'wburn', 'wsample', 'lda', 'eps', 'sigmaU', 'sigmaV', 'sigmaC', ...
     'phi', 'bAlpha', 'bBeta', 'alpha', 'X', 'V', 'stepNo', 'burnIn', 'trainingLength');

fprintf('Results saved to: %s\n', filename);