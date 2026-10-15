//Generated Date: Tue, 13 Oct 2026 09:03:19 GMT

int angle = 90;
#include <Servo.h>
#include "Wire.h"
#include "U8g2lib.h"

Servo servo1;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
byte A_Pin=0;
byte B_Pin=7;
char myBtnStatus;
bool buttonPressed(char btnName)
{
  if (btnName=='A'){
    if (digitalRead(A_Pin) == 1)
      return false;
    else
      return true;
  }
  else if (btnName=='B'){
    if (digitalRead(B_Pin) == 1)
      return false;
    else
      return true;
  } else {
    if ((digitalRead(A_Pin) == 1) && (digitalRead(B_Pin) == 1))
      return false;
    else
      return true;
  }
}

char getBtnStatus(){
  char buttonStatus=' ';
  int checkButtonDelay=200;
  if (buttonPressed('A')){
    delay(checkButtonDelay);
    if (buttonPressed('A')){
      buttonStatus='A';
      if (buttonPressed('B'))
        buttonStatus='C';
    }
  } else if (buttonPressed('B')){
      delay(checkButtonDelay);
      if (buttonPressed('B')){
        buttonStatus='B';
        if (buttonPressed('A'))
          buttonStatus='C';
      }
  }
  return buttonStatus;
}

void setup()
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);

  Serial.begin(9600);

  servo1.attach(2);
  servo1.write(angle);
  pinMode(A_Pin, INPUT);
  pinMode(B_Pin, INPUT);
}

void loop()
{
  myBtnStatus=getBtnStatus();
  if (myBtnStatus=='A'){
    angle = 0;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 0);
      u8g2.print(String(String("angle:")+String(angle)).c_str());

      u8g2.sendBuffer();
    } while (u8g2.nextPage());
    while(buttonPressed('A')){}
  }
  if (myBtnStatus=='B'){
    angle = 180;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 0);
      u8g2.print(String(String("angle:")+String(angle)).c_str());

      u8g2.sendBuffer();
    } while (u8g2.nextPage());
    while(buttonPressed('B')){}
  }
  if (myBtnStatus=='C'){
    angle = 90;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 0);
      u8g2.print(String(String("angle:")+String(angle)).c_str());

      u8g2.sendBuffer();
    } while (u8g2.nextPage());
    while(buttonPressed('C')){}
  }
  delay(100);
}
