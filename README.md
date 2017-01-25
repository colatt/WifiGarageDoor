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
- Wire - NOTE: I used some 22awg speaker wire that I already had, however, using stranded wire in a breadboard can be difficult. I would recommend solid core if you don't plan on doing any soldering.
- Butt Connectors - These can be picked up at any hardware or automotive store.

All these parts total ~$35 and you will have plenty of parts left over for more home automation projects.

### Schematic 

![Image](https://github.com/colatt/WifiGarageDoor/blob/master/GarageDoor_bb.png)

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/colatt/WifiGarageDoor/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
