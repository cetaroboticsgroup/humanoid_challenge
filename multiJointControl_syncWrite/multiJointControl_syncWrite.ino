
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

//Inverse Angle conversion ( 0-1023 to degree)
int Id (float input){
  int output;
  if (input < 512){
    output = (input*300/1024);
    output = output -150;
  }
  else{
    output = (input-512)*300/1024;
  }
 return (output);
}



void MJC(int GP[17],int T){;
  int CP[17];
  int speed[17];
  int ID;
  CP[0]=0;
  
  for ( ID=1; ID <= 16;ID ++){
    GP[ID]=d(GP[ID]);
  }
  
  for ( ID=1; ID <= 16;ID ++){
    CP[ID] = Dxl.readWord(ID,37);   //readcurrent postion to CP
  }
  
  for (ID=1;ID<=16;ID++){
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
}



void loop(){
  
int GP[17];  //Goal Position Array
int T;      // Run Time
int ID;
GP[0]=0;

for (ID=1;ID<=16;ID++){
  GP[ID] = Dxl.readWord(ID,37);  //readcurrent postion to GP, Initialize GP
  GP[ID] = Id(GP[ID]);
  }
  
while(1){
//motion 1
  GP[1] = 0;
  GP[3] = -60;
  GP[5] = 0;
  GP[4] = 60; 
  GP[6] = 0;
  GP[9] = -45;
  GP[10] = 45;
  T = 500;
  MJC(GP,T);
  
//motion 2
  GP[1] = -60;
  GP[2] = -60;
  T = 500;
  MJC(GP,T);

//motion 3
  GP[5] = -90;
  GP[6] = 90;
  T = 500;
  MJC(GP,T);
  
//motion 4
  GP[9] = -80;
  GP[10] = 80;
  T = 1000;
  MJC(GP,T);

//motion 5
  GP[9] = -45;
  GP[10] = 45;
  T = 1000;
  MJC(GP,T);
  
//motion 6
  GP[5] = 0;
  GP[6] = 0;
  T = 500;
  MJC(GP,T);
  
//motion 7  
  GP[1] = 0;
  GP[2] = 0;
  T = 500;
  MJC(GP,T);
}
}
