int a =100;        //亮度值
void setup ()
{
    Serial.begin(115200);    //设置串口波特率
    pinMode(10,OUTPUT);  //设置输出口
}
void loop()
{
    int n = analogRead(A3);   //读取模拟口A3，获取光强
    Serial.println(n);               // 用于IDE串口观察窗
    if (n<= a )                         //对光强进行判断
        digitalWrite(10,HIGH);
    else
        digitalWrite(10,LOW);
    delay(100);       //防止串口写入速度过快
}
