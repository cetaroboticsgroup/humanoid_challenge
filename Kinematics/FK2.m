clear all
syms t0 t1 t2 t3 t4 t5

A = 15;D = -24;B = -78;

T0 = [cos(t0) -sin(t0) 0 A
      sin(t0) cos(t0) 0 D
      0 0 1 B
      0 0 0 1];

T1 = [1 0 0 0
      0 cos(t1) -sin(t1) 0
      0 sin(t1) cos(t1) 0
      0 0 0 1];

T2 =[cos(t2) 0 sin(t2) 0
     0 1 0 0
     -sin(t2) 0 cos(t2) 0
     0 0 0 1];

T3 =[cos(t3) 0 sin(t3) 0
     0 1 0 0
     -sin(t3) 0 cos(t3) -45
     0 0 0 1];

 T4 =[cos(t4) 0 sin(t4) 0
     0 1 0 0
     -sin(t4) 0 cos(t4) -42
     0 0 0 1];
 
 T5 = [1 0 0 0
    0 cos(t5) -sin(t5) 0
    0 sin(t5) cos(t5) 0
    0 0 0 1];

T6 = [1 0 0 0
     0 1 0 0
     0 0 1 -25
     0 0 0 1];
 
 T06 = T0*T1*T2*T3*T4*T5;

%  t0=0;t1=0;t2=0;t3=0;t4=0;t5=0;
t0=0;
t1=0;
t2=-27.0627;
t3=30.4390;
t4=-3.3762 ;
t5=0;
t0 = degtorad(t0);t1 = degtorad(t1);t2 = degtorad(t2);t3 = degtorad(t3);t4 = degtorad(t4);t5 = degtorad(t5);

T = subs(T06);
round(T)
 
% t0=0;t1=0;t3=pi/3;

% M = inv(T0)* inv(T1)*T;
%  E = M(1,4);
%  F = M(3,4);
%  
%  theart3 = atan2(-(F*(42*cos(t3)+45)+E*42*sin(t3)),E*(42*cos(t3)+45)-F*42*sin(t3))
