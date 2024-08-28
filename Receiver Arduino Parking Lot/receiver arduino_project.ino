// Receiver Board (Transmitter)

int ultrasonicTriggerPins[] = {2, 3, 4,5}; // Digital pins for ultrasonic triggers (4 pins)
int ultrasonicEchoPins[] = {6, 7, 8,13};   // Digital pins for ultrasonic echo (4 pins)
int greenLEDs[] = {A0, A1, A2,A3};        // Digital pins for green LEDs (4 pins)
const int NUM_ULTRASONIC_SENSORS = 4;      // Number of ultrasonic sensors (4 sensors)
const int OCCUPIED_THRESHOLD = 10;
long duration;
long distanceCm;

// Function to measure distance using an ultrasonic sensor
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  // Implement the ultrasonic measurement logic here
  return distanceCm;
}



void setup() {
  for (int i = 0; i < NUM_ULTRASONIC_SENSORS; i++) {
    pinMode(ultrasonicTriggerPins[i], OUTPUT);
    pinMode(ultrasonicEchoPins[i], INPUT);
    pinMode(greenLEDs[i], OUTPUT);
  }

  Serial.begin(9600); // Start serial communication
}



void loop() {
  int parkingStatus[NUM_ULTRASONIC_SENSORS];

  // Measure distances from the ultrasonic sensors
  for (int i = 4; i < NUM_ULTRASONIC_SENSORS+4; i++) {
    long distance = measureDistance(ultrasonicTriggerPins[i-4], ultrasonicEchoPins[i-4]);

    if (distance > OCCUPIED_THRESHOLD) {
      parkingStatus[i] = 1; // Slot available
    } else {
      parkingStatus[i] = 0; // Slot occupied
    }
  }


  // Update the green LEDs based on the parkingStatus array
  
  
  for (int j=0; j<4; j++){
    if (Serial.available()){
      parkingStatus[j] = Serial.parseInt();
      //Serial.print(parkingStatus[j]);
    }
  
  }


  for (int i = 4; i < NUM_ULTRASONIC_SENSORS+4; i++) {
    if (parkingStatus[i] == 1) {
      analogWrite(greenLEDs[i-4], 255); // Slot available
    } else {
      analogWrite(greenLEDs[i-4], 0); // Slot occupied
    }
  }

  for (int k=0; k<8 ; k++){
    Serial.print(parkingStatus[k]);
  }

  
  Serial.println();
  delay(1000); // Add a small delay to avoid sending data and updating LEDs too frequently
}