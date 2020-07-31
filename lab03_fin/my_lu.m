function [L, U] = my_lu(A)
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

for k = 1:n
   for i = k+1:n
      L(i, k) = A(i, k) / A(k, k);
      for j = k+1:n
         A(i, j) = A(i, j) - L(i, k)*A(k, j);
      end
   end
   for j = k:n
      U(k, j) = A(k, j);
   end
   if n <= 10
    figure(k); clf;
    dispMEq('A=L*U',A,L,U);
    title(['Step ' num2str(k)], 'FontSize', 15);
    pause
   end
end
