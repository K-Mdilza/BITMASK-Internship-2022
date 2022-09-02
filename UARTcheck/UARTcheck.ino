#define L1 12
#define L2 13
#define L3 14
#define L4 26

void setup()
{
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  Serial.begin(9600);
  Serial2.begin(115200);  
}

void loop()
{
  if(Serial2.available())
  {
    int n=Serial2.read();
    switch(n)
    {
      case '0':
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      Serial.println("ZERO");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
      case '1':
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,HIGH);
      Serial.println("ONE");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
      case '2':
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      Serial.println("TWO");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
      case '3':
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      Serial.println("THREE");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '4':
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      Serial.println("FOUR");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '5':
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,HIGH);
      Serial.println("FIVE");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '6':
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      Serial.println("SIX");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '7':
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      Serial.println("SEVEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '8':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      Serial.println("EIGHT");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case '9':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,HIGH);
      Serial.println("NINE");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'A':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      Serial.println("TEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'B':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      Serial.println("ELEVEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'C':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      Serial.println("TWELVE");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'D':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,HIGH);
      Serial.println("THIRTEEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'E':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      Serial.println("FOURTEEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
       case 'F':
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      Serial.println("FIFTEEN");
      Serial2.println("SUCCESS");
      delay(1000);
      break;
      default:
      Serial.println("INVALID COMMAND READ");
      Serial2.println("INVALID");
      delay(1000);
    }
  }
}
