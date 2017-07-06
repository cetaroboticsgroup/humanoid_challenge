/* Author: Mohammad Manzur Murshid- University of Hartford. 
  Under the supervision of Dr. Kiwon Sohn- University of Hartford.
  2017-2018, All rights resevred. This is a open source code for distribution.
  Any modification of this code must maintain proper rights and must share in the community.
  
  */
  
/* Dynamixel basic Walking motion code . This code is only support Robotis Mini.
Dynamixel ID-7 to 16 actuators motion position.
 */
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
//#define ID_NUM 1
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
/* Control table defines */
#define GOAL_POSITION 30

Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup() {
  
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  //Dxl.jointMode(J_ID_1, J_ID_2, J_ID_3, J_ID_4, J_ID_5, J_ID_6, J_ID_7, J_ID_8, J_ID_9, J_ID_10); //jointMode() is to use position mode
  Dxl.jointMode(J_ID_1);
  Dxl.jointMode(J_ID_2);
  Dxl.jointMode(J_ID_3);
  Dxl.jointMode(J_ID_4);
  Dxl.jointMode(J_ID_5);
  Dxl.jointMode(J_ID_6);
  Dxl.jointMode(J_ID_7);
  Dxl.jointMode(J_ID_8);
  Dxl.jointMode(J_ID_9);
  Dxl.jointMode(J_ID_10);
}

void loop() { 
  
  //Turn dynamixel ID 1 to position 0  
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 512); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 512);
  // Wait for 1 second (1000 milliseconds)
  delay(10);         
  //Turn dynamixel ID 1 to position 300
  //step1
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 480); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 480);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 512);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step2
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 480); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 502);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 650);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 435);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 562);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 512);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step3
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 517); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 535);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 549);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 590);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 461);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 447);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 522);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 522);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 515);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 540);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step4
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 461); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 501);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 582);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 515);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 461);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 506);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 558);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 519);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 478);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 528);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step5
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 494); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 524);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 549);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 480);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 461);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 540);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 545);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 504);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 471);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 495);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step6
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 519); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 543);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 414);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 488);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 543);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 556);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 465);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 536);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 485);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 511);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step7
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 487); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 500);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 408);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 460);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 550);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 556);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 464);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 500);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 516);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step8
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 494); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 514);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 558);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 437);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 461);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 540);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 514);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 478);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 531);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 551);
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  //step9
  Dxl.writeWord(J_ID_1 , GOAL_POSITION, 512); //Compatible with all dynamixel serise
  Dxl.writeWord(J_ID_2 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_3 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_4 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_5 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_6 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_7 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_8 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_9 , GOAL_POSITION, 512);
  Dxl.writeWord(J_ID_10 , GOAL_POSITION, 512);
  // Wait for 1 second (1000 milliseconds)
  delay(1000);       
  
}


