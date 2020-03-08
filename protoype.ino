#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTPIN 8
#define DHTTYPE DHT22
#define gas_pin A5
DHT dht(DHTPIN,DHTTYPE);
int count = 0;
float totalTemp, avgTemp;
float totalGas, avgGas;
int buttonState = 0;
int switchPin = 9;
int buzzerPin = 10;
int minGas = 1000;
int isHot = 0;
void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(gas_pin, INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  pinMode(switchPin,INPUT);
}
void myDelay(unsigned long duration)
{
   unsigned long start = millis();
   int voltage;
   while (millis() - start <= duration)
   {
      voltage=digitalRead(switchPin);
      if (voltage==HIGH && isHot==1)
      {
          tone(buzzerPin,1000,1);
      }
   }
}
void loop()
{
   myDelay(3000);
   int voltage = digitalRead(switchPin);
   float temp = dht.readTemperature();
   float hum = dht.readHumidity();
   count++;
   int analogSensor = analogRead(gas_pin);
   if (analogSensor < minGas)
   {
      minGas = analogSensor;
   }
   if (count<=10)
   {
      totalTemp+=temp;
      totalGas+=analogSensor;
      avgTemp = totalTemp/count;
      avgGas = totalGas/count;
   }
   //float ppm =pow(10,(((log(10)-avgGas)/analogSensor) +minGas));
   Serial.print("T");
   Serial.print(temp);
   Serial.print(",");
   Serial.print("G");
   Serial.print(analogSensor*8);
   Serial.print(",H");
   Serial.println(hum);
   float tempDiff = temp-avgTemp;
   float gasDiff = analogSensor-avgGas;
   if (tempDiff >= 0.3) //REd
   {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(2,HIGH);
      isHot = 1;
      //if (voltage==HIGH) //Up is low, down is high
      //{
      //    tone(buzzerPin,1000,3000);
      //}
   }
   else if (tempDiff > 0.1) //Yellow
   {
      isHot=0;
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
   }
   else //Blue
   {
      isHot=0;
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
   }
}
