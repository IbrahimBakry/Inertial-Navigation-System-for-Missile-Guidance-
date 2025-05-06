function [Out]=File2(T)

% syms t
X = 2*exp(T)*sin(T);
Y = 2*exp(T)*cos(T);
Z = exp(T);
r = (9*sqrt(2)/4)*exp(T);

x_dot = double(vpa(subs(x_dot1,t,T)));
y_dot = double(vpa(subs(y_dot1,t,T)));
z_dot = double(vpa(subs(z_dot1,t,T)));

x_2dot = double(vpa(subs(x_2dot1,t,T)));
y_2dot = double(vpa(subs(y_2dot1,t,T)));
z_2dot = double(vpa(subs(z_2dot1,t,T)));

% % xd = eval(subs(x_dot,t,T));
% % yd = eval(subs(y_dot,t,T));
% % zd = eval(subs(z_dot,t,T));
% % 
% % x2d = eval(subs(x_2dot,t,T));
% % y2d = eval(subs(y_2dot,t,T));
% % z2d = eval(subs(z_2dot,t,T));
% r2 = double(vpa(subs(r,t,T)));

P = (x_dot/r);
Q = (y_dot/r);
R = (z_dot/r);

Out=[P Q R x_2dot y_2dot z_2dot];
end