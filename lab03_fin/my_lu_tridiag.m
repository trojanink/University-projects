function [L, U] = my_lu_tridiag(A)
% Square A=LU factorization.
%
% Usage: [L, U] = my_lu(A)
% INPUT:
% A         - square invertible m-by-m matrix
% OUTPUT:
% L         - square m-by-m unit lower-triangular matrix;
% U         - square m-by-m upper-triangular matrix;
% ALGORITHM:
% L and U are computed by Gaussian elimination, 
% i.e., row exchange, so that L*U=A.
%
% Examples: 
%           A = randn(5); [L,U] = my_lu(A); 

[m, n] = size(A);
if m ~= n
   error('Matrix must be square.')
end
L = eye(n, n);
U = zeros(n, n);

for k = 1:n-1
    L(k+1, k) = A(k+1, k) / A(k, k);
    A(k+1, k+1) = A(k+1, k+1) - L(k+1, k)*A(k, k+1);
    for j = k:k+1
      U(k, j) = A(k, j);
    end
    if n <= 10
     figure(k); clf;
     dispMEq('A=L*U',A,L,U);
     title(['Step ' num2str(k)], 'FontSize', 15);
     pause
    end
end
U(n, n) = A(n, n);
figure(n); clf;
dispMEq('A=L*U',A,L,U);
title(['Step ' num2str(n)], 'FontSize', 15);

