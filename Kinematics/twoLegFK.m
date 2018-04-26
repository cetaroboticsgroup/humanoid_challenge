clear all
% syms t0 t1 t2 t3 t4 t5

t = [-0.29 -0.29 -73.54 72.95 -0.29 -0.29 -0.29 -0.29 -20.8 31.93 29 -29.59 21.68 -10.55 -12.01 -3.22];

tr0 = 0;t7 = degtorad(t(7));t9 = degtorad(t(9));t11 = degtorad(t(11));t13 = degtorad(-t(13));t15 = degtorad(-t(15));
tl0 = 0;t8 = degtorad(t(8));t10 = degtorad(-t(10));t12 = degtorad(-t(12));t14 = degtorad(t(14));t16 = degtorad(-t(16));

%Right Leg Fk
A = 15;D = -24;B = -78;

T0 = [cos(tr0) -sin(tr0) 0 A
      sin(tr0) cos(tr0) 0 D
      0 0 1 B
      0 0 0 1];

T1 = [1 0 0 0
      0 cos(t7) -sin(t7) 0
      0 sin(t7) cos(t7) 0
      0 0 0 1];

T2 =[cos(t9) 0 sin(t9) 0
     0 1 0 0
     -sin(t9) 0 cos(t9) 0
     0 0 0 1];

T3 =[cos(t11) 0 sin(t11) 0
     0 1 0 0
     -sin(t11) 0 cos(t11) -45
     0 0 0 1];

 T4 =[cos(t13) 0 sin(t13) 0
     0 1 0 0
     -sin(t13) 0 cos(t13) -42
     0 0 0 1];
 
 T5 = [1 0 0 0
    0 cos(t15) -sin(t15) 0
    0 sin(t15) cos(t15) 0
    0 0 0 1];

T6 = [1 0 0 0
     0 1 0 0
     0 0 1 -25
     0 0 0 1];
 
 T06 = T0*T1*T2*T3*T4*T5;

Tr = round(T06)

%left leg FK

TL0 = [cos(tl0) -sin(tl0) 0 A
      sin(tl0) cos(tl0) 0 -D
      0 0 1 B
      0 0 0 1];

TL1 = [1 0 0 0
      0 cos(t8) -sin(t8) 0
      0 sin(t8) cos(t8) 0
      0 0 0 1];

TL2 =[cos(t10) 0 sin(t10) 0
     0 1 0 0
     -sin(t10) 0 cos(t10) 0
     0 0 0 1];

TL3 =[cos(t12) 0 sin(t12) 0
     0 1 0 0
     -sin(t12) 0 cos(t12) -45
     0 0 0 1];

 TL4 =[cos(t14) 0 sin(t14) 0
     0 1 0 0
     -sin(t14) 0 cos(t14) -42
     0 0 0 1];
 
 TL5 = [1 0 0 0
    0 cos(t16) -sin(t16) 0
    0 sin(t16) cos(t16) 0
    0 0 0 1];

TL6 = [1 0 0 0
     0 1 0 0
     0 0 1 -25
     0 0 0 1];
 
TL06 = TL0*TL1*TL2*TL3*TL4*TL5;

TL = round(TL06)


 
