#include <Console.h>
#define RELAY_PIN1 7
#define RELAY_PIN2 8


void setup()
{
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  Bridge.begin();
  Console.begin();
  while(!Console);
  digitalWrite(RELAY_PIN1, LOW);
  digitalWrite(RELAY_PIN2, LOW);
}

void loop()
{
  static int relayVal1 = 0;
  static int relayVal2 = 0;
  int cmd;
  
  while (Console.available() > 0)
  {
    cmd = Console.read();
      
    switch (cmd)
    {
    case '1':
      {
        relayVal1 ^= 1;
        if (!relayVal1)
          Console.println("Switch number 1 is on!");
        else
          Console.println("Switch number 1 is off.");
        break;
      }
      case '2':
      {
       relayVal2 ^= 1;
        if (!relayVal2)
          Console.println("Switch number 2 is on!");
        else
          Console.println("Switch number 2 is off.");
        break; 
      }
    default:
      {
        Console.println("There was an error.");
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
