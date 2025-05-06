function [out]=phiTpsi(in)
%% Calculating Euler Angles [Phi Theta Psi] ;
% pTp is: Phi & Theta & Psi;

Q1=in(1);
Q2=in(2);
Q3=in(3);
Q4=in(4);

theta=-asin(2*(Q4*Q2+Q1*Q3));
phi=asin((2/cos(theta))*(Q4*Q3-Q1*Q2));
psi=asin((2/cos(theta))*(Q2*Q3-Q1*Q4));

out=[theta phi psi];
end