 #include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char msg;

int opt;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600); 
  pinMode(13, OUTPUT);// Setting the baud rate of Serial Monitor (Arduino)
  pinMode(11, OUTPUT);
  delay(100);
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918560000183\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Message from thinkphi... to use manual control, press #0 for turn lights off and #1 for turn lights on...");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }

void loop()
{
  if (Serial.available()>0)
  {
      RecieveMessage();
      SendMessage();
  }

 if (mySerial.available()>0)
 {
   msg=mySerial.read();
   Serial.write(msg);
   delay(10);
   if(msg=='#')
   {
      msg=mySerial.read();
      Serial.write(msg);
      if(msg=='m'||msg=='M')
      {
        
        msg=mySerial.read();
        Serial.write(msg);
        delay(1000); 
         if(msg=='0')
         {
            digitalWrite(13,LOW);
            delay(10);
            digitalWrite(11,LOW);
         }else if(msg=='1')
         {
            digitalWrite(13,HIGH);
            delay(10);
            digitalWrite(11,LOW);
         }else
            SendMessage();
      }
      else if(msg=='a'||msg=='A')
      {
         digitalWrite(13,LOW);
         delay(10);
         digitalWrite(11,HIGH);
   }
   }
 }
}




