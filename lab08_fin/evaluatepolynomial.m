function  y = evaluatepolynomial(synt, n , x)

y = synt(n+1);

for i=n:-1:1
    y = y.*x+synt(i);
end