#include <SPI.h>
#include <SD.h>
#include <math.h>


#define LIGHT_PIN A3
#define TEMP_PIN  A2
#define CS        8

float r_light, light, v_temp, temp;
String data;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(CS)) {
    Serial.println("Cannot initialize SD port");
    return;
  }
}

void loop() {
  r_light = 10.0 / (1023.0 / analogRead(LIGHT_PIN) - 1.0);
  light = 10.0 * pow(14.0 / r_light, 1.6);
  v_temp = 1023.0 / analogRead(TEMP_PIN) - 1.0;
  temp = 1.0 / (-log(v_temp) / 3977.0 + 1.0 / 295.0) - 273.0;

  data = String(millis() / 1000) + ";" + String(light) + ";" + String(temp);

  data.replace(".", ",");
  Serial.println(data);

  File logF = SD.open("log.csv", FILE_WRITE);
  logF.println(data);
  logF.close();

  delay(1000);
}
