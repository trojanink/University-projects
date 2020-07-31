%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergasthrio 9
%% SYNEXEIA STHN EISAGWGH STO MATLAB. EISAGWGH STHN PAREMBOLH
%% yota@uth.gr



clear; clc;
%% NEA YLH
%% ASKHSH 1
%% Xrhsimopoihste thn synarthsh interp1 toy Matlab, me oles tis dynates me8odous, 
%% kai dhmiourgeiste polyvnyma poy parembaloun thn synarthsh f(x) = 1/(1+25*x*x)
%% sta shmeia -3, -2, -1, 0, 1, 2, 3.

disp('ASKHSH 1'); pause; clf; clear all;
x = -3:3;
n = length(x);
for i=1:n
 y(i)=1/(1+25*x(i)^2);
end;
xi=-3:.1:3;
yi=interp1(x,y',xi,'linear');
plot(x,y,'ko',xi,yi,'b-')
  
hold on

yi2=interp1(x,y',xi,'nearest');
plot(xi,yi2,'r:')

yi3=interp1(x,y',xi,'spline');
plot(xi , yi3,'g.-')

yi4=interp1(x,y',xi,'PCHIP');
plot( xi, yi4,'m-')
  
xxi=-4:.1:4; 
yi5=interp1(x,y,xxi,'spline','extrap');
plot(xxi,yi5,'c--')
legend('points','linear','nearest','spline','pchip','spline-extrap')
axis([-4 4 -3 3]);  

%% ASKHSH 2
%% Xrhsimopoihste th synarthsh spline gia na paremballete thn sin sta shmeia 
%% 0:10 kai ypologiste ths timh ths paremballousas sta shmeia 0:.25:10 .

disp('ASKHSH 2'); pause; clf; clear all;
x=0:10;
y=sin(x);
ezplot('sin(x)',[0 10]); hold on;
xx=0:.25:10;
yy=spline(x, y, xx);
plot(x,y,'ok',xx,yy,'+r');
  
  
%% ASKHSH 3
%% Xrhsimopoihste th synarthsh spline gia na sxediasete ena kyklo me bash
%% ta 21 shmeia panw ston kyklo me gwnia pi*[0:.1:2].
%% Giati dinoume 2 parapánw stoixeia sthn spline?

disp('ASKHSH 3'); pause; clf; clear all;
gwnia = pi*[0:.1:2];
shmeia = [0 cos(gwnia) 0 ; 1 sin(gwnia) 1];
n= size(shmeia,2);
pp=spline(gwnia , shmeia);
yy=ppval(pp,linspace(0,2*pi,101));
plot(yy(1,:),yy(2,:), '-b', shmeia(1,2:n-1), shmeia(2,2:n-1),'or')
    
%% ASKHSH 4
%% Xrhsimopoihste thn interp2 gia na kanete parembolh sth synarthsh 2 metablhtwn
%% f(x,y)=z =  3*(1-x).^2.*exp(-(x.^2) - (y+1).^2) ... 
%% - 10*(x/5 - x.^3 - y.^5).*exp(-x.^2-y.^2) ... 
%% - 1/3*exp(-(x+1).^2 - y.^2) 
%% kai pou einai ylopoihmenh sto Matlab san PEAKS,
%% sta shmeia -3:.5:3. Ypologiste thn parembalousa sta shmeia -3:.125:3.
%% Xrhsimopoihste thn meshgrid gia na ftiaksete ta plegmata gia thn
%% synarthsh kai thn parembalousa.

disp('ASKHSH 4'); pause;figure(1); clf; clear all;
[X,Y]=meshgrid(-3:.5:3);
Z=peaks(X,Y);
[XI,YI]=meshgrid(-3:.125:3);
ZI=interp2(X,Y,Z,XI,YI);
colormap('jet');
mesh(X,Y,Z); hold; mesh(XI,YI,ZI+10);
hold off;
axis([-3 3 -3 3 -5 35])

%% ASKHSH 5
%% Xrhsimopoihste thn interp3 gia na kanete parembolh sth synarthsh 3 metablhtwn
%% pou einai ylopoihmenh sto Matlab san FLOW , se ena plegma apo 20x10x10
%% shmeia. Kante parembolh sta shmeia x=.1:.1:10, y=-3:.1:3, z=-3:.1:3 
%% Xrhsimopoihste thn meshgrid gia na ftiaksete to plegma gia thn
%% parembalousa.
 
pause; figure(2); clf; clear all; disp('ASKHSH 5'); 
[x,y,z,v]=flow(10);
[xi,yi,zi]=meshgrid(.1:.1:10, -3:.1:3, -3:.1:3);
vi=interp3(x,y,z,v,xi,yi,zi);  
slice(xi,yi,zi,vi,[6 9.5],2,[-2 .2])
shading flat
figure(3);
slice(xi,yi,zi,vi,[.1  10],[-3  3],[-3 3])
shading flat

