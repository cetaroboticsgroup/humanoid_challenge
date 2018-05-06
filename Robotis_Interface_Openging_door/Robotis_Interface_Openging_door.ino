Dynamixel Dxl(1); 

void setup() {
 SerialUSB.begin();
   // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
}

void loop() {
  while (SerialUSB.available())
  {
    // Wait for a start byte, "W" for write or "R" for read. 
    char cmd = SerialUSB.read();
    
    switch (cmd)
    {
      
      case '1':
          left();
        break;
        
       case '2':
         right();
         
       case '3':
         float battery = batterylevel();
         SerialUSB.print("Battery Voltage = ");
         SerialUSB.println(battery);
         if (battery < 6){SerialUSB.println("Voltage is too low.");}
         break;
         
//       default:
//         SerialUSB.println("Error");
//         break;
    }    
 
  }
}

//void processWrite(byte cmd, byte id)
//{
//          switch (cmd)
//        {
//          case '1':
//
//            break; 
//          case '2':
// 
//            break; 
//          case 'w':
//            int add, val; 
//            if (!(readInt(&add) && readInt(&val))) break; 
//            Dxl.writeWord(id, add, val); 
//            break; 
//           default:
//             SerialUSB.println('Error')
//        }
//}

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

void left(){
 SJC(1,90,500);
}

void right(){
 SJC(2,-90,500);
}

int batterylevel(){
  float B = Dxl.readByte(1,45); // read the ID1 motor Voltage
  B = B/10;
  return (B);
}
