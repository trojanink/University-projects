%% H synarthsh myapprox xrhsimopoiei MET
%% gia na ypologisei proseggistikes synarthseis se dedomena shmeia 
%% ka8ws epishs kai ta sfalmata toys
%% H synarthsh kaleitai ws [x y error] = myapprox(axones, method) opou 
%% x, y  = oi syntetagm;enew twn shmeiwn pou 8a epileksei o xrhsths me th ginput
%% error = dianysma 3 stoixeiwn me ta sfalmata
%%         error(1) = to sfalma apo grammikh proseggish
%%         error(2) = to sfalma apo tetragwnikh proseggish
%%         error(3) = to sfalma apo thn 3 me8odo poy epilei o xrhsths me bash ta parakatw
%% axones = dianysma grammh th morfhs [ xmin xmax ymin ymax ] pou kauorizei to grafiko para8yro  
%% method = flag poy boh8a na epileksoume me8odo proseggishs
%%           1 = proseggish me synarthsh ths morfhs  f(x) = a * exp(b *x)
%%           2 = proseggish me synarthsh ths morfhs f(x) = a*x /(b+x)
%%           k = polywnymikh proseggish ba8mou k, poy dinei o xrhsths kata thn ektelesh toy script
%% Gia logous elegxou me oles tis synarthseis proseggishs, xrhsimopoihste ta x,y pou
%% didontai parakatv. Wstoso h synarthsh 8a prepei na trexei me thn ginput.
%%

function [x,y, error] = myapprox(axones, method)

clf; axis(axones); grid;

[x , y ] = ginput;
% x = [1:1:10];
% y = [1 2 2.5 2.3 2.7 3.1 3.15 3.16 3.25 3.5 ]; 

xplot = linspace(min(x), max(x), 1001);

synt1 = polyfit(x,y,1);
ypoly1 = polyval(synt1, x);
error(1) = norm(y-ypoly1);
yplot1 = polyval(synt1, xplot);

synt2 = polyfit(x,y,2);
ypoly2 = polyval(synt2, x);
error(2) = norm(y-ypoly2);
yplot2 = polyval(synt2, xplot);

if method < 0
    disp('Wrong method');
    value = 88888;
    return
end

if  method == 1
    logy = log(y);
    synt3 = polyfit(x, logy, 1);
    a = exp(synt3(2));
    b = synt3(1);
    y3 = a*exp(b*x);
    error(3) = norm(y-y3);
    yplot3 = a*exp(b*xplot);
elseif method == 2
    yinv = 1./y;
    xinv = 1./x;
    pp = polyfit(xinv,yinv,1);
    a = 1/pp(2);
    b = pp(1) * a;
    y3 = a*x ./(b+x);
    error(3) = norm(y-y3);
    yplot3 = a*xplot ./(b+xplot);
else
    k = method;
    synt3 = polyfit(x,y,k);
    y3 = polyval(synt3, x);
    error(3) = norm(y-y3);
    yplot3 = polyval(synt3, xplot);
end

plot(x, y, 'k*', xplot, yplot1, '-b', x, ypoly1, '*b', ...
    xplot, yplot2, '-r', x, ypoly2, '*r', ...
    xplot, yplot3, '-g', x, y3, '*g')
legend('data', 'Linear Least squares', 'Value LLS', 'Quadratic Least Squares', 'Value QLS','Epilogh', 'Value' )
end