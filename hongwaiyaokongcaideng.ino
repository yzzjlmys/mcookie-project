#include <IRremote.h>
 
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // 启动红外解码
    Serial.println("Initialisation complete.");
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    digitalWrite(10,HIGH);}
    else
        digitalWrite(10,LOW);
    delay(100);       //防止串口写入速度过
    irrecv.resume();  //接收下一个值
}
