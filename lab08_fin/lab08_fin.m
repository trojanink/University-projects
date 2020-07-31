%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergatshrio 8
%% SYNEXEIA STHN EISAGWGH STO MATLAB. EISAGWGH STHN PAREMBOLH
%% yota@uth.gr



clear; clc;
%% NEA YLH
%% Xrhsh sxhmatos Horner gia ypologismo timh polywnymou, p(x) =
%% 2x^3-4x^2+3x+1 = ((2x-4)x+3)x+1
%% ASKHSH 1
%% Ylopoihste thn evaluatepolynomial(poly, n, t) h opoia ypologizei thn timh toy 
%% polywnymoy ba8mou n, me syntelestes sto dianysma poly(ksekinontas apo to sta8ero 
%% oro pros to megistoba8mio), sto shmeio me
%% tetmhmenh t. H synarthsh sas na doylevei kai gia dianysma t me polla shmeia.

disp('ASKHSH 1');pause
timh = evaluatepolynomial([1 3 -4 2] , 3 , 0.5)
timh = evaluatepolynomial([1 3 -4 2] , 3 , [0.5 0.1 0])

%% Ypen8ymhsh apo shmeiwseis 8ewrias, gia parembolh me monwnyma, dhmioyrgia
%% pinaka Vandermonde.
%% ASKHSH 2
%% Ylopoieiste tis synarthseis matrixgenerator(x) h opoia dhmiourgei kai 
%% epistrefei ton pinaka Vandermonde gia ta shmeia pou einai apo8hkeymena 
%% sto shmeia dianysma. 

disp('ASKHSH 2');pause;
shmeia = [0:0.1:1];
a = matrixgenerator(shmeia)

%% ASKHSH 3a
%% Ypologiste ta polywnyma poy paremballoun th synarthsh f(x) = exp(-4x^2)
%% se 3, 7, 13, 31 kai 61 isapexonta shmeia tou diasthmatos [-3, 3]. Kane th
%% grafikh parastash  ths synarthshs kai tvn polyvnymvn sto idio grafiko
%% para8yro kai ypologiste to sfalma (megisth kata apolyth timh ths diaforas
%% toy polywnymou apo th synarthsh) gia ka8e polywnymo xrhsimopoiwntas 601 
%% isapexonta shmeia sto parapanw diasthma.
%% Sto idio grafiko para8yro alla se allh grafikh parastash, anaparasthsate 
%% tis synarthseis sfalmata gia ola ta polywnyma

disp('ASKHSH 3a'); pause; clf; clear all;

xplot = linspace(-3,3, 601); % tetmhmenes shmeiwn gia grafikh parastash
expplot = exp(-4*xplot.*xplot); % tetagmenes shmeiwn gia grafikh parastash
pause;
shmeia = [3 7 13 31 61];
for i = 1:5
    x = linspace(-3, 3,shmeia(i));
    n = shmeia(i);
    a = matrixgenerator(x);
    [l, u] = lu(a);
    y = exp(-4*x.^2);
    yi = u\(l\y');
    for k = 1:601
      yy(i,k) = evaluatepolynomial(yi, n-1, xplot(k));    
    end    
    error = max(abs(expplot-yy(i,:)));
    fprintf('To sfalma me polywnymo parembolhs se %2d shmeia einai %12.8f \n',shmeia(i), error);

pause;
end
subplot(2, 1, 1)
plot(xplot, yy(1,:), xplot, yy(2,:), xplot, yy(3,:),xplot, yy(4,:), xplot, yy(5,:)); hold on;
legend('3 shmeia','7 shmeia','13 shmeia','31 shmeia','61 shmeia');
plot(xplot, expplot,'k-','linewidth',2);
title('H synarthsh exp(-4x^2) kai ta polywnyma parembolhs');
xlabel('x'); ylabel('y'); axis([-3 3 -5 5]); hold off
subplot(2, 1, 2)
plot(xplot, expplot-yy(1,:), xplot, expplot-yy(2,:), xplot, expplot-yy(3,:),xplot, expplot-yy(4,:), xplot, expplot-yy(5,:)); hold on;
legend('3 shmeia','7 shmeia','13 shmeia','31 shmeia','61 shmeia');
title('To sfalma gia ola ta polywnyma parembolhs');
xlabel('x'); ylabel('y'); axis([-3 3 -5 5]); hold off

%%
%% ASKHSH 3b
%% Ypologiste ta polywnyma poy paremballoun th synarthsh f(x) = exp(-4x^2)
%% se 3, 7, 13, 31 kai 61 shmeia Chebychev tou diasthmatos [-3, 3]. Kane th
%% grafikh parastash  ths synarthshs kai tvn polyvnymvn sto idio grafiko
%% para8yro kai ypologiste to sfalma (megisth kata apolyth timh ths diaforas
%% toy polywnymou apo th synarthsh) gia ka8e polywnymo xrhsimopoiwntas 601 
%% isapexonta shmeia sto parapanw diasthma.  
%% Sto idio grafiko para8yro alla se allh grafikh parastash, anaparasthsate 
%% tis synarthseis sfalmata gia ola ta polywnyma

disp('ASKHSH 3b'); pause; clf; clear all;

xplot = linspace(-3,3, 601); % tetmhmenes shmeiwn gia grafikh parastash
expplot = exp(-4*xplot.*xplot); % tetagmenes shmeiwn gia grafikh parastash

shmeia = [3 7 13 31 61];
for i = 1:5
    n = shmeia(i);
    x = 3*cos(((2*[1:n]-1)/(2*n))*pi);
    a = matrixgenerator(x);
    [l, u] = lu(a);
    y = exp(-4*x.^2);
    yi = u\(l\y');
    for k = 1:601
      yy(i,k) = evaluatepolynomial(yi, n-1, xplot(k));    
    end    
    error = max(abs(expplot-yy(i,:)));
    fprintf('To sfalma me polywnymo parembolhs se %2d shmeia einai %12.8f \n',shmeia(i), error);
    subplot(3,1,1)
    plot(x, n*ones(n,1), '*'); hold on
end
subplot(3, 1, 2)
plot(xplot, yy(1,:), xplot, yy(2,:), xplot, yy(3,:),xplot, yy(4,:), xplot, yy(5,:)); hold on;
legend('3 shmeia','7 shmeia','13 shmeia','31 shmeia','61 shmeia');
plot(xplot, expplot,'k-','linewidth',2);
title('H synarthsh exp(-4x^2) kai ta polywnyma Chebychev parembolhs');
xlabel('x'); ylabel('y'); axis([-3 3 -5 5]); hold off
subplot(3, 1, 3)
plot(xplot, expplot-yy(1,:), xplot, expplot-yy(2,:), xplot, expplot-yy(3,:),xplot, expplot-yy(4,:), xplot, expplot-yy(5,:)); hold on;
legend('3 shmeia','7 shmeia','13 shmeia','31 shmeia','61 shmeia');
title('To sfalma gia ola ta polywnyma Chebychev parembolhs');
xlabel('x'); ylabel('y'); axis([-3 3 -5 5]); hold off
