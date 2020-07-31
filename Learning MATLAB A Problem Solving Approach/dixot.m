% H synarthsh dixot ylopoiei th me8odo ths dixotomhshs gia thn 
% eyresh ths rizas ths synarthshs f  sto diasthma [xa, xb].
% yota@uth.gr, May 2005


function [xstar, iter] = dixot(f, xa, xb, tol)

fid = fopen('dixot.dat','w');
fprintf(fid,'Iter        xa            xb               xnew           fxnew\n');
fprintf(    'Iter        xa            xb               xnew           fxnew\n');
hold on; plot([xa, xb], [0 0],'ro'); hold off;
iter = 0;
fa = feval(f, xa);
fb = feval(f, xb);
while (abs(xb-xa) > tol)
   xnew = (xa+xb)/2; 
   fnew = feval(f, xnew);
   fprintf(fid,'%d     %12.10f    %12.10f     %12.10f     %12.10f\n',iter+1, xa,xb,xnew,fnew);
   fprintf('%d     %12.10f    %12.10f     %12.10f     %12.10f\n',iter+1, xa,xb,xnew,fnew);
   if sign(fnew) == sign(fb)
      xb = xnew;
      fb = fnew;
   else
      xa = xnew;
      fa = fnew;
   end
   hold on; plot(xnew, 0,'ro'); hold off;
   iter = iter + 1 ; 
   pause
 end

xstar = xnew;
fclose(fid);

