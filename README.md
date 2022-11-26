# BUTTONS
An Arduino Library for simple buttons use

This arduino library is intended to manage buttons using debounce and edge detection.

Functions:

BUTTON myButton(5) to initialize a button on pin D5

myButton.begin() to begin the button using normal input
myButton.begin(PULLUP) to begin the button using input pullup

myButton.read() to read the actual value of the button pin

myButton.isPressed() returns true if button goes from not pressed to pressed
myButton.isReleased() returns true if button goes from pressed to not pressed

myButton.enableDebounce(time) to enable debouncing. time is debounce time in ms
myButton.setDebounceTime(time) to change debounce time once enabled. time is debounce time in ms
myButton.disableDebounce() to disable debounce once enabled
