int led = 13;                // the pin that the LED is attached to
int sensor = 2;              // the pin that the sensor is attached to
volatile int state = LOW;    // by default, no motion detected

void setup() {
  pinMode(led, OUTPUT);      // initialize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  attachInterrupt(digitalPinToInterrupt(sensor), motionDetected, HIGH);
  // attach interrupt to sensor pin, trigger on rising edge (HIGH)
  Serial.begin(9600);        // initialize serial
}

void loop(){
  // do other stuff here, if needed
}

void motionDetected() {
  digitalWrite(led, !state);   // toggle LED
  state = !state;              // update variable state
  if (state == HIGH) {
    Serial.println("Motion detected!"); 
  } 
  else {
    Serial.println("Motion stopped!");
  }
}

//In this code, we use the attachInterrupt function to attach an interrupt to the sensor pin. The motionDetected function is called whenever the sensor pin goes from low to high (rising edge). The volatile
//keyword is used to indicate that the state variable may be changed by the interrupt service routine.When motion is detected, the motionDetected function toggles the LED on or off depending on the current state,
//updates the state variable, and prints a message to the serial monitor.
//Note that interrupts can be a bit tricky to work with, so be sure to read up on their limitations and best practices if you're new to using them.
