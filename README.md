## Wifi Garage Door Opener

This is a simple project that will allow you to open or close your garage door from anywhere. It will also let you know whether the door is currently opened or closed. 

I was looking to build this at a fraction of the cost of the commercial offerings and keeping it as simple as possible. 

### Technology

For my first home automation project I wanted to use as many "off the shelf" tools as possible in order to simplify the development. After doing some research I found http://www.blynk.cc/ which I found to be an excellent fit for my project. It allowed me to customize an Android application and communicate with my wifi board with very little code.

### Parts

- [NodeMCU LUA WiFi ESP8266 Development Board](http://amzn.to/2iYBeTo)
- [Door Sensor Magnetic Reed Switch](http://amzn.to/2kbAGq7)
- [Breadboard](http://amzn.to/2klLUvB) - NOTE: I ended up buying an [Arduino Starter Kit](http://amzn.to/2jWg3ku) instead, which comes with a breadboard and a bunch of other stuff as well.
- [Relay](https://rover.ebay.com/rover/1/711-53200-19255-0/1?icep_id=114&ipn=icep&toolid=20004&campid=5338026670&mpre=http%3A%2F%2Fwww.ebay.com%2Fitm%2FDC-3V-3-3V-Relay-High-Level-Driver-Module-optocouple-Relay-Module-for-Arduino%2F331502222842%3Frt%3Dnc%26_soffid%3D5%26_soffType%3DPromotionalShipping%26_trksid%3Dp5731.m3795) - NOTE: This relay works at 3v/3.3v which is what the ESP8266 board runs at.
- [Power Supply](http://amzn.to/2k18UiX) - NOTE: I assume you have a brick and a micro usb cable laying around somewhere.
- Wire - NOTE: I used some 22awg speaker wire that I already had, however, using stranded wire in a breadboard can be difficult. I would recommend solid core if you don't plan on doing any soldering.
- Butt Connectors - These can be picked up at any hardware or automotive store.

All these parts total ~$35 and you will have plenty of parts left over for more home automation projects.

### Schematic 

![Image](https://github.com/colatt/WifiGarageDoor/blob/master/GarageDoor_bb.png)

### The Code

```
#define BLYNK_PRINT Serial
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
```
