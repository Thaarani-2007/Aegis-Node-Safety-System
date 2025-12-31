#include <Adafruit_NeoPixel.h>

// PIN CONFIGURATION
#define RING_PIN    15    
#define BUZZER_PIN  2     
#define BTN_CRASH   12    // Red Button Pin
#define BTN_SIREN   14    // Blue Button Pin
#define NUMPIXELS   16    

Adafruit_NeoPixel ring(NUMPIXELS, RING_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  
  // Initialize NeoPixel
  ring.begin();
  ring.setBrightness(255); 
  
  // Initialize Pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BTN_CRASH, INPUT_PULLUP); // Uses internal resistor
  pinMode(BTN_SIREN, INPUT_PULLUP); // Uses internal resistor
  
  Serial.println("AEGIS NODE: BUTTON CONTROL ACTIVE");
}

void loop() {
  // Read button states (LOW means pressed because of INPUT_PULLUP)
  bool crashPressed = (digitalRead(BTN_CRASH) == LOW);
  bool sirenPressed = (digitalRead(BTN_SIREN) == LOW);

  if (crashPressed) {
    // CRASH MODE (Red + Buzzer)
    ring.fill(ring.Color(255, 0, 0)); 
    tone(BUZZER_PIN, 1000); 
    Serial.println("ALERT: CRASH DETECTED");
  } 
  else if (sirenPressed) {
    // SIREN MODE (Blue)
    ring.fill(ring.Color(0, 0, 255)); 
    noTone(BUZZER_PIN);
    Serial.println("ALERT: SIREN DETECTED");
  } 
  else {
    // NORMAL MODE (Green)
    ring.fill(ring.Color(0, 255, 0)); 
    noTone(BUZZER_PIN);
  }
  
  ring.show(); // Update the ring colors
  delay(50);   // Small delay for stability
}