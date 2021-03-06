//Single Joint Movement

//Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(1);


void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}



void loop(){
SJC(3,0,1000); // call singel joint control function :ID,angle,time(ms)
SJC(4,0,1000);
SJC(3,-80,500);
SJC(4,80,500);
}


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
//    SerialUSB.print("Present Speed");// print 
//    SerialUSB.println(speed);
//    SerialUSB.println((GP-PP));
    
  }
}
