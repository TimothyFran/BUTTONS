#ifndef BUTTONS_H
#define BUTTONS_H

#include "Arduino.h"

class BUTTON {
  private:
    byte pin;
    unsigned int debounceTime = 0;
    bool pressed = LOW;
    bool currentState, prevState, lastDebouncedState, tempResult;
    unsigned long lastEvent;
    #define PULLUP true
  public:
    BUTTON(byte Pin);
    void begin(bool mode);
    bool read();
    bool isPressed();
    bool isReleased();
    void enableDebounce(unsigned int time);
    void disableDebounce();
    void setDebounceTime(unsigned int time);
};

#endif