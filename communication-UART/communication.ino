#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // Check if there is incoming message from Chloe
  if (mySerial.available()) {
    String receivedData = mySerial.readStringUntil('\n');
    Serial.print("Chloe: ");
    Serial.println(receivedData);
  }

  // Wait for user input from Hope
  if (Serial.available()) {
    Serial.println("...🇷🇼..⎆");
    
    // Read the user input
    String userInput = Serial.readStringUntil('\n');
  
    // Print the user input to the Serial Monitor
    Serial.print("Hope: ");
    Serial.println(userInput);
    
    // Print the user input to the SoftwareSerial
    mySerial.println(userInput);
  }

  delay(1000);
}
