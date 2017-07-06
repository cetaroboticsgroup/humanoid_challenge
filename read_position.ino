/* Author: Mohammad Manzur Murshid- University of Hartford. 
  Under the supervision of Dr. Kiwon Sohn- University of Hartford.
  2017-2018, All rights resevred. This is a open source code for distribution.
  Any modification of this code must maintain proper rights and must share in the community.
  
  */
  
/* Dynamixel position monitor for motion planning. This code is only support Robotis Mini.
Dynamixel ID-7 to 16 actuators motion position detector
 */
 /* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define J_ID_1 7
#define J_ID_2 8
#define J_ID_3 9
#define J_ID_4 10
#define J_ID_5 11
#define J_ID_6 12
#define J_ID_7 13
#define J_ID_8 14
#define J_ID_9 15
#define J_ID_10 16

#define PRESENT_POS 54
 
Dynamixel Dxl(DXL_BUS_SERIAL1); 
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
//Dynamixel Dxl(DXL_BUS_SERIAL1);
 
void setup() {
  // Initialize the dynamixel bus:
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps  
  Dxl.begin(3);
  Dxl.maxTorque(J_ID_1 ,1); // it has maxtorque for weak movement  
  //Dxl.jointMode(J_ID_2, 2); //jointMode() is to use position mode
  Dxl.maxTorque(J_ID_2, 1);
  Dxl.maxTorque(J_ID_3, 1);
  Dxl.maxTorque(J_ID_4, 1);
  Dxl.maxTorque(J_ID_5, 1);
  Dxl.maxTorque(J_ID_6, 1);
  Dxl.maxTorque(J_ID_7, 1);
  Dxl.maxTorque(J_ID_8, 1);
  Dxl.maxTorque(J_ID_9, 1);
  Dxl.maxTorque(J_ID_10, 1);
  
}
 
void loop() {
  int pos,pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, pos10 ;
  // Wait for 20 milliseconds
  delay(20);
 
  pos = Dxl.readWord(J_ID_1, PRESENT_POS); // Read present position
  pos2 = Dxl.readWord(J_ID_2, PRESENT_POS); // Read present position
  pos3= Dxl.readWord(J_ID_3, PRESENT_POS); // Read present position
  pos4 = Dxl.readWord(J_ID_4, PRESENT_POS); // Read present position
  pos5 = Dxl.readWord(J_ID_5, PRESENT_POS); // Read present position
  pos6 = Dxl.readWord(J_ID_6, PRESENT_POS); // Read present position
  pos7 = Dxl.readWord(J_ID_7, PRESENT_POS); // Read present position
  pos8 = Dxl.readWord(J_ID_8, PRESENT_POS); // Read present position
  pos9 = Dxl.readWord(J_ID_9, PRESENT_POS); // Read present position
  pos10 = Dxl.readWord(J_ID_10, PRESENT_POS); // Read present position
  
  
  SerialUSB.print("PP_7: "); //PP = Present position of ID-7
    SerialUSB.print(pos);
    SerialUSB.print("PP_8: ");
    SerialUSB.print(pos2);
    SerialUSB.print("PP_9: ");
    SerialUSB.print(pos3);
    SerialUSB.print("PP_10: ");
    SerialUSB.print(pos4);
    SerialUSB.print("PP_11: ");
    SerialUSB.print(pos5);
    SerialUSB.print("PP_12: ");
    SerialUSB.print(pos6);
    SerialUSB.print("PP_13: ");
    SerialUSB.print(pos7);
    SerialUSB.print("PP_14: ");
    SerialUSB.print(pos8);
    SerialUSB.print("PP_15: ");
    SerialUSB.print(pos9);
    SerialUSB.print("PP_16: ");
    SerialUSB.println(pos10);
//  SerialUSB.println(pos, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, pos10);
// 
 
}
