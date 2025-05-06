function [ out ] = BlockVA( in )
%% Calculating VA;
% from the Equation: dotVA_m=A_m - Omega_m/a * VA;

p=in(1);
q=in(2);
r=in(3);

AX=in(4);
AY=in(5);
AZ=in(6);

VAX=in(7);
VAY=in(8);
VAZ=in(9);

% Body Anguler Matrix Velocity;
Omega=[0 -r q ;
       -r 0 -p ;
        q -p 0];

% Velocities That Come From A_m;
VA=[VAX;VAY;VAZ];

% nondimentional Forces that come from Accelrometer;
A_m=[AX;AY;AZ];

dotVA_m=A_m - Omega*VA;

out=dotVA_m;


end

