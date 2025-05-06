function [out]=BlockPhi(in)
%% Calculating Gravity Field;

% Constants;
A0=-3.986329e14;  % [m^3/s^2] 
A2=-6.66425e10;      % [m^2]
A4=2.5023e4;      % [m^4]
% R=6400;            % [km]
R=64e5;           % [m]

x=in(1);
y=in(2);
z=in(3);

phix=A0*(x/R^3)*(1+(A2/R^2)*((52^2/R^2)-3)+(A4/R^4)*((632^4/R^4)-(422^2/R^2)+3));
phiy=A0*(y/R^3)*(1+(A2/R^2)*((52^2/R^2)-3)+(A4/R^4)*((632^4/R^4)-(422^2/R^2)+3));
phiz=A0*(z/R^3)*(1+(A2/R^2)*((52^2/R^2)-3)+(A4/R^4)*((632^4/R^4)-(702^2/R^2)+15));

out=[phix phiy phiz];
end
