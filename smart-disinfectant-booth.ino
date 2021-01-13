#define SENSOR_PIN 12
#define BUZZER 4
#define POMPA_PIN 2
#define LED 3
#define SAKLAR 2

 
void setup(){
 pinMode(POMPA_PIN, OUTPUT); 
 digitalWrite(POMPA_PIN, HIGH);
 pinMode(BUZZER,OUTPUT);
 pinMode(LED, OUTPUT);
 pinMode(SENSOR_PIN, INPUT); 
 Serial.begin(9600);
}
 
void loop(){
 int count = 0;
 while(digitalRead(SENSOR_PIN) == LOW){
   count++;
   buzzer();
   Serial.println(count);
   if(count>=8){
      fix();
      pompa();
      digitalWrite(POMPA_PIN, HIGH);
      delay(2000);
    }
  }
  while(digitalRead(SENSOR_PIN) == HIGH){
    count = 0; 
    digitalWrite(POMPA_PIN, HIGH);
    //     digitalWrite(LED, LOW);
      
    }
}
void pompa (){
  int waktu =0;
  while(waktu < 700){
     waktu+=1;
     Serial.println(waktu);
     digitalWrite(POMPA_PIN, LOW);
    // digitalWrite(LED, HIGH);
      if (waktu > 700){
        break;
        }
    }
  }
void buzzer(){
  digitalWrite(BUZZER,HIGH);
  delay(25);
  digitalWrite(BUZZER,LOW);
  delay(25);
  }
void fix(){
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
  delay(100);
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
  delay(100);
  }
