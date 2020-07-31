%% H synarthsh ayth ylopoiei thn epanalhptikh me8odo Apotomhs Ka8odou
%% (Steepest Descent) me arxikh timh panta to 0.
%% Kaleite me [sol err it] = ak(a, b, tol, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% tol = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan
%%
%% yota@uth.gr

function [sol, err, it] = ak(a, x0, b, tol, maxiter)

error = tol + 1;
k = 0;
xk = x0;
rk = b;
clf; 
title('Steepest Descend iterations');
xlabel('iterations');
ylabel('log_{10} of error , ||.||_2');
hold on;
while (k < maxiter & error > tol)
    amrk = a*rk;
    alphak = (rk' * rk) / (rk' * amrk);
    xkp1 = xk + alphak*rk;
    rkp1 = rk - alphak*amrk;
    error = norm(rkp1,2);
    fprintf('Sthn %d epanalhpsh to diadoxiko sfalma %12.8f . \n',...
      k,error );
    plot([k],[log10(error)], 'm*');
    k = k + 1;
    rk = rkp1;
    xk = xkp1;
end

err = error;
it = min(k, maxiter);
sol = xk;