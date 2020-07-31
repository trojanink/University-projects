%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergasthrio 3
%% Dianysmata, pinakes kai meuodoi epilyshs grammikwn systhmatwn
%% yota@uth.gr

clear all; clc; clf;
%%
%% GRAMMIKES EKSISWSEIS
%%
%% Anoikste me ena browser to arxeio drawLA/html/drawLAInro.html kai diabaste tis perigrafes.
%% Pros8este sto searching path tou MATLAB ta dyo folders me tis biblio8hkes pou sas dinw
%% grafontas sto command line
%% path(path,'FULL_PATH_TO ERG11\drawLA')
%% Ston proswpiko sas ypologisth (san administrators) balte ta drawLA kai solvingAx=b mesa sta searching paths tou Matlab
%% File -> SetPath -> Add Folders(with Subfolders)  kai meta swste to pathdef.m opws sas zhthsei to matlab se kapoio folder pou na exete prosbash.

%% ASKHSH 1
%% Xrhsimopoihste th synarthsh drawVector gia na sxediasete dianysmata sto 2d epipedo
%% a = [3 1]' b = [-2 1]';

figure(1); clf;
a = [3 1]'; b = [-2 1]';
drawVector([a b], 'g->', {'a', 'b'});
title('Draw two vectors')
pause
%% ASKHSH 2
%% Xrhsimopoihste th synarthsh drawVector gia na sxediasete dianysmata sto 3d xwro

disp('Press enter to continue'); pause;
a = [1 2 3]'; b = [3 -1 2]'; 
figure(2);clf; hold on;
drawVector([a b], {'a','b'});       % Plot the vectors
drawLine([a b], 'r3');              % Draw a line between them
view(15,5);
pause;
view(60,10);
hold off;
title('Draw a line in 3D with drawLine()')
pause

%% ASKHSH 3
%% Ylopoihste thn LU paragontopoihsh mesa sth synarthsh my_lu, h opoia 
%% kaleitai me [l,u] = my_lu(a), opou a o arxikos pinakas , kai l,u oi
%% oi pinakes pou prokeiptoun apo thn paragontopoihsh

a = rand(5,5);
[l,u] = my_lu(a);
dispMEq('A=L*U',a,l,u)
a-l*u
pause
%% ASKHSH 4
%% Xrhsimopoihste tis synarthsies tic kai toc toy matlab gia na xronometrhsete 
%% thn LU paragonotpoihsh opws exei ylopoih8ei mesa sthn my_lu.
%%
clear all;
n=(50:50:400);
for  ii = 1:length(n)
   nn = n(ii)
   a = rand(nn,nn); 
   tStart = tic;
   for j=1:5 , [l,u] = my_lu(a);  end
   time(ii)=toc(tStart)/5
end
%% grafikh anaparastash xronou kai ypologistikou kostous
figure(10)
loglog(n,time,n, 2*n.^3/3) 
pause
%% ASKHSH 5
%% Ylopoihste thn LU paragontopoihsh mesa sth synarthsh my_lu_tridiag, h opoia 
%% kaleitai me [l,u] = my_lu_tridiag(a), opou a o tridiagwnios arxikos pinakas , kai l,u oi
%% oi pinakes pou prokeiptoun apo thn paragontopoihsh

a1 = rand(6,1);
a2 = rand(5,1);
a3 = rand(5,1);
a = diag(a1)+diag(a2,1)+diag(a3,-1)
[l,u] = my_lu_tridiag(a);
dispMEq('A=L*U',a,l,u)
a-l*u

pause
