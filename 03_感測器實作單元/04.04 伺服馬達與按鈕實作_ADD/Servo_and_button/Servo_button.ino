//Generated Date: Mon, 12 Oct 2026 14:38:39 GMT

#include <Servo.h>

Servo servo1;
int angle = 90;
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
  Serial.begin(9600);

  servo1.attach(6);
  servo1.write(angle);
  pinMode(A_Pin, INPUT);
  pinMode(B_Pin, INPUT);
}

void loop()
{
  myBtnStatus=getBtnStatus();
  if (myBtnStatus=='A'){
    angle = angle + 1;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    while(buttonPressed('A')){}
  }
  if (myBtnStatus=='B'){
    angle = angle - 1;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    while(buttonPressed('B')){}
  }
  if (myBtnStatus=='C'){
    angle = 90;
    servo1.write(angle);
    Serial.println((String("馬達角度：")+String(angle)));
    while(buttonPressed('C')){}
  }
}
