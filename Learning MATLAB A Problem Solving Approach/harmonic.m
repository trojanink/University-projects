function grady = harmonic(t,y)

%% apo th y'' = -y pame sto systhma me lysh thn [y1, y2] 
%% pou y1 = y, y2 = y' i alliws
%% dy1/dt = y2
%% dy2/dt = -y1  me xrhsh tou deksiou merous ths diaforikhs
%% to opoio grafetai sto Matlab ws.....

grady= [y(2); -y(1)];