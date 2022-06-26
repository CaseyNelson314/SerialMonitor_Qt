/**
   Demonstration of serial communication
   When 'a' is sent from the application side,
   Switching the output of the on-board LEDs
*/

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  Serial.print("hogehoge");   //send character
  Serial.print("\n");
//  Serial.print(millis());     //send time data
//  Serial.print("\t");
//  Serial.print(millis());     //hoge?!?!?!?
//  Serial.print("\n");

  const char buf = Serial.read();   // get character

  static bool flag;
  flag ^= (buf == 'a');   //出力反転

  digitalWrite(LED_BUILTIN, flag);

  //  delay(10);

}
