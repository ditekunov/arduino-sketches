#include <LiquidCrystal.h>
 

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

int incomingByte = 0;
 
void setup() 
{

  Serial.begin(9600);
  
  lcd.begin(16, 2);

}
 
void loop() {

  lcd.setCursor(0, 0);
  
  lcd.print("Temp: ");

  if(Serial.available() > 0) {

    incomingByte = Serial.read(); 

    lcd.print(incomingByte - 8);
  }

  delay(200);

}
