/********************************************/
// Project 1 - Simple sensorReading Example */
// Arduino A/D uses 10 bits to  
// quantize voltage from 0 to 5V
/********************************************/

int rawAnalogReading; // variable used to store the raw reading

void setup()
{
  Serial.begin(9600);
  Serial.println("Light Level Readings taken using Arduino");
  delay(1000);
}

/********************************************************/

void loop()
{
  rawAnalogReading = analogRead(A0);
  Serial.println(rawAnalogReading);
// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
   float voltage = sensorValue * (5.0 / 1023.0);
// print out the value you read:
   Serial.println(voltage);

  delay(500);
} 
