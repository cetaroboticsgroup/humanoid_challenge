Dynamixel Dxl(1);
void setup() {
  // put your setup code here, to run once:
  Dxl.begin(3);
  Dxl.writeByte(17, 11, 1);  //joinMode() is to use position mode
  Dxl.writeWord(17, 6, 200); //CW Limit
  Dxl.writeWord(17, 8, 823); //CCW Limit
}


void loop() {
  //inital the goal speed
  Dxl.writeWord(17,30, 0);
  
  while (SerialUSB.available())
  {
     char x = SerialUSB.read();
     
     if(x > 127){
       int f = (x -127)*2.5;
       Dxl.writeWord(17,32, f);
       SerialUSB.println(f);
     }
     else
     {
       int f = ((127-x)*2.5+1023);    
       Dxl.writeWord(17,32, f);
       SerialUSB.println(f);
       }
     }
     delay(100);
}
