function c = countEven(v)
%Filename - countEven.m
%Function - c = countEven(v)
% This function counts the number of even
% integers in vector v and returns the
% count in c
[m,n] = size(c);
c = 0;
for i=1:1:m
    for j = 1:1:n
         if mod(v(i,j),2) == 0 % Number is even
             c = c + 1;
         end
    end
end