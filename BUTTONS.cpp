#include "BUTTONS.h"

BUTTON::BUTTON(byte Pin){
    // This function set the local pin variable
    pin = Pin;
}

void BUTTON::begin(bool mode){
    // This functions sets the pinmode and registers the initial state of prevState
    if(mode == true) {
        pinMode(pin, INPUT_PULLUP);
        pressed = LOW;
    } else {
        pinMode(pin, INPUT);
        pressed = HIGH;
    }
    prevState = digitalRead(pin);
    lastDebouncedState = digitalRead(pin);
}

bool BUTTON::read(){
    // This function returns the digital reading of the pin
    return(digitalRead(pin));
}

void BUTTON::enableDebounce(unsigned int time){
    debounceTime = time;
}

void BUTTON::disableDebounce(){
    debounceTime = 0;
}

void BUTTON::setDebounceTime(unsigned int time){
    debounceTime = time;
}

bool BUTTON::isPressed(){

    /*
        This function is used to detect the PRESS event of the button

        Returns true when button goes from PRESSED to NOT PRESSED
        Otherwise returns false

        currentState        : is the current state of the pin. Used to not use always digitalRead()
        prevState           : is the state of the pin on the previous function call
        lastDebouncedState  : is the last debounced state of the button
        tempResult          : is a temporary result stored before to end the function
        lastEvent           : millis() of the last PINCHANGE event

    */

    // Store current state of the pin
    currentState = digitalRead(pin);

    /*
        If pin state has changed:
            - Update previous state variable
            - Update last event millis()
    */
    if(currentState != prevState) {
        prevState = currentState;
        lastEvent = millis();
    }

    // If not enough time to debounce, return false (button still not released)
    if((millis() - lastEvent) < debounceTime) return(false);
    
    /*
        If it is pressed, and before was not pressed: button has been pressed
        Otherwise it has not been pressed
    */
    if(currentState == pressed && lastDebouncedState != pressed) {
        tempResult = true;
    } else {
        tempResult = false;
    }

    // Update the last debounced state
    lastDebouncedState = currentState;

    return(tempResult);

}

bool BUTTON::isReleased(){

    /*
        This function is used to detect the RELEASE event of the button

        Returns true when button goes from PRESSED to NOT PRESSED
        Otherwise returns false

        currentState        : is the current state of the pin. Used to not use always digitalRead()
        prevState           : is the state of the pin on the previous function call
        lastDebouncedState  : is the last debounced state of the button
        tempResult          : is a temporary result stored before to end the function
        lastEvent           : millis() of the last PINCHANGE event

    */

    // Store current state of the pin
    currentState = digitalRead(pin);

    /*
        If pin state has changed:
            - Update previous state variable
            - Update last event millis()
    */
    if(currentState != prevState) {
        prevState = currentState;
        lastEvent = millis();
    }

    // If not enough time to debounce, return false (button still not released)
    if((millis() - lastEvent) < debounceTime) return(false);
    
    /*
        If it is not pressed, and before was pressed: button has been released
        Otherwise it has not been released
    */
    if(currentState != pressed && lastDebouncedState == pressed) {
        tempResult = true;
    } else {
        tempResult = false;
    }

    // Update the last debounced state
    lastDebouncedState = currentState;

    return(tempResult);

}
