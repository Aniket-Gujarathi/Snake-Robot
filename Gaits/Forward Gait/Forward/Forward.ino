#include <Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;                  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  servo1.attach(10);  //10  // attaches the servo on pin 9 to the servo object
  servo2.attach(11); //11 
  servo3.attach(6);  // 6
  servo4.attach(9); // 9
  Serial.begin(9600);

  servo1.write(90);   //3          
  servo2.write(90);   //1
  servo3.write(90); //4              
  servo4.write(90);  // 2
}

// the loop function runs over and over again forever

void loop() {
  if(Serial.available())
  {
    char state  = Serial.read();
    Serial.print(state);
   if(state=='a'){
      delay(5000);
      int m = 0;
      while(1)
      {
      for(int j=0;j<100;j++)
      {
       int m3 = int(90-90*sin((j*0.01)));
       int m1 = int(90-45*sin((j*0.01)));

       //int m1 = 90-int(90*j*0.01);
       //int m3 = 90+int(-m1-asin(0.88)*sin(m1));
       Serial.println(m3);
       int m7 = int(m3);
       Serial.println( m7);
       float h1 = 90;
       float h2 = 90; 
       servo1.write(m1);             
       servo2.write(h1);
       servo3.write(m3);             
       servo4.write(h2); 
       delay(5); 
      }
       
       servo1.write(45);             
       servo2.write(90);
       servo3.write(90);             
       servo4.write(90);
       m = m+1;
       delay(150);
       }
      }
      
     delay(5000);
    
  }
}
  
