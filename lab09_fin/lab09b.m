%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergasthrio 9
%% SYNEXEIA STHN EISAGWGH STO MATLAB. ELAXISTA TETRAGWNA
%% onomatepwnymo = .......
%% userID = .......
%% AEM = .......

clf; clear all; clc;
%% ASKHSH 1
%% Xrhsimopoihste tis katallhles synarthseis toy Matlab, wste na efarmosete th me8odo twn
%% elaxistwn tetragwnwn gia na ypologisete ta polywnyma 4ou kai 8ou ba8mou pou proseggizoun
%% ta parakatw dedomena

%disp('ASKHSH 1');pause; clc; clf; clear all; 
%x = linspace(0,3,41); n = length(x);

%y = [ 2.07458  1.78801  2.07548  1.97954  2.08945  1.63480 ...
%   2.03053  1.74630  1.79267  1.42920  1.14101  1.32438 ...
%   1.17944  0.93214  0.87631  0.80062  0.69002  0.79622...
%   0.73527  0.60637  0.80011  0.95631  0.64858  0.95624 ...
%   0.62853  0.55175  0.90018  1.00167  0.60299  1.05339 ...
%   0.87300  0.99931  1.01089  1.11733  0.95633  1.15222 ...
%   1.09389  0.86498  1.04563  1.11432  1.15554 ];

%synt4 = polyfit(x,y,4);
%ypoly4 = polyval(synt4, x);
%sse = ............

%synt8 = ...........;
%ypoly8 = ...........;
%sse = ...............

%title('askhsh 1')
%plot(x,y,'*k', 'linewidth',2); hold on;
%plot(x,ypoly4,':b','linewidth',2);
%plot(x,ypoly8,'--r','linewidth',2);
%legend(.................);

%% ASKHSH 2
%% POSOTHTES POY PERIGRAFONTAI ME EKQETIKES SYNARTHSEIS, DHLADH SYNARTHSEIS
%% THS MORFHS y = a * exp(b*x);
%% YPOLOGISTE THN EKQETIKH SYNARTHSH POY PERIGRAFEI TA SHMEIA x KAI y,
%% KANTE TH GRAFIKH PARASTASH STO IDIO GRAFIKO PARAQYRO.
%% EPISHS YPOLOGISTE TO SXETIKO SFALMA THS PROSEGGISHS.y 

%pause; clf; clear all; disp('ASKHSH 2');
%x = [1 2 3 4 5 6 7 8];
%y = [0.74 0.20 0.065 0.019 0.0053 0.0018 0.0006 0.0002];
%plot(x, y, 'k*'); hold on;

%logy = ....;
%synt = polyfit(... ,... ,...);

%a = ....
%b = ...
%xplot = [1:0.1:8];
%yplot = ..................
%plot(xplot, yplot)

%sxetikosfalma = norm(............) / norm(y)
  

%% ASKHSH 3
%% 8ewreiste thn eikona tou arxeiou "lena.tif" kai kataskevaste ena algori8mo
%% sympieshs ths eikonas me bash thn analysh idiotimwn. Ta bhmata einai ta
%% ekshs:: 
%% - Metatrepste thn eikona se pinaka me th synarthsh imread
%% - Metatrepste ton pinaka apo int se double
%% - Kante analysh SVD
%% - Emfaniste thn eikona xrhsimopoiontas mono 1,2,3,...,k apo tis megalyteres
%% idiotimes(to k einai parametros eisodou) ektelwntas thn entolh image opws
%% thn exw kalesei sto script parakatw.


%pause; clc; clf; clear; disp('ASKHSH 5'); 

%k = input('dwse k : ')
%p=imread('lena','tif');
%[u, s, v] = svd(double(p));

%colormap(gray(255));

%image(u*s*v'); 
%disp('Pateiste enter gia tis proseggiseis.');pause;

%for i=1:k
%   pause(2); clf;
%   image(..............);
%   title([ 'Me xrhsh ' int2str(i) ' idiotimwn' ])
%end
