%% H synarthsh ayth ylopoiei thn epanalhptikh me8odos Jacobi
%% Kaleite me [sol err it] = jacobi(a, x0, b, tol, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% tol = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan
%%
%% yota@uth.gr

function [sol, err, it] = jacobi(a , x0, b, tol, maxiter)

xold = x0;
error = tol + 1;
iter = 0;
d = .....
mat = .....
hold on;
while (iter < maxiter & error > tol)
  xnew = ....
  error = norm(xnew - xold);
  xold = xnew;
  iter = iter + 1;
end

err = error;
it = iter; 
sol = xnew;