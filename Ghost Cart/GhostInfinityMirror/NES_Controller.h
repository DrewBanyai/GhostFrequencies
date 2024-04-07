#define NES_A_BUTTON                0
#define NES_B_BUTTON                1
#define NES_SELECT_BUTTON           2
#define NES_START_BUTTON            3
#define NES_UP_BUTTON               4
#define NES_DOWN_BUTTON             5
#define NES_LEFT_BUTTON             6
#define NES_RIGHT_BUTTON            7

class NES_Controller {
  public:
    NES_Controller(int dataPin, int clockPin, int latchPin) {
      DataPin = dataPin;
      ClockPin = clockPin;
      LatchPin = latchPin;
      Disconnected = false;

      //  Set appropriate pins to inputs
      pinMode(DataPin, INPUT);
  
      //  Set appropriate pins to outputs
      pinMode(ClockPin, OUTPUT);
      pinMode(LatchPin, OUTPUT);
  
      //  Set initial states
      digitalWrite(ClockPin, LOW);
      digitalWrite(LatchPin, LOW);
    }

    inline bool CheckButton(int buttonID) { return (!Disconnected && (bitRead(ButtonRegister, buttonID) == 0)); }

    void DisconnectCheck() {
      Disconnected = false;

      if (!CheckButton(NES_A_BUTTON)) return;
      if (!CheckButton(NES_B_BUTTON)) return;
      if (!CheckButton(NES_SELECT_BUTTON)) return;
      if (!CheckButton(NES_START_BUTTON)) return;
      if (!CheckButton(NES_UP_BUTTON)) return;
      if (!CheckButton(NES_DOWN_BUTTON)) return;
      if (!CheckButton(NES_LEFT_BUTTON)) return;
      if (!CheckButton(NES_RIGHT_BUTTON)) return;

      Serial.println("All buttons are active, which signals a disconnect...");
      Disconnected = true;
    }

    void ReadController() 
    {  
      //  Pre-load a variable with all 1's which assumes all buttons are not pressed. But while we cycle through the
      //  bits, if we detect a LOW, which is a 0, we clear that bit. In the end, we find all the buttons states at once.
      ButtonRegister = 255;
        
      // Quickly pulse the Latch Pin so that the register grabs what it see on its parallel data pins.
      digitalWrite(LatchPin, HIGH);
      digitalWrite(LatchPin, LOW);
    
      //  Upon latching, the first bit is available to look at, which is the state of the A button. We see if it is low,
      //  and if it is, we clear out variable's first bit to indicate this is so.
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_A_BUTTON);
        
      // Clock the next bit which is the B button and determine its state just like
      // we did above.
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_B_BUTTON);
      
      // Now do this for the rest of them!
      
      // Select button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_SELECT_BUTTON);

      // Start button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_START_BUTTON);

      // Up button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_UP_BUTTON);
        
      // Down button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_DOWN_BUTTON);

      // Left button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_LEFT_BUTTON);  
        
      // Right button
      digitalWrite(ClockPin, HIGH);
      digitalWrite(ClockPin, LOW);
      if (digitalRead(DataPin) == LOW) bitClear(ButtonRegister, NES_RIGHT_BUTTON);

      DisconnectCheck();
    }

  private:
    int DataPin;
    int ClockPin;
    int LatchPin;

    bool Disconnected;

    byte ButtonRegister = 0; //  We will use this to hold current button states
};