#include <Wire.h>

int redPin= 7;
int greenPin = 6;
int bluePin = 5;
int Intensity =0;

#define AD5 A5

void setup() {
  
// put your setup code here, to run once:
  
Serial.begin(9600);
 
 while (!Serial) {
    
; // wait for serial port to connect. Needed for Leonardo only
  
pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}
  
}

void loop() {
  
// put your main code here, to run repeatedly:
  
  Intensity = analogRead(AD5);  //读取模拟口AD5的值，存入Intensity变量
  Serial.print("Intensity = ");  //串口输出"Intensity = "
  Serial.println(Intensity);     //串口输出Intensity变量的值，并换行
  delay(500);     //延时500ms
if(Intensity>600){
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  }
  else {
    setColor(0, 0, 0); // Black Color
  delay(1000);
    }

}


void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
