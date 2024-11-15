int FlameSensorPin = A0;   // Define the analog input pin for the flame sensor
int FlameSensorReading;    // Variable to store the sensor reading
int LED = 2;               // Define the digital pin for the LED
int Buzzer = 3;// Define the digital pin for the buzzer

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);
  
  // Set the LED and buzzer pins as outputs
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  // Read the value from the flame sensor
  FlameSensorReading = analogRead(FlameSensorPin);
  
  // Print the sensor reading to the serial monitor
  Serial.println(FlameSensorReading);
  
  // Check if the sensor reading indicates the presence of a flame
  if (FlameSensorReading > 984) {  // Adjust threshold based on your flame sensor's sensitivity
    digitalWrite(LED, HIGH);     // Turn on the LED
    tone(Buzzer, 2000, 500);     // Activate the buzzer with a 2000 Hz tone for 500 ms
  } else {
    digitalWrite(LED, LOW);      // Turn off the LED
    noTone(Buzzer);              // Turn off the buzzer
  }

  // Add a small delay to prevent flooding the serial monitor with data
  delay(500);
}