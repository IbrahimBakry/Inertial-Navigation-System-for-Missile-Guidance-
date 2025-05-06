clc
clear all

syms t
X = 2*exp(t)*sin(t);
Y = 2*exp(t)*cos(t);
Z = exp(t);
r = (9*sqrt(2)/4)*exp(t);

x_dot1 = diff(X,t,1)
y_dot1 = diff(Y,t,1)
z_dot1 = diff(Z,t,1)

x_2dot2 = diff(X,t,2)
y_2dot2 = diff(Y,t,2)
z_2dot2 = diff(Z,t,2)
