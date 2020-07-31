%% HY 213 - ARI8MHTIKH ANALYSH
%% ERGASTHRIO 1
%% ONOMA:
%% AEM:
%% TMHMA:
%% EMAIL:

diary erg1 

%STAQERES TOU MATLAB/Octave
pi

i

%STAQERES TOY SYSTHMATOS MESA APO TO MATLAB
realmin

realmax

%MERIKES ENSWMATWMENES SYNARTHSEIS
sqrt(4)

exp(1)

log(ans)

sind(30)

sin(pi/6)

4*atan(1)

%EMFANISH ARIQMWN STO COMMAND WINDOW 
pi
format long
pi
format short e
pi
format long e
exp(1)
format short

%EKXORHSH TIMON SE METABLHTES
x=0.001
y=5-8

z = x+y

x=3
z

%OLES OI METABLHTES STO MATLAB EINAI PINAKES!
x = [-4 3.2 5 -9 6.1]   % METABLHTH ORIZONTIO DIANYSMA

%ORISMOS DIANYSMATOS STHLHS
c1=[1;2;3;4;5]
xx = [11 22 33 44]'
c2=x'

%POLLAPLASIASMOS DIANYSMATOS ME ARIQMO

0.5*x

%PROSQESH ARIQMOY SE DIANYSMA (SE KAQE STOIXEIO TOY DIANYSMATOS)

1.2 + x

%PRAJEIS METAJY DIANYSMATWN
y=2*x+4
x+y;
x-y;

%x*y
x.*y
x/y
x./y

%EYRESH PLHQOYS STOIXEION DIANYSMATOS
a= length(x) 

b= length(y)

%ALLOI TROPOI ORISMOU DIANYSMATWN


%DIANYSMA TOU OPOIOU TA STOIXEIA DIAFEROUN KATA BHMA ME SYGKEKRIMMENO
%MEGE8OS
x = [2:2:27]    
length(x)

%DIANYSMA TA STOIXEIA TOU OPOIOU EINAI EPILEGMENA STOIXEIA ALLOU DIANYSMATOS
x2(1) = x(3)
x2(2) = x(6)
length(x2)
x1 = x(2:2:10)    
length(x1)


%ORISMOS DIANYSMATOS ME for loop 
for k =1:1:10
  y(k) = k*2.5;   
end

%EYKLEIDEIO MHKOS DIANYSMATOS
mhkos = norm(y,2)

%SYNARTHSEIS DIANYSMATWN
min(x)
max(y)
mean(x1)

%GRAFIKES PARASTASEIS 
therm = [8 9 12 17 13 10]
x = [2 6 10 14 18 22];
b=length(therm)

plot(x,therm)
%axis([1 6 50 63])
xlabel ('wra sth diarkeia ths hmeras ')
ylabel ('thermokrasia (C)')
title ('thermokrasia hmeras')
hold on
plot(x,therm, '*r')
hold off
xx=[1:0.2:6]
yy = 2.5*xx+4 

hold on
plot(xx,yy, ':g')
hold off


%ASKHSH 1
%Oriste ena dianysma y me 18 stoixeia, pou kaqe tou stoixeio einai iso me to 
%triplasio ths qeshs toy meion 9.

y = [1:18]*3-9

%ASKHSH 2
%Ypologiste th 2h dynamh twn stoixeiwn tou y me mia entolh.
d = y.^2

%ASKHSH 3
%Ypologiste to eswteriko ginomeno tou dianysmatos y me ton eayto tou me mia entolh.
eg=y*y'

%ASKHSH 4
%Ypologiste thn eykleidia norma tou y xrhsimopoiwntas thn synarthsh norm.
%Ti sxesh exei to nor2 me thn timh ths eg?
nor2 = norm(y,2)

%ASKHSH 5 
%Kante th grafikh parastash twn zevgariwn (y(i),d(i)), i=1,2,3,....
%Balte labels kai titlo sth grafikh parastash.
plot(y,d,'*r')
xlabel ('times dianysmatos y ')
ylabel ('times dianysmatos d')
title ('y vs d')

diary off
