clc
clear all

Q01=0;
Q02=0;
Q03=0;

i=0;
for Q04 = -2:0.1:0
    
    sim('GP')
    i = i + 1;
    if RF(end,1) == RI(end,1)&& RF(end,2) == RI(end,2) && RF(end,3) == RI(end,3)
        break
        disp(Q04)
    end
    MAT(i,:)=RF(end,:)
%     if RF(end,:)- MAT(i,:)==0
%     Q02 = 1;
%     continue
%     end
%        
        
end


