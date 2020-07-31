function [points, der] = deriv(x,y,method)
% H synarthsh ypologizei thn 1h kai 2h paragvgo ths synarthshs poy didetai
% apo ta shmeia x,y. Oi typoi tvn peperasmenvn diaforwn didontai stis
% odhgies.

n = length(x);
h = x(2)-x(1); %% omoiomorfh diamerish

if method ==1
    points = x(2:1: n-1);
    der =  (y(3:1: n) -  y(1:1: n-2)) ./ (2*h) ;
elseif method == 2
    points = x(2:1: n-1);
    der =  (y(3:1: n) -2*y(2:1: n-1) +  y(1:1: n-2)) ./ (h*h) ;
else
    disp('')
    points = 0;
    der = 0;
end

end

