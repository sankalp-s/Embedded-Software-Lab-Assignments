// Defining the pins for buttons and LEDs

int button1Pin = 27; // Pin 3 is assigned to button 1
int button2Pin = 12; // Pin 2 is assigned to button 2
int led1Pin = 25; // Pin 4 will be Led1 terminal
int led2Pin = 32; // Pin 5 will be for Led2

// Calculating the Paramater using my surname "ARORA"
// A - 1, R-9, O-12, R-9, A-1.  ARORA = 1 9 12 9 1

int a = 1 * 100;  // Width of 1st pulse
int b = 9 * 100;  // Width of space between pulses
int c = 16;  // Number of pulses in block
int d = 9 * 500;  // Space between pulse blocks
int mode = (1%4) + 1;  // Remainder of (fifth letter/4) + 1, where fifth letter is A - 1


// Set the initial button states to zero
int button1State =0;   // button 1 is set at LOW state
int button2State =0;   // button 2 is set at LOW state

// Initialize the pins
void setup() {
  pinMode(button1Pin, INPUT);   // button 1 is an input component
  pinMode(button2Pin, INPUT);   // button 2 is the seconf input component
  pinMode(led1Pin, OUTPUT);    // Led emits light thus used as an output signal to study waveforms
  pinMode(led2Pin, OUTPUT);    // Led2 is set as an output component
}

// Loop to check the button inputs and perform operations accordingly
void loop() {
  button1State = digitalRead(button1Pin); //Fetches the state of button1 to know if its at LOW or HIGH state
  button2State = digitalRead(button2Pin); //Fetches state of the second button
  
  if (button1State == LOW)    // If button1Pin is low jump to cases on switch 2
  {
    if (button2State == LOW) // Checking switch 2 cases to perform stream of pulses
    {
      
      digitalWrite(led2Pin, HIGH); // First blink of the red light
      delayMicroseconds(50); // Passing the delay for the HIGH red light of 50 microseconds
      digitalWrite(led2Pin, LOW); // Putting off the red light 

      for (int i = 0; i < c; i++) //For loop for the Normal wave mode
      {
        
        digitalWrite(led1Pin, HIGH);
        delayMicroseconds(a + (i * 50)); // Incremental delay of 50 microseconds with each cycle
        digitalWrite(led1Pin, LOW);
        delayMicroseconds(b); // delay of b microseconds between consecutive pulses
      }
      delayMicroseconds(d); // Delay of d microseconds after completion of one cycle of C pulses
    }
    
    else // run with a modified waveform cycle (Inverted waveform)
    {
      
      digitalWrite(led2Pin, HIGH); /// First blink of the red light
      delayMicroseconds(50); // Passing the delay for the HIGH red light of 50 microseconds
      digitalWrite(led2Pin, LOW); // Putting off the red light
      
      for (int i = c; i > 0; i--) //For loop for the modified waveform cycle (inverted signal a)
      {
        digitalWrite(led1Pin, HIGH);  
        delayMicroseconds(a + ((i - 1) * 50)); // Decremental delay of 50 microseconds with each cycle
        digitalWrite(led1Pin, LOW);
        delayMicroseconds(b); // delay of b microseconds between consecutive pulses
      }
      delayMicroseconds(d); // Delay of d microseconds after completion of one cycle of C pulses
    }
  }
  else // Executuions if button1Pin is HIGH
  {
    digitalWrite(led2Pin, LOW); // Red led is put off
    digitalWrite(led2Pin, LOW); // Green led is put off
  }
}
