/* Code written for the IronBox project */

int relay_pin = 8;
int signal_pin =5;
int status_pin = 0;
unsigned long time;

void setup()
{
  pinMode(relay_pin,OUTPUT);
  pinMode(signal_pin,INPUT);
  pinMode(status_pin,INPUT);
  digitalWrite(relay_pin,LOW);
  digitalWrite(signal_pin,LOW);
  digitalWrite(status_pin,LOW);
}

void loop()
{
  //check for ironbox power-on-request
  while(status_pin==HIGH) 
  {
    time=millis();
    //power-on the ironbox after starting timer
    digitalWrite(relay_pin,HIGH);
    
    if(signal_pin==HIGH)
     {
       if(time>30000)
       {
         digitalWrite(relay_pin,LOW);
       }
     }
     
     else{
       if(time>3000)
       {
         digitalWrite(relay_pin,LOW);
       }
     }
  }
    
  
}
