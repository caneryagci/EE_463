int read_data = A0;
int pwm_pin = 9;
float duty_cycle = 0;
float j = 0;
float inputValue = 0;
int refsig = 200; //for converting the analog signal coming from hall sensor to digital through arduino code
int val;//the digital value of the incoming analog signals
int prev_val = 0;
int t, cur_t; //time variables
float rpm = 0;
float duty=0;
float ts = 1/5000;

void setup() {
  
  Serial.begin(9600);
  pinMode(pwm_pin,OUTPUT);
  pinMode(read_data,INPUT);
  //setPwmFrequency(9,2);
 
}

/*void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
*/
void loop() {   
            
      j= analogRead(read_data);               
      duty = j/1024*100;
      Serial.println(duty);

      if(duty<10){ 
      digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(20);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(180);
      }
      else if(duty >= 10 && duty < 20 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(40);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(160);
      }
       else if(duty >= 20 && duty < 30 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(60);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(140);
      }
       else if(duty >= 30 && duty < 40 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(80);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(120);
      }
       else if(duty >= 40 && duty < 50 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(100);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(100);
      }
       else if(duty >= 50 && duty < 60 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(120);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(80);
      }
       else if(duty >= 60 && duty < 70){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(140);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(70);
      }
       else if(duty >= 70 && duty < 80){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(160);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(40);
      }
       else if(duty >= 80 && duty < 90 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(180);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(20);
      }
       else if(duty >= 90 ){
        digitalWrite(pwm_pin, HIGH);
      delayMicroseconds(190);
      digitalWrite(pwm_pin, LOW);
      delayMicroseconds(10);
      }
      
              
        }
