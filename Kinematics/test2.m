clear all
syms t0 t1 t2 t3 t4 t5 A D B
A = 0;
D = -15;
B = -90;

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
     0 0 1 -30
     0 0 0 1];
 
 T06 = T0*T1*T2*T3*T4*T5;
  
 M = T0^-1* T1^-1*T06;
 E = M(1,4);
 F = M(3,4);
 
t3 = asin((45*(1 - ((Tx - 15)^2/3780 + (Ty + 24)^2/3780 + (Tz + 78)^2/3780 - 421/420)^2)^(1/2))/((Tx - 15)^2 + (Ty + 24)^2 + (Tz + 78)^2)^(1/2))) + atan2(15 - Tx, ((Ty + 24)^2 + (Tz + 78)^2)^(1/2)) + pi/2)