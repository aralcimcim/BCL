function [p, muCTpost, SigmaCTpostInv, SigmaCTpost, zc, Psit] = ...
    calc_pv_training(x,v,y,Z, sigmaU, sigmaV, phi, sigmaC, varargin)
    args=varargin;
    nargs=length(args);
    if (nargs>0)
        dims=args{1};
    else
        dims=0;
    end
    if (nargs>1)
        logOutput=args{2};
    else
        logOutput=0;
    end

    [N, T] = size(x);
    K = size(Z,2);
    availLinkNo = sum(Z(:));
    zc = false(N, K);
    zl = logical(Z);

    SigmaCtllhInv = zeros(availLinkNo, availLinkNo, T); 
    wt = zeros(availLinkNo, T, 2);                      
    Psit = zeros(1, T, 2);                              

    for t = 1:T
       [SigmaCtllhInv(:,:,t), wt(:,t,:), Psit(:,t,:), zct] = ...
            calc_pv_trial_mex(x(:,t), v(:,t,:), y(:,t), Z, sigmaU, sigmaV, phi);
        zc = (zc|zct);                                 
    end
    
    SigmaCTllhInv = sum(SigmaCtllhInv, 3);             
    SigmaCTpostInv = SigmaCTllhInv + diag(ones(1, availLinkNo)) / (sigmaC ^ 2); 
    SigmaCTpost = SigmaCTpostInv \ eye(size(SigmaCTpostInv));
    
    muCTpost = zeros(availLinkNo, 1, 2);

    muCTpost(:,:,1) = SigmaCTpost * sum(wt(:,:,1), 2);
    muCTpost(:,:,2) = SigmaCTpost * sum(wt(:,:,2), 2);

    muCTpostX = muCTpost(:,:,1);
    muCTpostY = muCTpost(:,:,2);

    zc_sum = sum(zc(:));
    
    if zc_sum > 0
        zc_indices = zc(zl);
        SigmaCTpostInv_sub = SigmaCTpostInv(zc_indices, zc_indices);
        nfx = mvnormpdfln(muCTpostX(zc_indices), zeros(zc_sum, 1), 'inv', SigmaCTpostInv_sub);
        nfy = mvnormpdfln(muCTpostY(zc_indices), zeros(zc_sum, 1), 'inv', SigmaCTpostInv_sub);
    else
        nfx = 0;
        nfy = 0;
    end

    common_term = (2 * pi) ^ (-zc_sum / 2) * sigmaC ^ (-zc_sum);

    if logOutput == 0
        p1 = prod(Psit(:,:,1)) * common_term / exp(nfx);
        p2 = prod(Psit(:,:,2)) * common_term / exp(nfy);
        if dims == 0
            p = p1 * p2;
        elseif dims == 1
            p = p1;
        elseif dims == 2
            p = p2;
        else
            error('calc_pv_training: wrong setting for optional argument dims');
        end
    else
        log_common_term = log(common_term);
        lp1 = sum(log(Psit(:,:,1))) + log_common_term - nfx;
        lp2 = sum(log(Psit(:,:,2))) + log_common_term - nfy;

        if (dims==0)
            p = lp1 + lp2;
        elseif (dims == 1)
            p = lp1;
        elseif (dims == 2)
            p = lp2;
        else
            error('calc_pv_training: wrong setting for optional argument dims');
        end
    end
end