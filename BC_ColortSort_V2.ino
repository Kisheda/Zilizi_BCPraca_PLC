#define s0 4     
#define s1 5
#define s2 6
#define s3 7
#define out 8
#define singleRelay  11
#define doubleRelay1 12
#define doubleRelay2 13

int   Red=0, Blue=0, Green=0;  

void setup() 
{
   pinMode(s0,OUTPUT);     
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);
   pinMode(singleRelay, OUTPUT); // HIGH = ON (single relay module)
   pinMode(doubleRelay1, OUTPUT); // LOW  = ON (double relay module)
   pinMode(doubleRelay2, OUTPUT); // LOW  = ON (double relay module)

   Serial.begin(9600); 
   
   digitalWrite(s0,HIGH); 
   digitalWrite(s1,HIGH); 
}

void loop(){
   
  GetColors();                                    
  if (Red <=15 && Green <=15 && Blue <=15){ 
   Serial.println("COLOR: White"); 
    digitalWrite(singleRelay, LOW); 
    digitalWrite(doubleRelay1, LOW);
    digitalWrite(doubleRelay2, HIGH);
      delay(10000); 
  }                          
      
  else if (Red<Blue && Red<=Green && Red<23){   
    Serial.println("COLOR: Red");
    digitalWrite(singleRelay, LOW); 
    digitalWrite(doubleRelay1, HIGH);
    digitalWrite(doubleRelay2, LOW);
      delay(10000); 
}

   else if (Blue<Green && Blue<Red && Blue<20){
    Serial.println("COLOR: Blue");
    digitalWrite(singleRelay, LOW); 
    digitalWrite(doubleRelay1, LOW);
    digitalWrite(doubleRelay2, HIGH);
      delay(10000); 
}  
   else{
    Serial.println("COLOR: Unknown");    
    digitalWrite(singleRelay, LOW); 
    digitalWrite(doubleRelay1, LOW);
    digitalWrite(doubleRelay2, LOW);               
    delay(10000); 
   }
  delay(1000);                           
}

void GetColors()  
{    
  digitalWrite(s2, LOW);                                           
  digitalWrite(s3, LOW);                                           
   Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);       
   delay(20);  
  digitalWrite(s3, HIGH);                                        
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW   : HIGH);
  delay(20);  
  digitalWrite(s2, HIGH);  
  Green = pulseIn(out,   digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
}


