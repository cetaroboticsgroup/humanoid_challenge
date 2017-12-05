
//Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(1);

//Angle conversion (degree to 0-1023)
int d (float input){
  int output;
  if (input < 0){
    output = (input+150)/300*1023;
  }
  else{
    output = input/300*1023+512;
  }
 return (output);
}



void MJC(int GP[17],int T){;
  int CP[17];
  int speed[17];
  int ID;
  
  for ( ID=0; ID <= 16;ID ++){
    
    GP[ID]=d(GP[ID]);

    CP[ID] = Dxl.readWord(ID,37);   //readcurrent postion to CP

    speed[ID] = ((GP[ID]-CP[ID])*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num  
    if(speed[ID]<0){speed[ID]=-speed[ID];}  
    if(speed[ID]>1023){speed[ID]=1023;}
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
  
  delay(1.1*T); // move delay time from SJC to here
}

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
  
  int GP[17] = {0,0,0,-73.24,73.24,0,0,0,0,-26.37,26.37,29.3,-29.3,13.18,-13.18,0,0};
    MJC(GP,500);
}

void loop(){
  
int T;      // Run Time
int I;

for( I=0; I <= 2;I ++){

  //motion 2
    int GP2[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
    T = 70;
    MJC(GP2,T);
    delay(15);
    
  //motion3
    int GP3[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
    T = 75;
    MJC(GP3,T);
    
  //motion4
    int GP4[17] = {0,29.3,14.65,-73.24,73.24,0,0,0,0,-20.51,32.23,29.3,-29.3,21.97,-10.25,0,0};
    T = 75;
    MJC(GP4,T);
  
  //motion 5
    int GP5[17] = {0,-0.29,-0.29,-73.54,72.95,-0.29,-0.29,-0.29,-0.29,-20.8,31.93,29,-29.59,21.68,-10.55,-12.01,-3.22};
    T = 75;
    MJC(GP5,T);
    delay(15);
  
  //motion 6
    int GP6[17] = {0,-9.08,-9.08,-73.54,72.95,-0.29,-0.29,-3.22,2.64,-41.31,26.07,58.3,-29.59,30.47,-16.41,-9.08,-3.22};
    T = 75;
    MJC(GP6,T);
    
  //motion 7
    int GP7[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
    T = 140;
    MJC(GP7,T);
}
  
////motion 8
//  int GP8[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
//  T = 70;
//  MJC(GP8,T);
//  
////motion 9
//  int GP9[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
//  T = 78;
//  MJC(GP9,T);
//  delay(15);
//
////motion 10
//  int GP10[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
//  T = 70;
//  MJC(GP10,T);
}
