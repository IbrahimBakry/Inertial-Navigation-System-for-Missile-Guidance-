function [out]=BlockB(in)
%% [Block B]

Q1=in(1);
Q2=in(2);
Q3=in(3);
Q4=in(4);

B1=Q1^2+Q2^2-Q3^2-Q4^2;
B2=2*(Q2*Q3-Q1*Q4);
B3=2*(Q2*Q4+Q1*Q3);

B4=2*(Q2*Q3+Q1*Q4);
B5=Q1^2+Q3^2-Q2^2-Q4^2;
B6=2*(Q4*Q3-Q1*Q2);

B7=2*(Q2*Q4-Q1*Q3);
B8=2*(Q3*Q4+Q1*Q2);
B9=Q1^2+Q4^2-Q2^2-Q3^2;

B=[B1 B2 B3 ; B4 B5 B6 ; B7 B8 B9];

out=B;

end