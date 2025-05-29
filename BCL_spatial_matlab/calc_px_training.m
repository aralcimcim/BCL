function p = calc_px_training(X, Y, Z, lda, eps, varargin)
    args=varargin;
    nargs=length(args);
    if (nargs>0)
        isLog=args{1};
    else
        isLog=0;
    end

    ZY = Z * Y;
    lda_part = 1 - lda;
    eps_part = 1 - eps;
    lda_term = lda_part .^ ZY;
    eps_term = lda_term * eps_part;

    pp = (1 - eps_term) .* X + eps_term .* (1 - X);

    if isLog == 0
        p = prod(pp(:));
    else
        p = sum(log(pp(:)));
    end
end