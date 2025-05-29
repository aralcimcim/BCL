function Ynew = wood_make_gibbs_y_spatial(Y,X,V,Z,R, lda, eps, sigmaU, sigmaV, phi, sigmaC)
[K, T] = size(Y);
Ynew = Y; 
lpv_y = zeros(1,2);
lpx_y = zeros(1,2);

lpv_y_new = calc_pv_training(X, V, Ynew, Z, sigmaU, sigmaV, phi, sigmaC, 0, 1);
lpx_y_new = calc_px_training(X(:,1), Ynew(:,1), Z, lda, eps, 1);

for t = 1:T
    for k = 1:K
        y_curr = Ynew(k, t);
        lpv_y(1, 1 + y_curr) = lpv_y_new;
        lpx_y(1, 1 + y_curr) = lpx_y_new;

        Ynew(k,t) = 1 - y_curr;

        lpv_y(1, 1 + Ynew(k,t)) = calc_pv_training(X, V, Ynew, Z, sigmaU, sigmaV, phi, sigmaC,0,1);
        lpx_y(1, 1 + Ynew(k,t)) = calc_px_training(X(:,t), Ynew(:,t), Z, lda, eps, 1);

        p = R(1,k);
        lPYk1_ZXYmk = log(p) + lpx_y(1, 2) + lpv_y(1, 2);
        lPYk0_ZXYmk = log(1 - p) + lpx_y(1, 1) + lpv_y(1, 1);

        rt = exp(lPYk1_ZXYmk - lPYk0_ZXYmk);

        if rt == Inf
            PYk_ZXYmk = 1;
        else
            PYk_ZXYmk = rt / (rt + 1); 
        end
       
        Ynew(k,t) = (PYk_ZXYmk > rand());
        lpv_y_new = lpv_y(1, Ynew(k, t) + 1);
        lpx_y_new = lpx_y(1, Ynew(k, t) + 1);
    end
end