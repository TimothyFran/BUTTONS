/*
 * By Timothy Franceschi
 * www.franceschi.es
 * 
 * This library is for a simple use of buttons
 * 
 * WIRING:
 *  Connect a pushbutton between GND and pin D5
 *  
 */

#include <BUTTONS.h>

byte buttonPin = 5;

BUTTON myButton(buttonPin);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // Begin the button.
  myButton.begin(PULLUP);
  //muButton.begin(); // use this line if you do not want to use INPUT_PULLUP

  // Enable debouncing with 100ms of time
  myButton.enableDebounce(100);

  // Change debounce time to 50ms
  myButton.setDebounceTime(50);

  // Disable debouncing
  //myButton.disableDebounce(); // Uncomment this line to disable debounce

  // Print current reading of the button pin
  Serial.print("Actual pin reading: ");
  Serial.println(myButton.read());

}

void loop() {
  // put your main code here, to run repeatedly:

  // Use .isPressed() to detect when button goes from NOT PRESSED to PRESSED
  if(myButton.isPressed()) Serial.println("BUTTON HAS BEEN PRESSED");

  // Use .isReleased() to detect when the button goes from PRESSED to NOT PRESSED
  if(myButton.isReleased()) Serial.println("BUTTON HAS BEEN RELEASED");

  // Avoid using delay

}
