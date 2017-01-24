#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

const int MAGNETIC_SENSOR_PIN = 4;
const int RELAY_PIN = 13;

WidgetLCD lcd(V0);

bool currentDoorPosition = 1; 
bool previousDoorPosition = 0;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  while (Blynk.connect() == false) {
    // Wait until connected 
  }
  pinMode(MAGNETIC_SENSOR_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop()
{
  Blynk.run();
  garageDoorMagneticSensor();
}

BLYNK_WRITE(V1) 
{
  //--on Blynk button press, activate garage door for 1 second
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);           
}

void garageDoorMagneticSensor()
{
  currentDoorPosition = digitalRead(MAGNETIC_SENSOR_PIN);
  if (currentDoorPosition != previousDoorPosition) { 
    previousDoorPosition = currentDoorPosition;
    if (currentDoorPosition == LOW)
    {
      lcd.clear();
      lcd.print(1, 0, "CLOSED");
    }
    else
    {
      lcd.clear();
      lcd.print(1, 0, "OPEN");
    }
  }
}




