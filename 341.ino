#include <Wire.h>
+#include <LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x3F, 16, 2);
const int motor1Pin1 = 8;
const int motor1Pin2 = 9;
const int motor2Pin1 = 10;
const int motor2Pin2 = 11;
const int sensorPin = A0;
const int metalsensorPin = 12;
int metalsensorValue;
int value;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(metalsensorPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Wire .begin ();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("WELCOME");
}
void wetright()
{
  Serial.println("wetright");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  delay(2000);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
}
void metalleft()
{
  Serial.println("metalleft");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  delay(4000);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
}
void conveyorforward()
{
  Serial.println("conveyorforward");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}
void conveyorstop()
{
  Serial.println("conveyorstop");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(200);
}
void soilmoisture()
{
  // put your main code here, to run repeatedly:
  int value = analogRead(sensorPin);
  Serial.print("Moisture : ");
  Serial.println(value);
  if (value < 950)
  {
    Serial.println("wet detected ");
    conveyorstop();
    wetright();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("wet detected");
    delay(4000);
    lcd.clear();

  }
  else
  {
    Serial.println("wet not detected ");

  }

}
void metaldetector()
{
  int metalsensorValue = digitalRead(metalsensorPin);
  Serial.println(metalsensorValue);
  if (metalsensorValue == 0)
  {
    Serial.println("metal detected  ");
    conveyorstop();
    metalleft();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("metal detected");
    delay(1000);
    lcd.clear();
    conveyorstop();
    metalleft();
  }
  else
  {
    Serial.println("metal not detected  ");

  }
}
void loop()
{
  // put your main code here, to run repeatedly:
  conveyorforward();
  soilmoisture();
  metaldetector();
  delay(1000);
}
