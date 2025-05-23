function Phi = Gravity_Model_Fun(R)

a0 = -3.986329e14;  % [m^3/s^2]
a2 = -6.66425e10; %[m^2]
a4 = 2.5023e21; % [m^4]
r  = 64e5; %[m]

Phi_x = a0*(R(1)/r^3)*(1 + (a2/r^2)*((5*R(3)^2/r^2)-3) + (a4/r^4)*((63*R(3)^4/r^4)-(42*R(3)^2/r^2)+3));
Phi_y = a0*(R(2)/r^3)*(1 + (a2/r^2)*((5*R(3)^2/r^2)-3) + (a4/r^4)*((63*R(3)^4/r^4)-(42*R(3)^2/r^2)+3));
Phi_z = a0*(R(3)/r^3)*(1 + (a2/r^2)*((5*R(3)^2/r^2)-3) + (a4/r^4)*((63*R(3)^4/r^4)-(70*R(3)^2/r^2)+15));

Phi = [Phi_x Phi_y Phi_z];
end
