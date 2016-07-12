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
  //Console.println("Write 1 or 2 to toggle relay on/off");
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
          Console.println("Prekidac broj 1 je ukljucen!");
        else
          Console.println("Prekidac broj 1 je iskljucen.");
        break;
      }
      case '2':
      {
       relayVal2 ^= 1;
        if (!relayVal2)
          Console.println("Prekidac broj 2 je ukljucen!");
        else
          Console.println("Prekidac broj 2 je iskljucen.");
        break; 
      }
    default:
      {
        Console.println("Doslo je do greske.");
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
