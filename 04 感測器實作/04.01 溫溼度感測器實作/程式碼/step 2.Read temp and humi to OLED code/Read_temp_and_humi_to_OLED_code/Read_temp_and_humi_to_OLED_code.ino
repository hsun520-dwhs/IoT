//Generated Date: Mon, 12 Oct 2026 16:52:58 GMT

#include "Wire.h"
#include "U8g2lib.h"
#include <DHT.h>

float temp = 0;
float humi = 0;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
DHT dht11_p10(10, DHT11);

void setup()
{
  Serial.begin(9600);

  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);


  dht11_p10.begin();
}

void loop()
{
  temp = dht11_p10.readTemperature();
  humi = dht11_p10.readHumidity();
  Serial.print("溫度：");
  Serial.print(temp);
  Serial.print("溼度：");
  Serial.print(humi);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 0);
    u8g2.print(String(String("temp:")+String(temp)).c_str());
    u8g2.setCursor(0, 8);
    u8g2.print(String(String("humi:")+String(humi)).c_str());

    u8g2.sendBuffer();
  } while (u8g2.nextPage());
  delay(1000);
}
