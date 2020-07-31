function a = matrixgenerator(x)

n = length(x);
a = ones(n);

for i=2:n
    a(:,i) = a(:,i-1).*x';
end
