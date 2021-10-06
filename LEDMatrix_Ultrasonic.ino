#include <LedControl.h>

//Ultrasonic Sensors
#define trigPinL 2
#define echoPinL 3
#define trigPinF 4
#define echoPinF 5
#define trigPinR 6
#define echoPinR 7

//LED Matrix
int DIN = 10;
int CS =  9;
int CLK = 8;

LedControl lc = LedControl(DIN,CLK,CS,0);

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
  //Ultrasonic Sensors
  Serial.begin (9600);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinF, OUTPUT);
  pinMode(echoPinF, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  //LED Matrix
  lc.shutdown(0,false);       
  lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0);  
}

void loop()
{
  //Ultrasonic Sensors
  SonarSensor(trigPinL, echoPinL);
  LeftSensor = distance;
  SonarSensor(trigPinF, echoPinF);
  FrontSensor = distance;
  SonarSensor(trigPinR, echoPinR);
  RightSensor = distance;
  Serial.print(LeftSensor);
  Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.println(RightSensor);

  //LED Matrix
   //1. Facial Expression
    byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};

    byte angryFilled[8]= {0x3c, 0x7e, 0xbd, 0xdb, 0xff, 0xc3, 0x42, 0x3c};
    byte smileFilled[8]=   {0x3c, 0x7e, 0xdb, 0xff, 0xdb, 0xe7, 0x7e, 0x3c};
    
    byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
    byte sad[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
   
    //2. Arrow
    byte arrow_up[8]= {0x18,0x3C,0x7E,0xFF,0x18,0x18,0x18,0x18};
    byte arrow_down[8]= {0x18,0x18,0x18,0x18,0xFF,0x7E,0x3C,0x18};
   
    
    //3. Alternate Pattern
    byte d1[8]= {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55};
    byte d2[8]= {0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};
    
    //4. Moving car
    byte b1[8]= {0x00,0x00,0x00,0x00,0x18,0x3C,0x18,0x3C};
    byte b2[8]= {0x00,0x00,0x00,0x18,0x3C,0x18,0x3C,0x00};
    byte b3[8]= {0x00,0x00,0x18,0x3C,0x18,0x3C,0x00,0x00};
    byte b4[8]= {0x00,0x18,0x3C,0x18,0x3C,0x00,0x00,0x00};
    byte b5[8]= {0x18,0x3C,0x18,0x3C,0x00,0x00,0x00,0x00};
    byte b6[8]= {0x3C,0x18,0x3C,0x00,0x00,0x00,0x00,0x18};
    byte b7[8]= {0x18,0x3C,0x00,0x00,0x00,0x00,0x18,0x3C};
    byte b8[8]= {0x3C,0x00,0x00,0x00,0x00,0x18,0x3C,0x18};

    //5. FU
    byte FU[8]= {0x0, 0x0, 0xe9, 0x89, 0xe9, 0x89, 0x86, 0x0};

    //6. Heart
    byte heart[8]= {0x6c, 0x92, 0x82, 0x82, 0x44, 0x28, 0x10, 0x0};
    byte heartFilled[8]= {0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x0};

    //7. $$$
    byte alien[8]= {0x0, 0x24, 0x66, 0xff, 0xdb, 0x66, 0x3c, 0x0};


//
//
// Conditions with the sensor values to call specific matrix animations
//
//

//Moving car
//    printByte(b1);
//    delay(50);
//    printByte(b2);
//    delay(50);
//    printByte(b3);
//    delay(50);
//    printByte(b4);
//    delay(50);
//    printByte(b5);
//    delay(50);
//    printByte(b6);
//    delay(50);
//    printByte(b7);
//    delay(50);
//    printByte(b8);
//    delay(50);
 
//alternate pattern
//    printByte(d1);
//    delay(100);
//
//    printByte(d2);
//    delay(100);

//Arrow
//    printByte(arrow_up);
//    delay(2000);
//
//    printByte(arrow_down);
//    delay(2000);
    

   
//Facial Expression   
//    printByte(smile);
//     
//    delay(1000);
//
//    printByte(neutral);
//    
//    delay(1000);
//
//    printByte(sad);    

//    delay(1000);
//
//        printByte(heart);    

//    delay(1000);
//        printByte(heartFilled);    

//    delay(1000);
//        printByte(smileFilled);    
//
//    delay(1000);
//        printByte(angryFilled);    

//    delay(1000);
//        printByte(dinero);    

//    delay(1000);

if(FrontSensor<=30)
  printByte(FU);    
else if(FrontSensor>30 && FrontSensor<=210)    
         printByte(smile);
         else if(FrontSensor>210 && FrontSensor<=320)
         printByte(smile);
         else
         printByte(heartFilled); 

//    delay(1000);
}

void SonarSensor(int trigPin,int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}


void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
