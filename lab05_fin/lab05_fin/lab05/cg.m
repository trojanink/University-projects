%% H synarthsh ayth ylopoiei thn epanalhptikh me8odo syzhgwn
%% klisewn(Conjugate-Gradient) me arxikh timh panta to 0.
%% Kaleite me [sol err it] = cg(a, b, tol, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% tol = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan
%%
%% yota@uth.gr

function [sol, err, it] = cg(a, x0, b, tol, maxiter)

error = tol + 1;
k = 0;
xk = x0;
rk = b;
pkp1 = rk;
clf; 
title('Conjugate Gradient iterations');
xlabel('iterations');
ylabel('log_{10} of error , ||.||_2');
hold on;
while (k < maxiter & error > tol)
    ampkp1 = a*pkp1;
    alphakp1 = (rk' * rk) / (pkp1' * ampkp1);
    xkp1 = xk + alphakp1*pkp1;
    rkp1 = rk - alphakp1*ampkp1;
    error = norm(rkp1,2);
    bk = (rkp1' * rkp1) / (rk' * rk); 
    fprintf('Sthn %d epanalhpsh to diadoxiko sfalma %12.8f . \n',...
      k,error );
    plot([k],[log10(error)], 'b*');
    k = k + 1;
    pkp1 = rkp1 + bk*pkp1;
    rk = rkp1;
    xk = xkp1;
end

err = error;
it = min(k, maxiter);
sol = xk;