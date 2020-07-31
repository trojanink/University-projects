%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergatshrio 2 
%% ONOMA:
%% AEM:
%% TMHMA:
%% EMAIL:
  

% 
% %% Lyste tis parakatw 3 askhseis se 15 lepta se ena diary arxeio kai paradwste tis mesw eclass
% %% se ena zipped fakelo "erg2_username.zip"
% 
% % diary erg2
% 
% %% ASKHSH 1
% %% Dhmiourgeiste, xwris for loop, ena dianysma 10 8esewn pou ta stoixeia tou na orizontai
% %% ws x(i) = 1/i, i=1...10.
% % x = 
% 
% %% ASKHSH 2
% %% Dhmioyrgeiste me for loop, ena dianysma 10 8esewn pou ta stoixeia tou 8a
% %% orizontai apo thn akolou8ia tou Fibonacci. Dhladh y(1) = 0, y(2)=1,y(n+2)=y(n)+y(n+1).
% 
% 
% %% ASKHSH 3
% %% Ypologiste, xwris for loop, to eswteriko ginomeno twn 2 prohgoumenwn dianysmatwn.
% 
% %diary off
% 
% %% NEO YLIKO
% 
% %% ARXEIA/PROGRAMMATA MATLAB .
% %% EMFANISH STHN OQONH -ENTOLES disp KAI fprintf
% %% DHMIOYRGIA PINAKWN ME DIAFORETIKOYS TROPOYS, PRAKSEIS ME PINAKES 
% %% DHMIOURGIA SYNARTHSEWN APO TON PROGRAMMATISTH
% %% ELEGXOS SYNQHKHS- ENTOLH if
% %% EPANALHPTIKH DIADIKASIA - ENTOLH while
% 
% clc; % GIA NA KAQARISEI TO COMMAND WINDOW
% 
% clear; % GIA NA KAQARISEI H MNHMH KAI OLES OI METABLHTES
% %% ISXYRH PAROTRHNSH:::: TA PROGRAMMATA SAS NA ARXIZOYN ME ENTOLES
% %% POY NA KAQARIZOYN THN MNHMH TOY Matlab, KAQWS KAI TA PARAQYRA TWN
% %% GRAFIKWN PARASTASEWN.
% 
% % EMFANISH DEDOMENWN STHN OQONH ME TIS ENTOLES disp KAI fprint
% 
% n = input('DWSTE TH DIASTASH TOU DIANYSMATOS a ');
% disp('ORISTE TO DIANYSMA a');
% for k =1:n
%   fprintf('DWSTE TO STOIXEIO %5d TOY DIANYSMATOS a ',k );
%   a(k) = input(' ');
% end
% 
% %MORFOPOIHMENH EMFANISH TOU DIANYSMATOS STHN OQONH 
% k=1;
% while k <= length(a)
%  fprintf('a(%1d) = %10.5f \n', k, a(k)); 
%  k=k+1;
% end
% 
% MORFOPOIHMENH EMFANISH TOU AQROISMATOS TWN STOIXEIWN TOU a STHN OQONH
% fprintf('TO AQROISMA TWN STOIXEIWN TOY DIANYSMATOS a EINAI ISO ME:: %10.5f \n',sum(a));

