

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
    
    if(ID = 1){GP[ID] = -GP[ID];}
    if(ID = 3){GP[ID] = -GP[ID];}
    if(ID = 4){GP[ID] = -GP[ID];}
    if(ID = 5){GP[ID] = -GP[ID];}
    if(ID = 6){GP[ID] = -GP[ID];}
    if(ID = 8){GP[ID] = -GP[ID];}
    if(ID = 10){GP[ID] = -GP[ID];}
    if(ID = 12){GP[ID] = -GP[ID];}
    if(ID = 14){GP[ID] = -GP[ID];}
      
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
  GP[7] = 30;
  GP[9] = 30;
  GP[11] = 30;
  GP[13] = 30; 
  GP[15] = 30;
  
  GP[8] = 30;
  GP[10] = 30;
  GP[12] = 30;
  GP[14] = 30; 
  GP[16] = 30;
  T = 500;
  MJC(GP,T);
}
}
