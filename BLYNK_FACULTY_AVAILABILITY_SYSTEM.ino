#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ir1 13 //d7
#define ir2 5 //d1
#define ir3 4 //d2

char auth[] = "........";   //authentication code from Blynk 

char ssid[] = ".........";  //Fill in hostspot SSID and password
char pass[] = ".........";

WidgetLCD lcd1(V1);   //FOR BLYNK
WidgetLCD lcd2(V2);
WidgetLCD lcd3(V3);

int val1 = 0; // variable for reading IR1
int val2 = 0; // variable for reading IR2
int val3 = 0; // variable for reading IR3 
void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  lcd1.clear(); //Use it to clear the LCD Widget
   lcd2.clear(); //Use it to clear the LCD Widget
    lcd3.clear(); //Use it to clear the LCD Widget
}

void loop()
{
  Blynk.run();
   val1 = digitalRead(ir1); // read input value 
   val2 = digitalRead(ir2); // read input value 
   val3 = digitalRead(ir3); // read input value 

if (val1 == HIGH) // no obstacle
   { // check if the input is HIGH
      Serial.println("HIGH"); 
      lcd1.clear();
      lcd1.print(0, 0, "Faculty 1  is available"); 
   } 
   else 
   { 
      Serial.println("LOW");
      lcd1.clear();
      lcd1.print(0, 0, "faculty 1 is not available"); 
   } 

       if (val2 == HIGH) // no obstacle
   { // check if the input is HIGH
      Serial.println("HIGH"); 
      lcd2.clear();
      lcd2.print(0, 0, "Faculty 2  is available"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") 
   } 
   else 
   { 
      Serial.println("LOW");
      lcd2.clear();
      lcd2.print(0, 0, "faculty 2 is not available"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
   } 

   if (val3 == HIGH) // no obstacle
   { // check if the input is HIGH
      Serial.println("HIGH"); 
      lcd3.clear();
      lcd3.print(0, 0, "Faculty 3  is available"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") 
   } 
   else 
   { 
      Serial.println("LOW");
      lcd3.clear();
      lcd3.print(0, 0, "Faculty 3 is not available"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
   } 

