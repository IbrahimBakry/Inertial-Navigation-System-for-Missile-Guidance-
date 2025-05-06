function Q_dot = Qdot_fun(IN)

% persistent Q
% LL = isempty(Q);
% if LL==0
%     Q = [1 0 0 0];
% end

p = IN(1);
q = IN(2);
r = IN(3);
Q = [IN(4) IN(5) IN(6) IN(7)]';



Q_mat = 0.5*[0   -p   -q   -r;
             p    0    r   -q;
             q   -r    0   -p;
             r    q   -p   0];
Q_dot = Q_mat*Q;

% a=0;
% b=10;
% n=1000;
% h=(b-a)/n;
% 
% i=0;
% for t = a:h:b
%     i=i+1;
%     Q = Q + h*Q_dot 
% end
% 
% Out = Q; 
end