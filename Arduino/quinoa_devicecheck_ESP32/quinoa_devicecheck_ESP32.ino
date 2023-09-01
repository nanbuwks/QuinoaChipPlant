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
#define VALVE0_PIN 27
#define VALVE1_PIN 14
#define VALVE2_PIN 13
#define VALVE3_PIN 21
#define GROVE0_PIN 22
#define GROVE1_PIN 39         // VN input only
#define BEEP_PIN 2
#define WATERSENSOR0_PIN 34
#define WATERSENSOR1_PIN 35
#define WATERSENSOR2_PIN 32
#define WATERSENSOR3_PIN 33   
#define BEEP
#define SW_THERMISTOR_PIN A0  // VP input only
\
//------------------------------------------------------------------------------
void setup() {

  Serial.begin(115200);
  delay(100);
  Serial.println("WATERCONTROLLER START");
  pinMode(WATERSENSOR0_PIN, INPUT);
  pinMode(WATERSENSOR1_PIN, INPUT);
  pinMode(WATERSENSOR2_PIN, INPUT);
  pinMode(WATERSENSOR3_PIN, INPUT);
  pinMode(PUMP0_PIN, OUTPUT);
  pinMode(PUMP1_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);
  pinMode(VALVE0_PIN, OUTPUT);
  pinMode(VALVE1_PIN, OUTPUT);
  pinMode(VALVE2_PIN, OUTPUT);
  pinMode(VALVE3_PIN, OUTPUT);
  digitalWrite(PUMP0_PIN, 0);
  digitalWrite(PUMP1_PIN, 0);
  digitalWrite(BEEP_PIN, 0);
  digitalWrite(VALVE0_PIN, 0);
  digitalWrite(VALVE1_PIN, 0);
  digitalWrite(VALVE2_PIN, 0);
  digitalWrite(VALVE3_PIN, 0);

  
}

void loop()
{
 
  Serial.printf("WATERSENSOR0:%d\n",digitalRead(WATERSENSOR0_PIN ));
  Serial.printf("WATERSENSOR1:%d\n",digitalRead(WATERSENSOR1_PIN ));
  Serial.printf("WATERSENSOR2:%d\n",digitalRead(WATERSENSOR2_PIN ));
  Serial.printf("WATERSENSOR3:%d\n",digitalRead(WATERSENSOR3_PIN ));
  Serial.printf("BEEP\n");
  digitalWrite(BEEP_PIN, 1);
  delay(1000);
  digitalWrite(BEEP_PIN, 0);
  delay(1000);
  Serial.printf("PUMP0\n");
  digitalWrite(PUMP0_PIN, 1);
  delay(1000);
  digitalWrite(PUMP0_PIN, 0);
  delay(1000);
  Serial.printf("PUMP1\n");
  digitalWrite(PUMP1_PIN, 1);
  delay(1000);
  digitalWrite(PUMP1_PIN, 0);
  delay(1000);
  Serial.printf("VALVE0\n");
  digitalWrite(VALVE0_PIN, 1);
  delay(1000);
  digitalWrite(VALVE0_PIN, 0);
  delay(1000);
  Serial.printf("VALVE1\n");
  digitalWrite(VALVE1_PIN, 1);
  delay(1000);
  digitalWrite(VALVE1_PIN, 0);
  delay(1000);
  Serial.printf("VALVE2\n");
  digitalWrite(VALVE2_PIN, 1);
  delay(1000);
  digitalWrite(VALVE2_PIN, 0);
  delay(1000);
  Serial.printf("VALVE3\n");
  digitalWrite(VALVE3_PIN, 1);
  delay(1000);
  digitalWrite(VALVE3_PIN, 0);
  delay(1000);
  
  
  
}     
