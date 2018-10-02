/********************************************************************
 * PhotoGate Timer
 * Hardware connections:
 * IR LED (Emitter): Pin 12
 * IR Detector: Pin 2
 * Upload this example, open up the serial monitor - set to 115200 bps.
 * LED 13 will turn on to show that the beam is being detected.
 *******************************************************************/

// Initialize variables
int IRDetectorPin = 2;  // variable for the detector Pin of the photogate
int IRLEDPin = 12;      // variable for the IR LED Pin of the photogate
char DELIM = '\t';      // data column delimiter character
long baud_rate = 115200;  // use the fastest baud rate possible.
boolean photoGate;      // stores the state of the photoGate
boolean lastState = 0;  // stores the last State of photoGate used to detect a change
int eventNum = 1;
long eventTime;         // variable to store the time of the event.
void setup()
{
    Serial.begin(baud_rate);         // setup Serial communication

    pinMode(IRDetectorPin, INPUT_PULLUP);
    pinMode(IRLEDPin, OUTPUT);    // setup IRLEDPin as an output
    pinMode(13, OUTPUT);          // setup debug LED as an output
    digitalWrite(IRLEDPin, HIGH); // turn on the IR LED
    Serial.print("event");
    Serial.print(DELIM);
    Serial.print("time");
    Serial.print(DELIM);
    Serial.println("state");
    Serial.println("======================");
}

// the loop routine runs over and over again forever:
void loop()
{
    // read the input pin:
    photoGate = digitalRead(IRDetectorPin);  // Gate is HIGH when IR beam is broken.
    digitalWrite(13, !photoGate); // turns on the LED if the gate is NOT broken

    if (photoGate != lastState)  // if there is a change,
        {
            eventTime = millis();    // capture the time immediately.
            Serial.print(eventNum);  // print out the event number
            Serial.print(DELIM);
            Serial.print(eventTime / 1000.0, 3);  // print out the # of seconds as a floating point decimal
            Serial.print(DELIM);
            Serial.println(photoGate); // print out the state of the gate
            eventNum++; // increment the eventNum
        }
    lastState = photoGate;

}
