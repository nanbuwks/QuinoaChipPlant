
#define PUMP0_PIN 8  // 給水用
#define PUMP1_PIN 11 // 排水用
#define SW_THERMISTOR_PIN A4
#define BEEP_PIN 15
#define WATERSENSOR_PIN 19
#define BEEP

void beep(int millis) {
  Serial.print("beep:"+ millis);
#ifdef BEEP
  digitalWrite(BEEP_PIN, HIGH);
#endif
  delay(millis);
  digitalWrite(BEEP_PIN, LOW);
}
void pi() {
  beep(200);
}
void pipi() {
  beep(200);
  delay(50);
  beep(100);

}
void pipipipi() {
  beep(200);
  delay(50);
  beep(100);
  delay(100);
  beep(100);
  delay(100);
  beep(100);

}
void peee() {
  beep(1000);
}


void runPUMP0() {
  digitalWrite(PUMP0_PIN, HIGH);
}
void stopPUMP0() {
  digitalWrite(PUMP0_PIN, LOW);
}

void flush(int flushtime){
  
  Serial.println("排水");
  digitalWrite(PUMP1_PIN, 0);
  delay(flushtime);
  digitalWrite(PUMP1_PIN, 1);
  
  
}
//------------------------------------------------------------------------------
void setup() {

  Serial.begin(115200);
  delay(100);
  Serial.println("WATERCONTROLLER START");
  pinMode(WATERSENSOR_PIN, INPUT_PULLUP);
  pinMode(PUMP0_PIN, OUTPUT);
  pinMode(PUMP1_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);
  digitalWrite(PUMP1_PIN, 1);
  digitalWrite(PUMP0_PIN, 0);
  digitalWrite(SW_THERMISTOR_PIN, 0);
  digitalWrite(BEEP_PIN, 0);
  pipi();
  Serial.println( digitalRead(WATERSENSOR_PIN));
  // 5分排水
  flush(3000);

  
}

void dummy()
{

  Serial.println("給水");
  digitalWrite(PUMP0_PIN, 1);
  delay(3000);
  digitalWrite(PUMP0_PIN, 0);
      
  Serial.println("排水");
  digitalWrite(PUMP1_PIN, 0);
  delay(3000);
  digitalWrite(PUMP1_PIN, 1);
}
void loop(){
  
    // 給水
  while ( 1 == digitalRead(WATERSENSOR_PIN )){   // 水位が充たされてなければこのループを回る
    Serial.println("給水");
    digitalWrite(PUMP0_PIN, 1);
    while ( 1 == digitalRead(WATERSENSOR_PIN )){ // 水位が充たされるまでこのループを回る
      delay(100);
  }}
  while ( 0 == digitalRead(WATERSENSOR_PIN )){
    Serial.println("完了");
    digitalWrite(PUMP0_PIN, 0);
    while ( 0 == digitalRead(WATERSENSOR_PIN )){  // 水位が充たされていたらこのループを回る
      delay(100);
      int check = analogRead(SW_THERMISTOR_PIN);  // ボタンが押されたら
      if (0 == check) flush(3000);                // 一定時間排水
  
  }}
  delay(100);
}     
