/* Version 202304
#define PUMP0_PIN 27
#define PUMP1_PIN 26
#define FAN_PIN 22
#define BEEP_PIN 2
#define WATERSENSOR_PIN 25
#define BEEP
*/


/* Version 202304 */
#define PUMP0_PIN 25
#define PUMP1_PIN 26
#define BULB0_PIN 27
#define BULB1_PIN 14
#define BULB2_PIN 13
#define BULB3_PIN 21
#define GROVE0_PIN 22
#define GROVE1_PIN 39         // VN input only
#define BEEP_PIN 2
#define WATERSENSOR0_PIN 34
#define WATERSENSOR0_PIN 35
#define WATERSENSOR0_PIN 32
#define WATERSENSOR0_PIN 33   
#define BEEP
#define SW_THERMISTOR_PIN A0  // VP input only

void beep(int millis) {
  Serial.printf("beep:%d", millis);
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
  digitalWrite(FAN_PIN, 0);
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
