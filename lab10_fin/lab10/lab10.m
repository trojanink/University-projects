%% HY 213 - ARI8MHTIKH ANALYSH
%% Ergatshrio 10
%% Ari8mhtikh Oloklhrwsh kai Paragwgish,
%% onomatepwnymo = .......
%% userID = .......
%% AEM = .......% 

%% ASKHSH 1
%% Symbolikoi ypologismoi gia ypologismo oloklhrwmatwn se synexh dedomena.
%% synarthsh 1 metablhths

clf; clc; clear all, disp('ASKHSH 1')
ekf1 = '1./sqrt(1+x.^4)';
f1 = inline(ekf1);
ezplot(f1, [-2, 2]);
olok1 = quad(f1, -2, 2);
fprintf('QUAD: To oloklhrwma ths synarthshs %s einai %12.8f \n',ekf1,olok1);
pause

%% ASKHSH 2
%% Oloklhrwsh me diakrita dedomena
%% Xrhsimopoihste thn me8odo toy trapeziou (olok=trapz(x,y)) gia na
%% ypologisete to oloklhrwma ths parakatw synarthshs.

%% Synarthsh h(x) = 1/((x-0.3)^2+0.01)  + 1/((x-0.9)^2+0.4)
% clf; clc; clear all, disp('ASKHSH 2')
% h = inline('1./((x-0.3).^2+0.01)  + 1./((x-0.9).^2+0.4)');
% ezplot(h,[0,10]); title('1/((x-0.3)^2+0.01)  + 1/((x-0.9)^2+0.4)'); axis tight;
% x = [0:0.5:10];
% y = h(x);
% olokt = trapz(....  ,  ....);
% fprintf('TRAPZ: To oloklhrwma ths h sto [0, 10] einai %12.8f \n',olokt);
% hold on;
% plot(x,y, '*-r')
% pause;


%% ASKHSH 2a
%% Taksh sygklishs me8odou oloklhrwshs.
%% Xrhsimopoihste thn me8odo toy trapeziou (olok=trapz(x,y)) kai epibebaiwste thn tajh sygklishs ths.
%% Xrhsimopoieiste thn quad,  gia na sygkrinete ta apotelesmata kai na ypologisete to sfalma.

%% Synarthsh h(x) = 1/((x-0.3)^2+0.01)  + 1/((x-0.9)^2+0.4)
% clf; clc; clear all, disp('ASKHSH 2a')
% h = inline('1./((x-0.3).^2+0.01)  + 1./((x-0.9).^2+0.4)');
% ezplot(h,[0,10]); title('1/((x-0.3)^2+0.01)  + 1/((x-0.9)^2+0.4)'); axis tight;
% [olokq, nq] = quad(h, 0, 10, 5e-5)
% ii= 1;
% for n=11:10:1001
% x = linspace(0, 10, n);
% y = h(x);
% oloktra(ii) = trapz(x,y);
% fprintf('TRAPEZIO: To oloklhrwma ths h sto [0, 10] einai %12.8f \n',oloktra(ii));
% error(ii) = abs(oloktra(ii)-olokq)
% ii = ii+1;
% end
% figure(1)
% subplot(2,1,1)
% plot([11:10:1001], oloktra)
% xlabel('# shmeiwn diakritopoihshs')
% ylabel('oloklhrwma me trapz')
% subplot(2,1,2)
% plot([11:10:1001], error)
% xlabel('# shmeiwn diakritopoihshs')
% ylabel('sfalma oloklhrwmatos me trapz')
% pause;


%% ASKHSH 5
%% Ari8mhtikoi ypologismoi gia ypologismo paragwgwn
%% xrhsh ths diff gia ypologismo 1hs paragwgou

%pause; clf; clc; clear all, disp('ASKHSH 5')
%x = linspace(0,2*pi,50);
%yy = sin(x);
%cosine = diff(yy) ./ diff(x);
%xxcos = x(..........) + diff(x).............;
%hold on; 
%plot(x,yy, 'r*',xxcos, cosine, 'g*', x, 0*x,'r+', xxcos,0*xxcos,'g+')
%legend('synarthsh','paragwgos','shmeia synarthshs','shmeia paragwgishs')

%% ASKHSH 6
%% Ariumhtikh paragwgish se perissoetres diastaseis
%% Ypologismos prwtwn merikwn paragwgwn me thn gradient.

% pause; clf; clc; clear all, disp('ASKHSH 6')
% [x,y] = meshgrid(-2:.2:2, -2:.2:2);
% z = x .* exp(-x.^2 - y.^2);
% [px,py] = gradient(z,.2,.2);
% figure(1);
% contour(x,y,z, 20),hold on, %sxediasmos ths synarthshs
% colorbar;
% quiver(x,y,px,py), hold off % sxediasmos tou gradient(anadelta) ths synarthshs
% xlabel('x');ylabel('y');
% figure(2)
% surf(x,y,z);
% xlabel('x');ylabel('y');zlabel('z');
