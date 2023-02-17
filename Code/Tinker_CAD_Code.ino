// define the pins for buttons and LEDs
int a = 1 * 100;  // Width of 1st pulse
int b = 9 * 100;  // Width of space between pulses
int c = 16;  // Number of pulses in block
int d = 9 * 500;  // Space between pulse blocks
int mode = (1%4) + 1;  // Remainder of fifth letter/4 + 1, where "Arora" is 1

int button1State =0;
int button2State =0;

int button1Pin = 3;
int button2Pin = 2;
int led1Pin = 4;
int led2Pin = 5;

// define variables for parameters

// initialize the pins
void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

// loop to check the button inputs and perform operations accordingly
void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  if (button1State == LOW)
  {
    if (button2State == LOW)
    {
      
      digitalWrite(led2Pin, HIGH);
      delay(50);
      digitalWrite(led2Pin, LOW);

      for (int i = 0; i < c; i++)
      {
        
        digitalWrite(led1Pin, HIGH);
        delay(a + (i * 50));
        digitalWrite(led1Pin, LOW);
        delay(b);
      }
      delay(d);
    }
    // perform stream of pulses
    else
    {
      
      digitalWrite(led2Pin, HIGH);
      delay(50);
      digitalWrite(led2Pin, LOW);
    // disable stream of pulses
      
      for (int i = c; i > 0; i--)
      {
        digitalWrite(led1Pin, HIGH);
        delay(a + ((i - 1) * 50));
        digitalWrite(led1Pin, LOW);
        delay(b);
      }
      delay(d);
    }
  }
  else 
  {
    digitalWrite(led2Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }
}