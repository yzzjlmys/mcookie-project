#define  sensorPin  6
int state;
void setup()
{
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  state = digitalRead(sensorPin);
  Serial.println(state);
  if (state == 1)
        digitalWrite(10,HIGH);
    else
        digitalWrite(10,LOW);
  delay(500);
}
