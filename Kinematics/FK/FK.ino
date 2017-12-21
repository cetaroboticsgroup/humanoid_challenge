
//Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(1);

//Angle conversion (degree to 0-1023)
int d (float input){
  int output;
  if (input < 0){
    output = (input+150)/300*1024;
  }
  else{
    output = input/300*1023+512;
  }
 return (output);
}


//Single Joint Control function
void SJC(int ID,int GP,int T)//ID num, Goal postion, Time(ms)
{
  GP = d(GP);
  if(1){// isMoving == 0 ){  // move or not
    int speed;
    int PP = Dxl.readWord(ID,37); // PP:Present Postion
      speed = ((GP-PP)*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num 
      if(speed<0){speed=-speed;}
      if(speed>1023){speed=1023;}
  
    Dxl.writeWord(ID,32,speed) ; // wirte word to motor
    Dxl.writeWord(ID,30,GP) ;
    delay(1.1*T); 
    SerialUSB.print("Present Speed");// print 
    SerialUSB.println(speed);
    SerialUSB.println((GP-PP));
  }
}

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int deg[5];

#define pi 3.1415926535897932384626433832795

void IK(){
  double Tx,Ty,Tz;
  double Alpha,C,t21,t22;
  double t[5];
  
  Tx = 60; Ty = -24;Tz = -120; // postion input
  
  C =sq(Tx-15)+sq(Ty+24)+sq(Tz+78);
  
  t[3] = pi - acos(421/420 - C/3780);
  t[5] = atan2((-Ty-24),(-Tz-78));
  Alpha = asin((45*sqrt(1 - sq(C/3780 - 421/420)))/sqrt(sq(Ty +24) + sq(Tz + 78) + sq(Tx-15)));
  t[4] = -atan2(15-Tx, sqrt(sq(Ty + 24) + sq(Tz + 78)))-Alpha;
  t[1] = atan2((Ty+24),-(Tz+78));
  
  t21 = asin(sqrt((1-sq(C/3780-421/420)))*45/sqrt(C));
  t22 =atan2((15-Tx),(sqrt(sq(Ty+24)+sq(Tz+78))))+acos(421/420 - C/3780);
  t[2] = t21 +t22;
  
  for (int i = 0; i<=5;i++)
  {
    deg[i]=t[i]/pi*180;
  }
  
}

void loop() {
  IK();
  
  
  
  SJC(7,deg[1],1000); 
  SJC(9,deg[2],1000);
  SJC(11,deg[3],500);
  SJC(13,deg[4],500);
  SJC(15,deg[5],500);
}

