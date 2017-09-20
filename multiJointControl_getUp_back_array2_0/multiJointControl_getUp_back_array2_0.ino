
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



void MJC(int GP[17],int T){;
  int CP[16];
  int speed[16];
  int ID;
  
  for ( ID=0; ID <= 15;ID ++){
    GP[ID]=d(GP[ID]);
  }
  
  for ( ID=0; ID <= 15;ID ++){
    CP[ID] = Dxl.readWord(ID+1,37);   //readcurrent postion to CP
  }
  
  for (ID=0;ID<=15;ID++){
    speed[ID] = ((GP[ID]-CP[ID])*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num  
    if(speed[ID]<0){speed[ID]=-speed[ID];}  
    if(speed[ID]>1023){speed[ID]=1023;}
  }
  
  word SyncPage1[48]=
  { 
  1,GP[0],speed[0],  
  2,GP[1],speed[1],  
  3,GP[2],speed[2],
  4,GP[3],speed[3],
  5,GP[4],speed[4],
  6,GP[5],speed[5],
  7,GP[6],speed[6],
  8,GP[7],speed[7],
  9,GP[8],speed[8],
  10,GP[9],speed[9],
  11,GP[10],speed[10],
  12,GP[11],speed[11],
  13,GP[12],speed[12],
  14,GP[13],speed[13],
  15,GP[14],speed[14],
  16,GP[15],speed[15]};
  
  Dxl.syncWrite(30,2,SyncPage1,48);
  
  delay(1.1*T); // move delay time from SJC to here
}

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
  
    
int GP[16];  //Goal Position Array
int T ;      // Run Time
int ID;
for (ID=0;ID<=15;ID++){
  //GP[ID] = Dxl.readWord(ID,37);  //readcurrent postion to GP, Initialize GP
  GP[ID]=0;
  }
  
  
//  //Part 1
//    int GP1[17] = {0,-78.52,78.52,-80.86,80.86,-10.84,10.84,0,0,35.16,-35.16,62.4,-62.4,78.22,-78.22,0,0};
//    T = 1000;
//    MJC(GP1,T);
//    
//    int GP2[17] = {0,-78.52,78.52,-80.86,80.86,-10.84,10.84,0,0,35.16,-35.16,77.05,-77.05,60.64,-60.64,0,0};
//    T = 400;
//    MJC(GP2,T);
//    
//    int GP3[17] = {0,-52.44,52.44,-2.64,2.64,-74.71,74.71,0,0,-73.54,73.54,20.95,-20.95,-43.9,43.9,0,0};
//    T = 1000;
//    MJC(GP3,T);
//  
//    int GP4[17] = {0,150,-150,-50.1,50.1,-104.3,104.3,0,0,-73.54,73.54,-3.81,3.81,-13.48,13.48,0,0};
//    T = 1000;
//    MJC(GP4,T);
//    
//   //Part 2
//    int GP5[17] = {0,120.7,-120.7,-50.1,50.1,-104.3,104.3,0,0,-99.02,99.02,-3.81,3.81,-13.48,13.48,0,0};
//    T = 1000;
//    MJC(GP5,T);
//    
//    int GP6[17] = {0,150,-150,-50.1,50.1,-104.3,104.3,0,0,-58.89,58.89,-3.81,3.81,-13.48,13.48,0,0};
//    T = 1000;
//    MJC(GP6,T);
    
    //Part 3
    int GP7[16] = {-114.55,114.55,0.88,-0.88,-7.91,7.91,0,0,-39.55,39.55,-7.03,7.03,-14.65,14.65,0,0};
    T = 400;
    MJC(GP7,T);
    
    int GP8[16] = {-110.45,110.45,-16.7,16.7,-109.28,109.28,0,0,-39.55,39.55,-7.03,7.03,-14.65,14.65,0,0};
    T = 100;
    MJC(GP8,T);
    delay(250);
    
    int GP9[16] = {-70.52,70.52,-86.86,86.86,-0.84,0.84,0,0,35.16,-35.16,77.05,-77.05,60.64,-60.64,0,0};
    T = 400;
    MJC(GP9,T);
    delay(300);
    
    int GP10[16] = {-78.52,78.52,-80.86,80.86,-10.84,10.84,0,0,35.16,-35.16,62.4,-62.4,78.22,-78.22,0,0};
    T = 1000;
    MJC(GP10,T);
    delay(300);
    
    int GP11[16] = {0,0,-73.24,73.24,0,0,0,0,-26.37,26.37,29.3,-29.3,13.18,-13.18,0,0};
    T = 800;
    MJC(GP11,T);  
    
    
}

void loop(){

}
