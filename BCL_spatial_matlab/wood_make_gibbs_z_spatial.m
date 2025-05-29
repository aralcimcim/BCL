function [Znew, Ynew, Rnew] = wood_make_gibbs_z_spatial(Y,X,V,Z,R, lda, eps, sigmaU, sigmaV, phi, sigmaC, Balpha, Bbeta, alpha,Kmax, wburn, wsample)

[N, K] = size(Z);
[T] = size(X, 2);
lpv_y = zeros(1, 2);
lpx_y = zeros(1, 2);

for n = 1:N
    Znew = Z;
    lpv_y_new = calc_pv_training(X, V, Y, Znew, sigmaU, sigmaV, phi, sigmaC, 0, 1);
    lpx_y_new = calc_px_training(X(n,:), Y, Znew(n,:), lda, eps, 1);
    
    for k = 1:K
        if (n < N)
            m_mnk = sum(Znew([1:n-1 n+1:N], k)); 
        else
            m_mnk = sum(Znew(1:n-1, k)); 
        end
        
        th_k = m_mnk/N;

        if (m_mnk > 0)
            
            lpv_y(1, 1+Znew(n,k)) = lpv_y_new;
            lpx_y(1, 1+Znew(n,k)) = lpx_y_new;
           
            Znew(n, k) = 1 - Znew(n, k);
            lpv_y(1, 1 + Znew(n,k)) = calc_pv_training(X,V,Y,Znew, sigmaU, sigmaV, phi, sigmaC,0,1); 
            lpx_y(1, 1 + Znew(n,k)) = calc_px_training(X(n,:),Y, Znew(n,:), lda, eps, 1);
            
            lPznk1_XZmnkY = log(th_k) + lpx_y(1, 2) + lpv_y(1, 2); 
            lPznk0_XZmnkY = log(1 - th_k) + lpx_y(1, 1) + lpv_y(1, 1);
            rt = exp(lPznk1_XZmnkY - lPznk0_XZmnkY);
            
            if (rt == Inf) 
                 Pznk_XZmnkY = 1;
            else 
                Pznk_XZmnkY = rt/(rt+1);
            end
            
        else
            Pznk_XZmnkY = 0;
        end
        
        uni = rand(1);
        Znew(n, k) = Pznk_XZmnkY > uni;
        
        lpv_y_new = lpv_y(1, Znew(n,k) + 1);
        lpx_y_new = lpx_y(1, Znew(n,k) + 1);
    
    end
    
    Z = Znew;

    for k = 1:K
        R(1,k) = betarnd(Balpha + sum(Y(k,:)), Bbeta + T - sum(Y(k,:)));
    end

    PKnew_XZY_5 = zeros(1, Kmax + 1);
    Ysample = cell(1, Kmax + 1);
    Rsample = cell(1, Kmax + 1);
    lpy_xv = zeros(1, wsample);
  
    for Knew = 0:Kmax
        ZAct = [Z zeros(N,Knew)]; ZAct(n, K+1:K+Knew)=1;
        RAdd = betarnd(Balpha, Bbeta, 1, Knew);
        RAct = [R RAdd];
        rand_vals = rand(Knew, T);
        YAct = [Y; ((rand_vals < repmat(RAdd', 1, T)) + 0)];
        
        lpv_y_act = zeros(1,2); 
        lpx_y_act = zeros(1,2);
        
        lpv_y_new = calc_pv_training(X, V, YAct, ZAct, sigmaU, sigmaV, phi, sigmaC, 0, 1);
        lpx_y_new = calc_px_training(X(n,:), YAct, ZAct(n,:), lda, eps, 1);
             
        if (Knew > 0)
            for wi = 1:wburn+wsample 
                for t = 1:T          
                    for k = 1:Knew
                        lpv_y_act(1, 1 + YAct(K+k, t)) =  lpv_y_new;
                        lpx_y_act(1, 1 + YAct(K+k, t)) =  lpx_y_new;

                        YAct(K+k, t) = 1 - YAct(K+k, t);
                        lpv_y_act(1, 1 + YAct(K+k, t)) = calc_pv_training(X,V,YAct,ZAct, sigmaU, sigmaV, phi, sigmaC,0,1);
                        lpx_y_act(1, 1 + YAct(K+k, t)) = calc_px_training(X(n,:), YAct, ZAct(n,:), lda, eps, 1);
                        
                        p = RAct(1, K + k);
                        lPYk1_ZXYmk = log(p) + lpx_y_act(1,2) + lpv_y_act(1,2);
                        lPYk0_ZXYmk = log(1-p) + lpx_y_act(1,1) + lpv_y_act(1,1);
                        rt = exp(lPYk1_ZXYmk - lPYk0_ZXYmk );
                        
                        if (rt == Inf) 
                            PYk1_ZXYmk = 1;
                        else 
                            PYk1_ZXYmk = rt / (rt+1); 
                        end
                        
                        uni = rand(1,1);
                        YAct(K+k,t) = PYk1_ZXYmk > uni;
                        lpv_y_new = lpv_y_act(1, YAct(K + k, t) + 1);
                        lpx_y_new = lpx_y_act(1, YAct(K + k, t) + 1);
                    end
                end
                 
                for k = 1:Knew
                    RAct(1, K + k) = betarnd(Balpha + sum(YAct(K + k, :)), Bbeta + T - sum(YAct(K + k, :)));  
                end

                if (wi>wburn) 
                    lpy_xv(wi-wburn) = lpx_y_new + lpv_y_new;
                end
            end        
        else
            lpx_y_new = calc_px_training(X(n,:), YAct, ZAct(n,:), lda, eps, 1);
            lpv_y_new = calc_pv_training(X,V,YAct,ZAct, sigmaU, sigmaV, phi, sigmaC,0,1);
            lpy_xv = lpv_y_new + lpx_y_new ;                         
        end
        if Knew == 0 
            py_xzKnew_5 = lpy_xv; 
        else
            py_xzKnew_5 = log(wsample) - log(1) + max(lpy_xv) - log(sum(1./exp(lpy_xv - max(lpy_xv))));
        end
        PKnew_XZY_5(Knew + 1) = (py_xzKnew_5 + log(poisspdf(Knew, alpha/N)));
        Ysample{Knew + 1} = YAct;
        Rsample{Knew + 1} = RAct;
    end

    lpdf_5 = PKnew_XZY_5 - max(PKnew_XZY_5);
    pdf_5 = exp(lpdf_5)/sum(exp(lpdf_5));
    bar = rand(1);
    j = 1; while (sum(pdf_5(1:j))<bar), j = j+1; end
    Knew = j - 1;
    
    Znew = [Z zeros(N, Knew)]; 
    Znew(n, K+1:K+Knew) = 1;

    Z = Znew;
    Y = Ysample{Knew + 1}; 
    R = Rsample{Knew + 1};
        
    nodes2keep = find(sum(Z,1));
    if(~isempty(nodes2keep))
        Z = Z(:, nodes2keep);
        Y = Y(nodes2keep, :);
        R = R(1,nodes2keep, :);
        K = size(Z, 2);
    elseif isempty(Z)
        Z = zeros(N,1);
        Y = zeros(1,T);
        R = 0;
        K = size(Z,2);  
    else    
        Z = zeros(N,1);
        Y = zeros(1,T);
        R = 0;
        K = size(Z,2);
    end
  
end

Znew = Z;
Ynew = Y;
Rnew = R;