//Single Joint Movement

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
void SJC(int ID,int GP,int T)//ID num, Goal postion, Time
{
  int isMoving = Dxl.readByte(ID, 49);
  if( isMoving == 0 ){  // move or not
    int NP = Dxl.readWord(ID,37); // now postion
    int speed = (NP-GP)/T;  //caculate speed
    Dxl.setPosition(ID,GP,speed); // wirte word to motor
    delay(T);
  }
}



void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}



void loop(){
SJC(5,d(-90),600); // call singel joint control function :ID,angle,time
SJC(5,d(60),300);
}
