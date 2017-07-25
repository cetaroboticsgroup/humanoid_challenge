/* Dynamixel Basic Position Control 


/* Dynamixel ID defines */
#define ID_NUM 1
/* Control table defines */
#define GOAL_POSITION 30

/* Serial device defines for dxl bus */
Dynamixel Dxl(1); //Dynamixel on Serial1(USART1)  <-OpenCM9.04

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM); //jointMode() is to use position mode
}

void loop() {
  /*ID 1 dynamixel moves to position 0 with velocity 100 */
  Dxl.setPosition(ID_NUM,0,100);
  delay(1000);// it has more delay time for slow movement
  /*ID 1 dynamixel moves to position 500 with velocity 300 */
  Dxl.setPosition(ID_NUM,500,300);
  delay(500);
}

