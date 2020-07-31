%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergasthrio 7
%% ARI8MHTIKH EPILYSH MH GRAMMIKWN EKSISWSEWN.
%% ONOMATEPONYMO = 
%% userid = 
%% AEM =

clear all; clc;

%% Ari8mhtikh Epilysh Mh Grammikwn Eksiswsewn.

%% Symbolic functions tou Matlab

%% Polywnyma...
%% Gia to polyvnymo p(x)= a_n x^n + a_{n-1}x^(n-1) + ... a_1x + a_0, mporoume na 
%% xrhsimopoihsoume th roots([a_n  a_{n-1}  ...     a_1  a_0]) gia na broume tis rizes tou

% disp('klish ths roots')
% clf; clc; clear all
% syn = [5 2 0 3 -4];
% rizes = roots(syn)

%% Gia alles synarthseis pou gnwrizoume thn analytikh touw ekfrash, xrhsimopoioume th
%% fzero('ekfrash')
% disp('inline + fzero. Pateiste Enter gia na synexisete')
% pause; 
% clf; clc; clear all
% 
% ekf= '30*sin(x)-5*exp(x^2)';
% f = inline(ekf);
% ezplot(ekf,[-2 3]); grid
% x0 = input('dwse arikh timh ');
% [sol fsol] = fzero(ekf, x0)

%% Me8odos ths Dixotomhshs
%% Ylopoihste thn me8odo ths dixotomhshs, se mia synarthsh pou na kaleitai 
%% [xstar, iter] = dixot(f, xa, xb, tol), opou f to onoma ths synarthshs pou 
%% psaxnome na ypologisoume th riza sto diasthma [xa, xb], tol fragma gia to
%% anekto sfalma, xstar h ypologismenh riza kai iter to plh8os twn epanalhpsewn
%% pou pragmatopoih8hkan.

% disp('Klish ths dixot. Pateiste Enter gia na synexisete')
% pause; 
% clf; clc; clear all
% 
% f = inline('sin(x)');
% xa = -0.5; xb = 1;
% tol = 1.e-10;
% ezplot(f, [xa, xb]); grid on
% [xstar, iter] = dixot(f, xa, xb, tol);
% fprintf('DIXOTOMHSH: H riza %f vre8hke se %d epanalhpseis.\n',xstar, iter);
% 
% 
% disp('Klish ths dixot. Pateiste Enter gia na synexisete')
% pause; 
% clf; clc; clear all
% myfun = 'f1';
% xa = 0; xb = 1;
% tol = 1.e-10;
% ezplot('f1', [xa, xb]); grid on
% [xstar, iter] = dixot(myfun, xa, xb, tol);
% fprintf('DIXOTOMHSH: H riza %f vre8hke se %d epanalhpseis.\n',xstar, iter);

%% ASKHSH 1 -- Me8odos Newton
%% Ylopoihste thn me8odo tou Newton, se mia synarthsh pou na kaleitai 
%% [xstar, iter] = newton(ekf, x0, tol, maxiter), opou ekf h ekfrash ths synarthshs 
%% ths opoias psaxnome na ypologisoume th riza me axrikh proseggish x0, tol fragma gia to 
%% anekto sfalma, maxiter to megisto plh8os epanalhpsewn, 
%% xstar h ypologismenh riza kai iter to plh8os twn epanalhpsewn
%% pou pragmatopoih8hkan.

% disp('Klish ths newton. Pateiste Enter gia na synexisete')
% pause; 
% clf; clc; clear all
% x = sym('x');
% ekf = x^3 + 2*x^2 -3*x + 0.5;
% x0 = 1;
% tol = 1.e-6;
% maxiter = 20;
% ezplot(ekf, [0 1]); grid on
% 
% [xstar, iter] = newton(ekf, x0, tol, maxiter);%evresh ths dejias rizas
% fprintf('NEWTON: H riza %f vre8hke se %d epanalhpseis.\n',xstar, iter);
% 
% disp('Klish ths newton. Pateiste Enter gia na synexisete');pause;
% x0 = 0;
% [xstar, iter] = newton(ekf, x0, tol, maxiter);%evresh ths aristerhs rizas
% fprintf('NEWTON: H riza %f vre8hke se %d epanalhpseis.\n',xstar, iter);
% 
% disp('Klish ths newton. Pateiste Enter gia na synexisete');pause;
% % Paradeigmata eksiswsewn pou h Newton den doulevei.
% ekf2 =2*x*(1-x^2+x)*log(x)-x^2+1;
% ezplot(ekf2, [-1 2]); grid on
% [xstar, iter] = newton(ekf2, 0.56, tol, 100);
% disp('Klish ths newton. Pateiste Enter gia na synexisete');pause
% ekf3 = x^5-9*x^4-x^3+17*x^2-8*x-8
% ezplot(ekf3, [-1 2]); grid on
% [xstar, iter] = newton(ekf3, 1, tol, 100);

