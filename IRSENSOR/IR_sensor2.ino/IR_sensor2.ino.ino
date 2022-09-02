int irpin = 5;
int ir;
int LED1 = 12;
int LED2 = 13;
int LED3 = 14;
int LED4 = 26;
int LED5 = 27;


void setup()
{
pinMode(5,INPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(26,OUTPUT);
pinMode(27,OUTPUT);
}

void loop() 
{
ir=digitalRead(irpin);
//while(digitalRead(irpin))
//delay(300);
if(ir==LOW)
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED5,HIGH);
  delay(300);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED4,HIGH);
  delay(300);
  digitalWrite(LED3,HIGH);
  delay(600);
  digitalWrite(LED3,LOW);
  delay(300);
  digitalWrite(LED2,LOW);
  digitalWrite(LED4,LOW);
  delay(300);
  digitalWrite(LED1,LOW);
  digitalWrite(LED5,LOW);
  delay(300);
}

else
{
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
   digitalWrite(LED4,LOW);
   digitalWrite(LED5,LOW);
   delay(300);
}

}
