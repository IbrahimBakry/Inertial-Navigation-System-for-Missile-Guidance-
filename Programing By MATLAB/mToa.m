function [out]=mToa(in)
%% convert from movable frame to inertial frame;

B=[in(1) in(2) in(3);
    in(4) in(5) in(6);
    in(7) in(8) in(9)];

VXA=in(10);
VYA=in(11);
VZA=in(12);

VA=B*[VXA;VYA;VZA];
out=VA;

end