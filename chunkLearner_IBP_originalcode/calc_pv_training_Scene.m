function [Psit, SigmaCTllhInv, muCTllh] = ...
    calc_pv_training_Scene(x,v,y,Z, sigmaU, sigmaV, phi, sigmaC)
   
   
    [N T] = size(x);
    K = size(Z,2);
    %** Z[N x K] dependency, availLinkNo counts the dependencies between chunks and shapes
    %** note that here the dimensions are not N or K, but the number of all the
    %** dependecies
    availLinkNo = sum(Z(:));
    zc = false(N, K);
    zl = logical(Z);

    SigmaCtllhInv = zeros(availLinkNo, availLinkNo, T); %** EQ 44 Orban_Wood, [2 x 2 x 10]
    wt = zeros(availLinkNo, T, 2);                      %** [2 x 10 x 2]
    Psit = zeros(1, T, 2);                              %** Psi: EQ 54, def on p. 16, Orban_Wood
    for t = 1:T, %** for all trials calculate the inverse covariance mtx (EQ 44), Psit (EQ 54), and zct [N x K] logical
       [SigmaCtllhInv(:,:,t), wt(:,t,:), Psit(:,t,:), zct] = ...
            calc_pv_trial_Scene(x(:,t), v(:,t,:), y(:,t), Z, sigmaU, sigmaV, phi);
        zc = (zc|zct);                                  %[N, K], 0 if never active (x*y*z)
    end
    
    SigmaCTllhInv = sum(SigmaCtllhInv, 3);                                      %** sum for all trial EQ 48 O_W
    SigmaCTpostInv = SigmaCTllhInv + diag(ones(1, availLinkNo)) / (sigmaC ^ 2); %** EQ 50 in Orban_Wood
    
    if sum(SigmaCTllhInv(:))==0 
        muCTllh = SigmaCTllhInv * sum(wt(:,:,1), 2);
        muCTllh(:,:,2) = SigmaCTllhInv * sum(wt(:,:,2), 2);
    else
        muCTllh = inv(SigmaCTllhInv) * sum(wt(:,:,1), 2);
        muCTllh(:,:,2) = inv(SigmaCTllhInv)* sum(wt(:,:,2), 2);
    end
%     muCTllhX = muCTllh(:,:,1);
%     muCTllhY = muCTllh(:,:,2); 
%     
    
%     
%     SigmaCTpost = inv(SigmaCTpostInv);
%     muCTpost = SigmaCTpost * sum(wt(:,:,1), 2);                                  %** EQ 51 O_W
%     muCTpost(:,:,2) = SigmaCTpost * sum(wt(:,:,2), 2);
% 
%     muCTpostX = muCTpost(:,:,1);
%     muCTpostY = muCTpost(:,:,2);
%     
    

end


