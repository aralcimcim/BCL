function [SigmaCtllhInv, wt, Psit, zc] = calc_pv_trial(x, v, y, Z, sigmaU, sigmaV, phi)
    [N, ~] = size(Z);
    ZAct = Z .* y';
    phi = phi .* ZAct;                           
    zc = logical(phi .* x);

    xAct = find(x);                              
    xActNo = length(xAct);                      
    phiSum = sum(phi, 2);
    A = phi ./ (1 + phiSum);
    sSq = sigmaV^2 ./ (1 + phiSum);

    ptAct = find(sum(ZAct .* x, 1));
    ptNo = length(ptAct); 
    omegaBU = zeros(N);                         
    omega = 1 / sigmaV^4 * diag(sSq(xAct));

    if ptNo > 0
        SigmaInv = zeros(ptNo, ptNo, length(xAct));

        for xi = 1:length(xAct)
            A_xi = A(xAct(xi), ptAct);
            SigmaInv(:, :, xi) = (A_xi' * A_xi) / sSq(xAct(xi));
        end
    
        SigmaCVInv = sum(SigmaInv, 3);
        SigmaCInv = SigmaCVInv + (1 / (sigmaU^2)) * eye(ptNo);
        SigmaC = SigmaCInv \ eye(ptNo);
        omega = omega - (1 / sigmaV^4) * (A(xAct, ptAct) * (SigmaC * A(xAct, ptAct)'));
        omegaBU(xAct, xAct) = omega;
    
        if any(Z(:))
            [availLinksRow, availLinksCol] = find(Z);
            availLinks = [availLinksRow, availLinksCol];
            availLinkNo = size(availLinks, 1);

            wt = zeros(availLinkNo, 1, 2);
            linkIndices = availLinks(:, 1);
            phiTerms = phi(sub2ind(size(phi), linkIndices, availLinks(:, 2)));
            omegaTerms = omegaBU(linkIndices, :);

            vnan = v;
            vnan(isnan(vnan)) = 0;
    
            activeLinks = (x(linkIndices) == 1);
            activeMatrix = activeLinks' & activeLinks;
            phiProductMatrix = phiTerms * phiTerms';
            omegaProductMatrix = omegaTerms * omegaTerms';
            
            SigmaCtllhInv = zeros(availLinkNo, availLinkNo);
            SigmaCtllhInv(activeMatrix) = omegaProductMatrix(activeMatrix) .* phiProductMatrix(activeMatrix);
    
            phiSum = sum(phi, 2);
            wt(:, 1, 1) = phiTerms .* (omegaTerms * ((1 + phiSum) .* vnan(:, :, 1)));
            wt(:, 1, 2) = phiTerms .* (omegaTerms * ((1 + phiSum) .* vnan(:, :, 2)));
        else
            SigmaC = 1;
            SigmaCtllhInv = 0;
            wt = 0;
        end
    else
        SigmaC = 1;
        SigmaCtllhInv = 0;
        wt = 0;
    end

    detSigmaC = det(SigmaC);
    invSqrtProdSSq = 1 / sqrt(prod(sSq(xAct)));
    Psit = zeros(1, 1, 2);

    for coord = 1:2
        vp = ((1 + phiSum) .* v(:, :, coord));
        vpnan = vp;
        vpnan(isnan(vpnan)) = 0;
        Psit(:,:,coord) = (2*pi)^(-xActNo/2) * sigmaU^(-ptNo) * ...
                          invSqrtProdSSq * sqrt(detSigmaC) * ...
                          exp(-0.5 * (vpnan' * (omegaBU * vpnan)));
    end
end