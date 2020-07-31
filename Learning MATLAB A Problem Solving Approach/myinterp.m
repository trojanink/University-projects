%% H synarthsh myinterp xrhsimopoiei me8odous parembolhs
%% gia na ypologisei times ths 8ermokrasias se sygkekrimenes wres thw hmeras.
%% H synarthsh kaleitai ws value = myinterp(t, method) opou 
%% value = h timh / oi times ths 8ermokrasias stis wres poy pernoyn sto t ( ari8mos i sthlodianysma)
%% t = h wra / oi wres poy endiaferomaste na ypologisoyme th 8ermokrasia ( ari8mos i sthlodianysma)
%% method = flag poy boh8a na epileksoume me8odo parambolhs
%%           0 = polywnymikh parembolh
%%           1 = grammikh spline
%%           2 = kybikh spline
%%           3 = efarmozontai kai oi 3 me8odoi gia oles tis pi8anes xronikes stigmes
%%               edw h value einai pinakas opou h prvth sthlh periexei 
%%               ta apotelsmata gia th polywnymikh parembolh, 
%%               h deyterh ta apotelesmata apo thn grammikh spline kai 
%%               h trith ta apotelesmata apo thn kybikh spline
%% gia logoys oikonomias xronoy oi gnvstes times ths 8ermokarsias/wras 
%% einai ka8orismenes mesa sth synarthsh stis metablhtes therm kai time


function value = myinterp( t, method )

time = [0:4:24]';
therm = [15 14.2  12.8  13.9 17  16.8 15.5 ]';

n = length(t);     
if method == 3
    value = zeros(n, 3);
else
    value = zeros(n);
end

tplot = linspace(0,24,145);

if method == 0 
    m = matrixgenerator(time');
    synt = m\therm;
    value = evaluatepolynomial(synt, length(time)-1 , t);
    vplot = evaluatepolynomial(synt, length(time)-1, tplot);
    plot(time, therm, 'k*', tplot, vplot, '-b', t, value, '*b')
    legend('data', 'polynomial', 'value')
elseif method == 1 
    value = interp1(time, therm, t, 'linear');
    vplot = interp1(time, therm, tplot, 'linear');
    plot(time, therm, 'k*', tplot, vplot, '-r', t, value, '*r')
    legend('data', 'linear spline', 'value')
elseif method == 2 
    value = interp1(time, therm, t ,'cubic');
    vplot = interp1(time, therm, tplot, 'cubic');
    plot(time, therm, 'k*', tplot, vplot, '-g', t, value, '*g')
    legend('data', 'kybikh spline', 'value')
elseif method == 3
    m = matrixgenerator(time');
    synt = m\therm;
    value(:,1) = evaluatepolynomial(synt, length(time)-1, t);
    value(:,2) = interp1(time, therm, t, 'linear');
    value(:,3) = interp1(time, therm, t ,'cubic');
    
    vplot1 = evaluatepolynomial(synt, length(time)-1, tplot);
    vplot2 = interp1(time, therm, tplot, 'linear');
    vplot3 = interp1(time, therm, tplot, 'cubic');
    plot(time, therm, 'k*', tplot, vplot1, '-b', t, value(:,1), '*b', ...
        tplot, vplot2, '-r', t, value(:,2), '*r', ...
        tplot, vplot3, '-g', t, value(:,3), '*g')
    legend('data', 'polynomial', 'value', 'linear spline', 'value','kybikh spline', 'value' )
else
    disp('Wrong method');
    value = 88888;
    return
end
xlabel('wres sth diarkeia ths hmeras')
ylabel('thermokrasia')
end

