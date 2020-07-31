%% H synarthsh newton ylopoiei th me8odo tou Newton gia thn 
%% eyresh ths rizas ths synarthshs f(x) = x^2*sin(x) me arxikh timh to x0.
%%  x0 = arxikh timh
%% tol = anoxh sto sfalma
%% maxiter = megisto plh8os synarthsewn
%% xstar = proseggish thw rizas
%% fxstar = timh ths synarthshs sth riza
%% iter = plh8os epanalhpsewn poy ektelesthkan
%%


function [xstar, fxstar,  iter] = newton(x0, tol, maxiter)

f = inline('x*x*sin(x)'); %% h ekfrash metatrepetai se synarthsh
df =  inline('2*x*sin(x) + x^2*cos(x)');  %% ypologismos ths paragwgoy

xold = x0;
fxold = f(xold);
dfxold = df(xold);
iter = 0;

if  abs(dfxold) <= eps
   fprintf('H paragwgos mhdenizetai sto %f kai h me8odos Newton den mporei na synexisei.\n',xold);
   xstar = xold;
   fxstar = f(xstar);
   return;
end

xnew = xold - fxold/dfxold;
fxnew = f(xnew);
iter = 1;

while (iter < maxiter) & (abs(xold-xnew) > tol)  & (abs(fxnew) >tol)
   xold = xnew;
   fxold = fxnew; 
   dfxold = df(xold);
   if abs(dfxold) > eps
      xnew = xold - fxold/dfxold;
      fxnew = f(xnew);
   else
      fprintf('H paragwgos mhdenizetai sto %f kai h me8odos Newton den mporei na synexisei.\n',xold);
      xstar = xnew;
      fxstar = fxnew;
      return;
   end
   iter = iter + 1 ;
 end

xstar = xnew;
fxstar = f(xstar);
end


