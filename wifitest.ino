#include <ESP8266WiFi.h>
char ssid[]="........."; //fill in hotspot ssid and password
char pass[]=".........";

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.print("Connecting to...");
  Serial.print(ssid);
  delay(500);

  //initate Wifi
  WiFi.disconnect();
  WiFi.begin(ssid,pass);

  //wait till connection is established
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.println(",");
  }
  Serial.print("SSID.... ,");
  Serial.println(WiFi.SSID());
  Serial.println("Connected successfully!");

  Serial.print("IP address of NodeMCU:  ");
  Serial.println(WiFi.localIP());

  Serial.print("MAC address of NodeMCU:  ");
  Serial.println(WiFi.macAddress());
  WiFi.printDiag(Serial); //prints credentials
  }

void loop() {
  // put your main code here, to run repeatedly:

}


