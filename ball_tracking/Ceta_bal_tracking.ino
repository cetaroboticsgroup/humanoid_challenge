/*Author : Manzur Murhsid
University of Hartford, 2017-2018*/


/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM 1
/* Control table defines */
#define GOAL_POSITION 30

Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup(){
SerialUSB.begin();

 // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM); //jointMode() is to use position mode
}

byte temp = 0;  

void loop(){
  
if ( SerialUSB.available() ){
temp = SerialUSB.read();
char a = (char)temp;
//int b = a+1;
if(a == '1'){
 Dxl.writeWord(ID_NUM, GOAL_POSITION, 512); 
SerialUSB.print((char)a);}
else if((char)a == '0'){
SerialUSB.print((char)a);
Dxl.writeWord(ID_NUM, GOAL_POSITION, 300);
}
else{
Dxl.writeWord(ID_NUM, GOAL_POSITION, 0);
delay(1000);}

}

}
