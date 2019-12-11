#define TRIG_PIN 4            //Connect TRIG pin to digital pin 4
#define ECHO_PIN 5            //Connect ECHO pin to digital pin 5
void setup() {
 pinMode(TRIG_PIN, OUTPUT);  //Set the TRIG pin to OUTPUT mode
 pinMode(ECHO_PIN, INPUT);   //Set the ECHO pin to INPUT mode
 Serial.begin(9600);         //Begin serial communication
}
void loop() {
 //Send a short (10 microseconds) ultrasonic burst
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);        
 digitalWrite(TRIG_PIN, LOW);
 float microseconds = pulseIn(ECHO_PIN, HIGH, 100000); //Mesure the duration of a HIGH pulse in echo pin in microseconds. Timeout in 0,1 seconds
 float seconds = microseconds / 1000000;               //Convert microseconds to seconds
 float meters = seconds * 343;                         //Get the distance in meters using the speed of sound (343m/s)
 float cm = meters * 100;                              //Convert meters to cm
 cm = cm/2;                                            //We only want the distance to the obstacle and not the roundtrip
 Serial.println(cm);                                   //Print distance in cm to the serial monitor
 delay(50);                                            //Delay 50 milliseconds until the next mesurement
}

