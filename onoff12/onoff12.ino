//define relay pins 
#define RELAY_PIN1 7
#define RELAY_PIN2 8

void setup()
{
	// initialize the pins for the relay as output
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  Serial.begin(9600); // open serial
  Serial.println("Press 1/2 to toggle relay on/off");
}

void loop()
{
  static int relayVal1 = 0;
  static int relayVal2 = 0;
  int cmd;
  //make loop when the serial is available
  while (Serial.available() > 0)
  {
	// read the input all the time
    cmd = Serial.read();
      
    switch (cmd)
    {
    case '1':
      {
        relayVal1 ^= 1; // xor current value with 1 (causes value to toggle)
        if (relayVal1)
          Serial.println("Relay n.1 on");
        else
          Serial.println("Relay n.1 off");
        break;
      }
      case '2':
      {
       relayVal2 ^= 1; // xor current value with 1 (causes value to toggle)
        if (relayVal2)
          Serial.println("Relay n.2 on");
        else
          Serial.println("Relay n.2 off");
        break; 
      }
    default:
      {
        Serial.println("Press the button 1 or 2 to toggle relay on/off");
      }
    }
    
    if (relayVal1)
      digitalWrite(RELAY_PIN1, HIGH);
    else
      digitalWrite(RELAY_PIN1, LOW);
      if (relayVal2)
      digitalWrite(RELAY_PIN2, HIGH);
    else
      digitalWrite(RELAY_PIN2, LOW);
   }
}
