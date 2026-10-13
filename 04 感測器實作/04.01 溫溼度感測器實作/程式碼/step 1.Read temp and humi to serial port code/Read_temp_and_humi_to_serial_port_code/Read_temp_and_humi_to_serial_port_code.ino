//Generated Date: Mon, 12 Oct 2026 16:20:13 GMT

#include <DHT.h>

float temp = 0;
float humi = 0;
DHT dht11_p10(10, DHT11);

void setup()
{
  Serial.begin(9600);


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
  delay(1000);
}
