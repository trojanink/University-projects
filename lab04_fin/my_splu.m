function [P, L, U, sign] = my_splu(A)
% Square PA=LU factorization *with row exchanges*.
%
% Usage: [P, L, U] = splu(A)
% INPUT:
% A         - square invertible m-by-my matrix
% OUTPUT:
% L         - square m-by-m unit lower-triangular matrix;
% U         - square m-by-m upper-triangular matrix;
% P         - square m-by-m permutation matrix;
% sign      - sign = det(P); it is 1 or -1.
% ALGORITHM:
% L and U are computed by Gaussian elimination, with pivoting, 
% i.e., row exchange, so that L*U=P*A.
%
% Examples: 
%           A = randn(5); [P,L,U,sign] = splu(A); 
%
% See also: slu, backSub, forSub.

% Defaults:

[m, n] = size(A);
if m ~= n
   error('Matrix must be square.')
end
P = eye(n, n);
L = eye(n, n);
U = zeros(n, n);
tol = sqrt(eps);
sign = 1;

for k = 1:n
   [max_ak, r] = max(abs(A([k:n], k)));
   r = r+k-1;
   if r ~= k
       if  max_ak < tol
           if nargout == 4
               sign = 0;
               return
           else
               disp('A is singular within tolerance.')
               error(['No pivot in column ' int2str(k) '.'])
           end
       end
       A([r k], 1:n) = A([k r], 1:n);
       if k > 1, L([r k], 1:k-1) = L([k r], 1:k-1); end
       P([r k], 1:n) = P([k r], 1:n);
       sign = -sign;
   end
   for i = k+1:n
      L(i, k) = A(i, k) / A(k, k);
      for j = k+1:n
         A(i, j) = A(i, j) - L(i, k)*A(k, j);
      end
   end
   for j = k:n
      U(k, j) = A(k, j) * (abs(A(k, j)) >= tol);
   end
   if n <= 10
     figure(k); clf;
     dispMEq('P*A=L*U',P,A,L,U);
     title(['Step ' num2str(k)], 'FontSize', 15);
     pause
   end
end

if nargout < 4
   roworder = P*(1:n)';
   disp('Pivots in rows:'), disp(roworder'); end
end
