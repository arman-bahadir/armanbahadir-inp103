// Pin definitions
const int VIBRATION_SENSOR_PIN = 2;  // KY-002 sensor
const int BUZZER_PIN = 11;            // Buzzer
const int LED_PIN = 3;               // Red LED
const int MOTOR_PIN = 4;             // Vibration motor

// Variables for LED blinking
unsigned long previousMillis = 0;
const long blinkInterval = 500;      // Blink every 500ms
bool ledState = LOW;
bool alarmActive = false;

void setup() {
  // Initialize pins
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the vibration sensor
  int sensorState = digitalRead(VIBRATION_SENSOR_PIN);
  
  // If vibration is detected
  if (sensorState == LOW) {
    alarmActive = true;
    Serial.println("Vibration detected!");
  }
  
  // If alarm is active, run all alerts until reset
  if (alarmActive) {
    // Blink the LED
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
    
    // Activate buzzer and motor
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(MOTOR_PIN, HIGH);
  } else {
    // Turn off all outputs when not active
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(MOTOR_PIN, LOW);
  }
}