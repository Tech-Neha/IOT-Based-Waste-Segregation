const int sensorPin = A0;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int value = analogRead(sensorPin);

  Serial.print("Moisture : ");
  Serial.println(value);
  delay(2000);
}
