unsigned long Last_time = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
  int AD_c = analogRead(A2) ;
  int PWM = map(AD_c, 0, 1023, 0, 255);
  if (AD_c > 512) {
    digitalWrite(2,1);
  }else{
    digitalWrite (2,0);
  }
  if(millis()-Last_time > 1000){
    Serial.print("ADC: ");
    Serial.print(AD_c);
    Serial.print(" PWM: ");
    Serial.println(PWM);
    Last_time = millis();
  }

}
