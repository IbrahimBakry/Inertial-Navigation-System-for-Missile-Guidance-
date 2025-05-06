function [out]=absVelocity(in)
%% Summing Velocities;

VA=[in(1);in(2);in(3)];
VF=[in(4);in(5);in(6)];

VX=VA(1)+VF(1);
VY=VA(2)+VF(2);
VZ=VA(3)+VF(3);

% Absolute Velocity;
out=[VX VY VZ];


end