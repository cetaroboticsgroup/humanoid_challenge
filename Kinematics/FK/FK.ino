
double Tx,Ty,Tz;
double t1,t2,t3,t4,t5,Alpha,C,t21,t22;
#define pi 3.1415926535897932384626433832795

void IK(){
  Tx = 60; Ty = -24;Tz = -120;
  
  C =sq(Tx-15)+sq(Ty+24)+sq(Tz+78);
  
  t3 = pi - acos(421/420 - C/3780);
  t5 = atan2((-Ty-24),(-Tz-78));
  Alpha = asin((45*sqrt(1 - sq(C/3780 - 421/420)))/sqrt(sq(Ty +24) + sq(Tz + 78) + sq(Tx-15)));
  t4 = -atan2(15-Tx, sqrt(sq(Ty + 24) + sq(Tz + 78)))-Alpha;
  t1 = atan2((Ty+24),-(Tz+78));
  
  t21 = asin(sqrt((1-sq(C/3780-421/420)))*45/sqrt(C));
  t22 =atan2((15-Tx),(sqrt(sq(Ty+24)+sq(Tz+78))))+acos(421/420 - C/3780);
  t2 = t21 +t22;
  
}

void setup() {

}


void loop() {
 IK();
  
  SerialUSB.println("T= "); 
  SerialUSB.println(t1);
  SerialUSB.println(t2);
  SerialUSB.println(t3);
  SerialUSB.println(t4);
  SerialUSB.println(t5);
  
//  SerialUSB.println(t21);
//  SerialUSB.println(t22);
  delay(3000);
}