%% Me8odos Temnousas
%% ASKHSH 2
%% Tropopoihste thn me8odo Newton prokeimenou na parete thn me8odo ths Temnousas
% disp('Klish ths temnousa. Pateiste Enter gia na synexisete')
% pause; 
% clf; clc; clear all
% x = sym('x'); 
% ekf = x^3 + 2*x^2 -3*x + 0.5;
% tol = 1.e-6;
% maxiter = 20;
% ezplot(ekf, [-2 1]); grid on
% x0 = -1; x1 = 0;
% [xstar, iter] = temnousa(x^3 + 2*x^2 -3*x + 0.5, x0, x1, tol, maxiter);
% fprintf('TEMNOUSA: H riza %f vre8hke se %d epanalhpseis.\n',xstar, iter);


%% ASKHSEIS GIA MELETH : 
%% YLOPOIHSTE THN ME8ODO THS TEMNOYSAS GIA TH SYNARTHSH f(x) = x^3-2*x^2+5
%% H SYNARTHSH 8A KALEITAI [sol, iter] = fun1(x0,x1,maxiter,tol), OPOY
%% EPISTERFEI THN RIZA STO sol, PLH8OS TVN EPANALHPSEWN POY PRAGMATOPOIHSE STO iter
%% ENW TO x0, x1 EINAI OI DYO ARXIKES TIMES, maxiter TO MEGISTO PLH8OS EPANALHPSEWN POY EPITREPETAI,
%% KAI tol H ANOXH SE SFALMATA.
%% KANTE GRAFIKH ANAPARASTASH TWN PROSEGGISEWN SE KA8E BHMA MAZI ME THN SYANRTHSH KAI
%% DOKIMASTE NA TREKSETE ME TA PARAKATW DEDOMENA. TI PARATHREITE?

% disp('ASKHSH'); pause;
% [sol1, iter1] = fun1(1.2, 1.25, 20, .1e-6)
% [sol2, iter2] = fun1(-6,-5, 20, .1e-6)

%% YLOPOIHSTE THN ME8ODO THS DIXOTOMHSHS GIA TH SYNARTHSH f(x) = x^5-2*sin(x) 
%% H SYNARTHSH 8A KALEITAI [sol, iter] = fun2(x0,x1,maxiter,tol), OPOY
%% EPISTERFEI THN RIZA STO sol, PLH8OS TVN EPANALHPSEWN POY PRAGMATOPOIHSE STO iter
%% ENW TO x0, x1 EINAI TA AKRA TOY ARXIKOY DIASTHMATOS, maxiter TO MEGISTO PLH8OS EPANALHPSEWN POY EPITREPETAI,
%% KAI tol H ANOXH SE SFALMATA.
%% KANTE GRAFIKH ANAPARASTASH TWN PROSEGGISEWN SE KA8E BHMA MAZI ME THN SYANRTHSH KAI
%% DOKIMASTE NA TREKSETE ME TA PARAKATW DEDOMENA. TI PARATHREITE?

% disp('ASKHSH'); pause;
% [sol1, iter1] = fun2(0.5 , 3, 20, .1e-6)
% [sol2, iter2] = fun2(-1, 0.5, 20, .1e-6)
% [sol3, iter3] = fun2(-2, -0.5, 20, .1e-6)
% [sol4, iter4] = fun2(-2, 3, 20, .1e-6)

%% YLOPOIHSTE THN ME8ODO TOY NEWTON GIA TH SYNARTHSH f(x) = (x^3-3*x^2+2*x)/50 
%% H SYNARTHSH 8A KALEITAI [sol, iter] = fun3(x0,maxiter,tol), OPOY
%% EPISTERFEI THN RIZA STO sol, PLH8OS TVN EPANALHPSEWN POY PRAGMATOPOIHSE STO iter
%% ENW TO x0 EINAI HA RXIKH TIMH, maxiter TO MEGISTO PLH8OS EPANALHPSEWN POY EPITREPETAI,
%% KAI tol H ANOXH SE SFALMATA.
%% KANTE GRAFIKH ANAPARASTASH TWN PROSEGGISEWN SE KA8E BHMA MAZI ME THN SYANRTHSH KAI
%% DOKIMASTE NA TREKSETE ME TA PARAKATW DEDOMENA. TI PARATHREITE?

% disp('ASKHSH'); pause;
% [sol1, iter1] = fun3(4, 20, .1e-6)
% [sol2, iter2] = fun3(-1, 20, .1e-6)
% [sol3, iter3] = fun3(0.5, 20, .1e-6)
% [sol4, iter4] = fun3(1.5, 20, .1e-6)