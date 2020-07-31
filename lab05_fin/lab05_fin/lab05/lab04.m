%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergasthrio 5
%% Epanalhptikes me8odoi epilyshs grammikwn systhmatwn
%% ONOMATEPONYMO ==
%% userid ==
%% AEM ==

clear all; clc; clf;
%%
%% GRAMMIKES EKSISWSEIS
%%
%% Gia na melethsoyme tis me8odouw, dhmioyrgoume enan pinaka pentadiagwnio, me poly kales idiothtes
%% me ta ekshs stoixeia:
%% sthn kyria diagvnio thn timh 12
%% akribws dipla apo thn kyria diagwnio  thn timh 3
%% se apostash 2 8esewn apo th diagwnio thn timh 1
%% O pinakas 8a exei th morfh
%% 12  3   1   0    0  0  0...
%% 3  12   3   1    0  0  0...
%% 1    3  12  3    1  0  0..
%% 0    1   3  12  3  1  0...
%% klp...

%% ASKHSH 1
%% Grapste mia synarthsh h opoia 8a ylopoiei thn meuodo Jacobi gia th lysh 
%% enos systhmatos grammikwn eksiswsen. 8ymizoume oti gia th Jacobi isxyei::
%% D * x_new = ((L+U)*x_old +b, an exoume na lysoume to A*x=b kai A = D-L-U. 
%% GIa perisosteres plhrofories, diabaste to yliko apo tis sxetikes dialekseis 
%% H synarthsh 8a kaleite me [sol err it] = jacobi(a, x0, b, epsilon, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% eps = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan

% clear all; clc;  display('Epilysh me Jacobi')
% n=100;
% d = 12*ones(n,1);
% dd = 3*ones(n-1,1);
% ddd = 1*ones(n-2,1);
% a = diag(d)+ diag(dd,-1) + diag(dd,1)+diag(ddd,+2) + diag(ddd,-2);
% b = a*ones(n,1);
% x0  = zeros(n,1);
% maxiter = 50;
% epsilon = 0.5e-5;
% [sol err it] = jacobi(a, x0, b, epsilon, maxiter)


%% ASKHSH 2
%% Tropopoihste thn jacobi gia na parete thn gauss_seidel.
%% GIa perisosteres plhrofories, diabaste to yliko apo tis sxetikes dialekseis (13/4)
%% H synarthsh 8a kaleite me [sol err it] = gs(a, x0, b, epsilon, maxiter), opou 


% clear all; clc;  display('Epilysh me Gauss-Seidel')
% n=100;
% d = ..
% dd = ..
% ddd = ..
% a = ....
% b = ..
% x0  = zeros(n,1);
% maxiter = 50;
% epsilon = 0.5e-5;
% [sol err it] = gs(a, x0, b, epsilon, maxiter)


%% ASKHSH 3
%% Tropopoihste thn jacobi gia na parete thn me8odo APOTOMHS KA8ODOY.
%% GIa perisosteres plhrofories, diabaste to yliko apo tis sxetikes
%% diafaneies gia epanalhptikes me8odous sthn lysh systhmatwn grammikwn
%% eksiswsewn
%% H synarthsh 8a kaleite me [sol err it] = ak(a, x0, b, epsilon, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% eps = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan

% clear all; clc; display('Epilysh me Apotomhs Ka8odou')
% n=100;
% d = ..
% dd = ..
% ddd = ..
% a = ....
% b = ..
% x0  = zeros(n,1);
% maxiter = 50;
% epsilon = 0.5e-5;
% [sol err it] = ak(a, x0, b, epsilon, maxiter);

%% ASKHSH 4
%% Tropopoihste thn jacobi gia na parete thn me8odo SYZYGWN KLISEWN(Conjugate Gradient).
%% GIa perisosteres plhrofories, diabaste to yliko apo tis sxetikes
%% diafaneies gia epanalhptikes me8odous sthn lysh systhmatwn grammikwn
%% eksiswsewn.
%% H synarthsh 8a kaleite me [sol err it] = cg(a, x0, b, epsilon, maxiter), opou 
%% a = pinakas, b = deksio melos, 
%% x0 = arxikh proseggish ths lyshs,
%% eps = megisto apodekto sfalma sthn me8odo,  
%% maxiter = megistos ari8mos epanalhpsewn
%% sol = h lysh toy systhmatos
%% err = sfalma ths me8odou
%% iter = plh8os epnalhpsewn pou eginan

% clear all; clc; display('Epilysh me Syzygwn Klisewn')
% n=100;
% d = ..
% dd = ..
% ddd = ..
% a = ....
% b = ..
% x0  = zeros(n,1);
% maxiter = 50;
% epsilon = 0.5e-5;
% [sol err it] = cg(a, x0, b, epsilon, maxiter);


%% ASKHSH GIA MELETH
%% Metreiste to xrono ekteleshs ana epanalhpsh olwn tvn me8odwn 
%% (Jacobi, Gauss-Seidel, Apotomhs Ka8odou, Syzhgwn Klisewn) pou 
%% ylopoihsate parapanw. Xrhsimopoihste n=100:50:1000 kai kante tis
%% grafikes parastaseis opws kaname sto  ergatshrio.

