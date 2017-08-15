
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
void SJC(int ID,float GP,int T)//ID num, Goal postion, Time(ms)
{
  GP = d(GP);
  if(1){// isMoving == 0 ){  // move or not
    int speed;
    int PP = Dxl.readWord(ID,37); // PP:Present Postion
      speed = ((GP-PP)*1000/T)/0.67; //unit is about 0.111rpm = 0.67deg/s 
      if(speed>1023){speed=1023;}
      if(speed<0){speed=-speed;}
  
    Dxl.writeWord(ID,32,speed) ; // wirte word to motor
    Dxl.writeWord(ID,30,GP) ;
    
  }
}

void MJC(float GP[17],int T){
  int CP[17];
  int ID;
  CP[0]=0;
  
  for ( ID=1; ID <= 16;ID ++){
    CP[ID] = Dxl.readWord(ID,37);   //readcurrent postion to CP
  }

  for (ID=1;ID<=16;ID++){
    int D;
    D = GP[ID] - CP[ID];
    if (abs(D)>10){
      SJC(ID,GP[ID],T);
      }
  }
  
  delay(1.1*T); 
}

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}



void loop(){
  
float GP[17];  //Goal Position Array
int T;      // Run Time
int ID;
GP[0]=0;
for (ID=1;ID<=16;ID++){
  GP[ID] = Dxl.readWord(ID,37);  //readcurrent postion to GP, Initialize GP
  }
  
//motion 1
  GP[11]=29.3;
  GP[12]=-29.3;
  T = 1000;
  MJC(GP,T);
  
//motion 2
  float GP2[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
  T = 140;
  MJC(GP2,T);
  
//motion3
  float GP3[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
  T = 150;
  MJC(GP3,T);
  
//motion4
  float GP4[17] = {0,29.3,14.65,-73.24,73.24,0,0,0,0,-20.51,32.23,29.3,-29.3,21.97,-10.25,0,0};
  T = 140;
  MJC(GP4,T);

//motion 5
  float GP5[17] = {0,-0.29,-0.29,-73.54,72.95,-0.29,-0.29,-0.29,-0.29,-20.8,31.93,29,-29.59,21.68,-10.55,-12.01,-3.22};
  T = 150;
  MJC(GP5,T);

//motion 6
  float GP6[17] = {0,-9.08,-9.08,-73.54,72.95,-0.29,-0.29,-3.22,2.64,-41.31,26.07,58.3,-29.59,30.47,-16.41,-9.08,-3.22};
  T = 150;
  MJC(GP6,T);
  
//motion 7
  float GP7[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
  T = 140;
  MJC(GP7,T);
  
//motion 8
  float GP8[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
  T = 140;
  MJC(GP8,T);
  
//motion 9
  float GP9[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
  T = 150;
  MJC(GP9,T);

//motion 10
  float GP10[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
  T = 150;
  MJC(GP10,T);
}
