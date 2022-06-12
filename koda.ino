const int b1 = 1;
const int b2 = 2;
const int b3 = 3;
const int b4 = 4;
const int rele = 5;
const int led = 7;
boolean b1status = false;
boolean b2status = false;
boolean b3status = false;
boolean b4status = false;

void setup()
{
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (digitalRead(b1) == HIGH);
  {
    b1status = true;
    while (b1status)
    {
      digitalWrite(led, HIGH);
      if (digitalRead(b3) == HIGH)
      {
        b1status = false;
        b3status = true;
        break;
      }
    }
    while (b3status)
    {
      digitalWrite(rele, HIGH);
      if (digitalRead(b4) == HIGH)
      {
        b4status = true;
        while (b4status)
        {
          digitalWrite(led, HIGH);
          delay(100);
          digitalWrite(led, LOW);
          delay(100);
          if (digitalRead(b2) == HIGH)
          {
            b3status = false;
            b4status = false;
            break;
          }
        }
      }
      break;
    }
  }
}
