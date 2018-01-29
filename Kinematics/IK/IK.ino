
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
void MJC(int GPI[17],int T){;
  int CP[17];
  int speed[17];
  int GP[17];
  int ID;
  CP[0]=0;
  
//  for ( ID=1; ID <= 16;ID ++){ 
//    if(ID = 1){GP[ID] = -GPI[ID];}
//    else if(ID = 3){GP[ID] = -GPI[ID];}
//    else if(ID = 4){GP[ID] = -GPI[ID];}
//    else if(ID = 5){GP[ID] = -GPI[ID];}
//    else if(ID = 6){GP[ID] = -GPI[ID];}
//    else if(ID = 8){GP[ID] = -GPI[ID];}
//    else if(ID = 10){GP[ID] = -GPI[ID];}
//    else if(ID = 13){GP[ID] = -GPI[ID];}
//    else if(ID = 14){GP[ID] = -GPI[ID];}
//    else {GP[ID] = GPI[ID];}
////    SerialUSB.println(GP[ID]);     
//  }

    GP[1] = -GPI[1];
    GP[2] = GPI[2];
    GP[3] = -GPI[3];
    GP[4] = -GPI[4];
    GP[5] = -GPI[5];
    GP[6] = -GPI[6];
    GP[7] = GPI[7];
    GP[8] = -GPI[8];
    GP[9] = GPI[9];
    GP[10] = -GPI[10];
    GP[11] = GPI[11];
    GP[12] = -GPI[12];
    GP[13] = -GPI[13];
    GP[14] = GPI[14];
    GP[15] = GPI[15];
    GP[16] = GPI[16];   
  
  for ( ID=1; ID <= 16;ID ++){
    
      
    CP[ID] = Dxl.readWord(ID,37);   //readcurrent postion to CP
    
    GP[ID]=d(GP[ID]);
    
    speed[ID] = ((GP[ID]-CP[ID])*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num  
    if(speed[ID]<0){speed[ID]=-speed[ID];}  
    if(speed[ID]>1023){speed[ID]=1023;}
    
    //Fix rotation direction

    
  }
  
  
  
  word SyncPage1[48]=
  { 
  1,GP[1],speed[1],  
  2,GP[2],speed[2],  
  3,GP[3],speed[3],
  4,GP[4],speed[4],
  5,GP[5],speed[5],
  6,GP[6],speed[6],
  7,GP[7],speed[7],
  8,GP[8],speed[8],
  9,GP[9],speed[9],
  10,GP[10],speed[10],
  11,GP[11],speed[11],
  12,GP[12],speed[12],
  13,GP[13],speed[13],
  14,GP[14],speed[14],
  15,GP[15],speed[15],
  16,GP[16],speed[16]};
  
  Dxl.syncWrite(30,2,SyncPage1,48);
  
  delay(1.1*T); // delay time for movment
}


///////////////
///IK PART
///////////////

int deg[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define pi 3.1415926535897932384626433832795

void IRK(int Tx, int Ty, int Tz){
  double Alpha,C,t21,t22;
  double t[17];
  
  C =sq(Tx-15)+sq(Ty+24)+sq(Tz+78);
  
  t[11] = pi - acos(421/420 - C/3780);
  t[15] = atan2((-Ty-24),(-Tz-78));
  Alpha = asin((45*sqrt(1 - sq(C/3780 - 421/420)))/sqrt(sq(Ty +24) + sq(Tz + 78) + sq(Tx-15)));
  t[13] = -atan2(15-Tx, sqrt(sq(Ty + 24) + sq(Tz + 78)))-Alpha;
  t[7] = atan2((Ty+24),-(Tz+78));
  
  t21 = asin(sqrt((1-sq(C/3780-421/420)))*45/sqrt(C));
  t22 =atan2((15-Tx),(sqrt(sq(Ty+24)+sq(Tz+78))+acos(421/420 - C/3780)));
  t[9] = -(t21 +t22);
 
  for (int i = 7; i<=15;i=i+2)
  {
    deg[i]=t[i]*180/pi;
    //SerialUSB.println(deg[i]);
  }  
  
}


void ILK(int Tx, int Ty, int Tz){
  double Alpha,C,t21,t22;
  double t[17];
  
  C =sq(Tx-15)+sq(Ty-24)+sq(Tz+78);
  
  t[12] = pi - acos(421/420 - C/3780);
  t[16] = atan2((-Ty+24),(-Tz-78));
  Alpha = asin((45*sqrt(1 - sq(C/3780 - 421/420)))/sqrt(sq(Ty -24) + sq(Tz + 78) + sq(Tx-15)));
  t[14] = -atan2(15-Tx, sqrt(sq(Ty - 24) + sq(Tz + 78)))-Alpha;
  t[8] = atan2((Ty-24),-(Tz+78));
  
  t21 = asin(sqrt((1-sq(C/3780-421/420)))*45/sqrt(C));
  t22 =atan2((15-Tx),(sqrt(sq(Ty-24)+sq(Tz+78))+acos(421/420 - C/3780)));
  t[10] = -(t21 +t22);

 
  for (int i = 8; i<=16;i=i+2)
  {
    deg[i]=t[i]*180/pi;
//    SerialUSB.println(deg[i]);
  }  
  
}

void setup() {
// Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
    
  IRK(15,-24,-155);
  ILK(15,24,-155);
  
  int GPI[17];
  for (int i = 0; i<=16;i++)
  {
    GPI[i]=0;
  }
  MJC(GPI,500);
  
  delay(1000);
  
   for (int i = 7; i<=16;i++)
  {
    GPI[i]=deg[i];
    SerialUSB.println(deg[i]);
  }  
  MJC(GPI,500);
  
  IRK(15,-14,-155);
  ILK(15,34,-155);
     for (int i = 7; i<=16;i++)
  {
    GPI[i]=deg[i];
    SerialUSB.println(deg[i]);
  }  
  MJC(GPI,500);


}

void loop() {

}

