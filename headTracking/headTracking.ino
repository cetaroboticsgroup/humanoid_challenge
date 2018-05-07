Dynamixel Dxl(1);
void setup() {
  // put your setup code here, to run once:
  Dxl.begin(3);
  Dxl.wheelMode(17); //joinMode() is to use position mode
}

void loop() {
  // put your main code here, to run repeatedly: 
  while (SerialUSB.available())
  {
     char x = SerialUSB.read();
     
     if(x > 127){
       x = (x -127)*3;
       Dxl.goalSpeed(17, x);
     }
     else
     {
       x = ((127-x)*3+1023);    
       Dxl.goalSpeed(17, x);
       }
     }
     delay(100);
}