%pause
% % 
% % % %% ORISMOI PINAKWN
% disp('ORISMOI PINAKWN')
% d = [1 3 4 6 ; 3 7 8 9];
% 
% e = [16 20
%      9 18];
%    
% g = [3 5 ; 7 9];
% %% DHMIOYRGIA PINAKWN ME DIAFORETIKOYS TROPOYS, PRAKSEIS ME PINAKES 
% %% KEF. 3, PARAGRAFOI 1-5,7-10
% 
% a = [ 11 12 13 14
%       21 22 23 24]
%   
% b = [11 12 13; 21 22 23]
% % % 
% % % % % pause
% % % % % 
% % % % % %% DHMIOURGIA PINAKVN APO DIANYSMATA
% % % % 
% d1 = [1 2 3 4 5]
% 
% d2 = [0 9 8 7 6]
% 
% c1 = [d1 d2]
% 
% c2 = [d1 ; d2]
% 
% c3 = [d1' d2']
% 
% c4 = [d1; d2]'
% % % % 
% % % % %pause
% % % % 
% % % % %% KATASKEYH PINAKWN APO GINOMENO DIANYSMATWN
% x = [1 2 3 4 5 6 7]
% for k =1:1:length(x)
%  y(k) = k*1.45;   
% end
% 
% x' * y
% % % % %pause
% % % % %% ORISMOS PINAKWN ME ENTOLES Matlab 
% % % % 
% p1 = zeros(3,2)
% pause
% p2 = eye(5)
% pause
% p3 = ones(4,3)
% 
% % % pause
% % % % 
% % % % % EYRESH DIASTASEWN ENOS PINAKA
% a
% meg_pin =size(a)
% rows = size(a,1)
% columns = size(a,2)
% 
% if rows==columns
%     disp('o pinakas einai tetragwnkos')
% else
%     disp('o pinakas den einai tetragwnkos')
% end
% % % 
% % % %pause
% % % % % 
% % % % % %% EYRESH STOIXEIWN PINAKA POU BRISKONTAI SE SYGKEKRIMENES QESEIS
% a
% a(2,1)
% a(1,3)
% % OLA TA STOIXEIA MIAS GRAMMHS
% a(1,:)
% % OLA TA STOIXEIA MIAS STHLHS
% a(:,3)
% % % % %pause
% % % 
% % % %% POLLAPLASIASMOS PINAKA ME DIANYSMA 
% % % %% TO KOSTOS 4 PROIONTWN POU PARAGOYN DYO ETAIREIES, PERIGRAFETAI APO TO 
% % % %% DIANYSMA costos OI POSOTHTES POU KALEITAI NA PARAGEI KAQE ETAIREIA, 
% % % %% DIDETAI STON PINAKA posothtes
% % % 
% costos = [34 22 61 72];
% posothtes = [13 9; 6 15; 7 18; 20 12];
% % % 
% % % % NA BREQEI TO KOSTOS ANA ETAIREIA
% c = costos * posothtes
% % h 
% disp('To synoliko kostos gia thn prwth etaireia')
% c1 = costos*posothtes(:,1) 
% disp('To synoliko kostos gia th deyterh etaireia')
% c2 = costos*posothtes(:,2)
% % %pause
% % % 
% % % %% PROSQESH PINAKA ME PINAKA, XRHSH TOY +
% % % %% OI PINAKES c3 KAI c4 EINAI 5X2 KAI OI DYO, TO AQROISMA TOYS, 
% % % %% EINAI O PINAKAS....
% c3,c4
% prosqesh = c3 + c4
% 
% %% POLLAPLASIASMOS PINAKA ME PINAKA (ORISMOS OPWS STA MAQHMATIKA), 
% %% XRHSH TOY * 
% %% O a EINAI 2X4 KAI O p1 EINAI 4X3, ARA TO GINOMENO TOYS EINAI 
% %% PINAKAS DIASTASEWN.....
% a,p3
% pol1 = a * p3
% 
% % POLLAPLASIASMOS PINAKA ME PINAKA ANA STOIXEIO, XRHSH TOY .*
% % OI PINAKES c3 KAI c4 EINAI 5X2 KAI OI DYO, TO GINOMENO TOYS ANA 
% % STOIXEIO, EINAI O PINAKAS....
% 
% pol2 = c3 .* c4
% 
% % DIAIRESH PINAKA ME PINAKA ANA STOIXEIO, XRHSH TOY ./
% % OI PINAKES c3 KAI c4 EINAI 5X2 KAI OI DYO, TO PHLIKO TOYS ANA STOIXEIO, EINAI O PINAKAS....
% 
% pol3 = c3 ./ c4

% pause
% 
% %% ORISMOS SYNARTHSHS STO MATLAB
% 
% %% PARADEIGMA KLHSHS THS SYNARTHSHS s = st_pin(A,i,j),H OPOIA 
% %% DEXETAI SAN ORISMA ENA PINAKA A KAI MIA QESH TOU PINAKA
% %% KAI EPISTREFEI TO ANTISTOIXO SHMEIO
% % 
% disp('SYNARTHSEIS');pause;
d=[1 2 3; 4 5 6]
s1=st_pin(d,2,3)
% 
% %%
% %% Grapste mia synarthsh h opoia na dexetai san orisma eisagwghs ena dianysma akeraiwn (d)
% %% kai h opoia 8a epistrefei to plh8os twn artiwn stoixeiwn (count) toy dianysmatos
% %% H synarthsh 8a kaleitai ws count = countEven(d)
c = [1 2 4 5 7 10 11];
v = [2 4 10 12 14 -1];
count = countEven(v)
count = countEven(c)
% 
