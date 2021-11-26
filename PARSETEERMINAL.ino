/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define BLYNK_MSG_LIMIT 20
#define light1 D3
#define light2 D4
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>

// Construct an LCD object and pass it the 
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.
LiquidCrystal_I2C lcd(0x27, 20, 4);
char auth[] = "qkqNFA6MmwQT0ma-MVZYrjGA1goxE7J8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Anonymous@unifi";
char pass[] = "NBV1190WAJA";


void setup()
{

  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  digitalWrite(light1,HIGH);
  digitalWrite(light2,HIGH);
  // Debug console
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hi");
  delay(1000);
  lcd.clear();

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

BLYNK_WRITE(V1) // Terminal Widget on port V1
{
String text = param.asStr(); // Get typed in data

Serial.println(text);  // Printing to 2nd hardware serial port as a test   lcd.setCursor(0, 0);
  lcd.setCursor(0,0);
  lcd.println(text);
  
  for (int positionCounter = 0; positionCounter < 80; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(500);


    }
     
}

BLYNK_WRITE(V2)
{
  int turnon = param.asInt();
  if(turnon == HIGH)
  {
    digitalWrite(light1,HIGH);
  }

  else
  {
    digitalWrite(light1,LOW);
  }
}

BLYNK_WRITE(V3)
{
  int turnon2 = param.asInt();
  if(turnon2 == HIGH)
  {
    digitalWrite(light2,HIGH);
  }

  else
  {
    digitalWrite(light2,LOW);
  }
}


void loop()
{
  
Blynk.run();

   
}
