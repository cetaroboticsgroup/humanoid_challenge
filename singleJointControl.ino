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
void SJC(int ID,int GP,int T)//ID num, Goal postion, Time(ms)
{
  int isMoving = Dxl.readByte(ID, 49);
  if( isMoving == 0 ){  // move or not
    int PP = Dxl.readWord(ID,37); // present postion
    int speed;
    if(GP>=GP){
      speed = (GP-PP)*1000/T/2.2867; //unit is about 0.111rpm = 0.67deg/s = 2.2867/s 
    }
    else{
      speed = (PP-GP)*1000/T/2.2867;
      speed = speed +1023;}
    Dxl.writeWord(ID,32,speed) ; // wirte word to motor
    Dxl.writeWord(ID,30,GP) ; 
    T = T +100;
    delay(T);
    SerialUSB.print("Present speed");
    SerialUSB.println(speed);
  }
}



void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}



void loop(){
SJC(5,d(-90),100); // call singel joint control function :ID,angle,time
SJC(5,d(0),300);
}
