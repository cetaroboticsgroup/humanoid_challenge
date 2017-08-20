
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
  //int isMoving = Dxl.readByte(ID, 49);
  if(1){// isMoving == 0 ){  // move or not
    int speed;
    int PP = Dxl.readWord(ID,37); // PP:Present Postion
      speed = ((GP-PP)*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num  
    if(speed<0){speed=-speed;}  
    if(speed>1023){speed=1023;}
  
    Dxl.writeWord(ID,32,speed) ; // wirte word to motor
    Dxl.writeWord(ID,30,GP) ;
    
  }
}

void MJC(int GP[17],int T){
  int CP[17];
  int ID;
  CP[0]=0;
  
  //for ( ID=1; ID <= 16;ID ++){
    //CP[ID] = Dxl.readWord(ID,37);   //readcurrent postion to CP
 // }

  for (ID=1;ID<=16;ID++){
    int D;
    //D = GP[ID] - CP[ID];
    //if (abs(D)>5){    // Eliminate sensor errors
      SJC(ID,GP[ID],T);
      //}
  }
  
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
  }
  
//motion 1
  GP[1] = d(0);
  GP[3] = d(-60);
  GP[5] = d(0);
  GP[4] = d(60); 
  GP[6] = d(0);
  GP[9] = d(-45);
  GP[10] = d(45);
  GP[11] = 952;
  GP[12] = 69;
  T = 500;
  MJC(GP,T);
  
//motion 2
  GP[1] = d(-60);
  GP[2] = d(-60);
  T = 500;
  MJC(GP,T);

//motion 3
  GP[5] = d(-90);
  GP[6] = d(90);
  T = 500;
  MJC(GP,T);
  
//motion 4
  GP[9] = d(-80);
  GP[10] = d(80);
  T = 1000;
  MJC(GP,T);

//motion 5
  GP[9] = d(-45);
  GP[10] = d(45);
  T = 1000;
  MJC(GP,T);
  
//motion 6
  GP[5] = d(0);
  GP[6] = d(0);
  T = 500;
  MJC(GP,T);
  
//motion 7  
  GP[1] = d(0);
  GP[2] = d(0);
  T = 500;
  MJC(GP,T);

  
}
