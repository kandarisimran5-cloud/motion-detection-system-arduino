// Pin definitions
const int PIR_PIN = 2;     // Signal pin from PIR sensor
const int ALARM_PIN = 13;   // Pin connected to LED and Buzzer

// Variables to track state
int pirState = LOW;        // Start assuming no motion detected
int val = 0;               // Variable for reading the pin status

void setup() {
  pinMode(PIR_PIN, INPUT);     // Declare sensor as input
  pinMode(ALARM_PIN, OUTPUT);  // Declare alarm as output

  Serial.begin(9600);          // Initialize serial communication
  Serial.println("System Initialised. Monitoring for motion...");
}

void loop() {
  val = digitalRead(PIR_PIN);  // Read input value
  
  if (val == HIGH) {           // Check if the input is HIGH
    digitalWrite(ALARM_PIN, HIGH);  // Turn LED/Buzzer ON
    
    if (pirState == LOW) {
      // We have just turned on
      Serial.println("ALERT: Motion detected!");
      pirState = HIGH;         // Update the tracker variable
    }
  } else {
    digitalWrite(ALARM_PIN, LOW); // Turn LED/Buzzer OFF
    
    if (pirState == HIGH) {
      // We have just turned off
      Serial.println("Motion ended. System secure.");
      pirState = LOW;          // Update the tracker variable
    }
  }
  delay(100); // Small delay to improve simulation stability
}

