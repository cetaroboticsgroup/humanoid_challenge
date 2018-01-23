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
    SerialUSB.print("Present Speed");// print 
    SerialUSB.println(speed);
    SerialUSB.println((GP-PP));
    
    for ( ID=1; ID <= 16;ID ++){    
        //Fix rotation direction
        if (ID = 1){GP[ID] = -GP[ID];}
        if (ID = 3){GP[ID] = -GP[ID];}
        if (ID = 4){GP[ID] = -GP[ID];}
        if (ID = 5){GP[ID] = -GP[ID];}
        if (ID = 6){GP[ID] = -GP[ID];}
        if (ID = 8){GP[ID] = -GP[ID];}
        if (ID = 10){GP[ID] = -GP[ID];}
        if (ID = 12){GP[ID] = -GP[ID];}
        if (ID = 14){GP[ID] = -GP[ID];}
    }
  }
}

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
