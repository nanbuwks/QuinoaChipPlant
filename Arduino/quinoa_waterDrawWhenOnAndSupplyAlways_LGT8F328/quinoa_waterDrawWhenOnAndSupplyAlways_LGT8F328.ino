
#define PUMP0_PIN 8
#define PUMP1_PIN 11
#define SW_THERMISTOR_PIN 18
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
//------------------------------------------------------------------------------
void setup() {

  Serial.begin(115200);
  delay(100);
  Serial.println("WATERCONTROLLER START");
  pinMode(WATERSENSOR_PIN, INPUT_PULLUP);
  pinMode(PUMP0_PIN, OUTPUT);
  pinMode(PUMP1_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);
  digitalWrite(PUMP0_PIN, 0);
  digitalWrite(PUMP1_PIN, 0);
  digitalWrite(SW_THERMISTOR_PIN, 0);
  digitalWrite(BEEP_PIN, 0);
  pipi();
  Serial.println( digitalRead(WATERSENSOR_PIN));
  // 5分排水
  Serial.println("排水");
  digitalWrite(PUMP0_PIN, 1);
  delay(300000);
  digitalWrite(PUMP0_PIN, 0);

  
}

void loop()
{
    // 給水
  while ( 1 == digitalRead(WATERSENSOR_PIN )){
    Serial.println("給水");
    digitalWrite(PUMP1_PIN, 1);
    while ( 1 == digitalRead(WATERSENSOR_PIN )){
      delay(1000);
  }}
  while ( 0 == digitalRead(WATERSENSOR_PIN )){
    Serial.println("完了");
    digitalWrite(PUMP1_PIN, 0);
    while ( 0 == digitalRead(WATERSENSOR_PIN )){
      delay(1000);
  }}
  delay(1000);
}     
