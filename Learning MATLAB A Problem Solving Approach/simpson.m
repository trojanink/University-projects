function res = simpson(x,y)

n = length(x)-1;
a = x(1);
b = x(n+1);
h = (b-a)/n;

if mod(n,2) == 0  
   res = h*( y(1) + 4*sum(y(2:2:n)) + 2*sum(y(3:2:n-1)) + y(n+1) )/3;
else
   res = NaN;
   fprintf('Error:: H meqodos Simpson den mporei na klhqei. Plhqws diasthmatwn peritto.\n');
end
