function [out]=BlockQ(in)
%% [Block Q]
% Calculating The Matrix Q, "The Quanterion Matrix";
%  our Equation is: "dotQ=0.5*Omega_m/a*Q"
% dotQ=[dQ1 dQ2 dQ3 dQ4];
%  Q=[Q1 Q2 Q3 Q4];

Q=[in(1);in(2);in(3);in(4)];

p=in(5);
q=in(6);
r=in(7);

Omega=[0 -p -q -r ; p 0 r -q ; q -r 0 p ; r q -p 0];
dotQ=0.5*Omega*Q;

out=[dotQ(1);dotQ(2);dotQ(3);dotQ(4)];
end