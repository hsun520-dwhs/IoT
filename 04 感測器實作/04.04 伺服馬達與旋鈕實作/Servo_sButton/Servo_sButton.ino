//Generated Date: Wed, 14 Oct 2026 08:51:18 GMT

int angle = 90;
#include <Servo.h>
#include "Wire.h"
#include "U8g2lib.h"

Servo servo1;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

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
}

void loop()
{
  angle = map(analogRead(16),0,4090,0,180);
  servo1.write(angle);
  Serial.println((String("馬達角度：")+String(angle)));
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 0);
    u8g2.print(String(String("angle:")+String(angle)).c_str());

    u8g2.sendBuffer();
  } while (u8g2.nextPage());
  delay(100);
}
