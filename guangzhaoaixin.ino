#include "U8glib.h"
int a =100;        //此处需是环境基础亮度变量，请查看自己的亮度数值，填写到此处数值要略大于所测得的数据但小于灯光下的数据


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);  // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)

//static unsigned char u8g_logo_bits[] = {
void setup ()
{
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}
void loop()
{
  int n = analogRead(A0);        //读取模拟口A0数值
  Serial.println(n);
  if (n>= a )                   //对光线强度进行判断，如果比我们的预设值小就关闭LED,否则就点亮
  {
  
    u8g.firstPage();
  do {
static unsigned char u8g_logo_bits[] U8G_PROGMEM = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,
0xFF,0xFF,0xF7,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0xFE,0xFF,0x1F,0x00,0xFC,0xFF,0xFF,
0xFF,0x0F,0x00,0xF8,0xFF,0x0F,0x00,0xF8,0xFF,0xFF,0xFF,0x07,0x00,0xF0,0xFF,0x07,
0x00,0xF0,0xFF,0xFF,0xFF,0x03,0x7F,0xC0,0xFF,0x01,0x7F,0xE0,0xFF,0xFF,0xFF,0xC1,
0xFF,0xC1,0xFF,0xC1,0xFF,0xC0,0xFF,0xFF,0xFF,0xF0,0xFF,0x07,0x7F,0xF0,0xFF,0x87,
0xFF,0xFF,0xFF,0xF0,0xFF,0x0F,0x7F,0xF8,0xFF,0x87,0xFF,0xFF,0x7F,0xFC,0xFF,0x1F,
0x3E,0xFC,0xFF,0x1F,0xFF,0xFF,0x3F,0xFC,0xFF,0x3F,0x1C,0xFC,0xFF,0x1F,0xFE,0xFF,
0x3F,0xFC,0xFF,0x3F,0x0C,0xFE,0xFF,0x1F,0xFE,0xFF,0x3F,0xFE,0xFF,0x7F,0x08,0xFF,
0xFF,0x3F,0xFE,0xFF,0x1F,0xFF,0xFF,0xFF,0x80,0xFF,0xFF,0x7F,0xFC,0xFF,0x1F,0xFF,
0xFF,0xFF,0x80,0xFF,0xFF,0x7F,0xFC,0xFF,0x1F,0xFF,0xFF,0xFF,0x80,0xFF,0xFF,0x7F,
0xFC,0xFF,0x1F,0xFF,0xFF,0xFF,0xC1,0xFF,0xFF,0x7F,0xF8,0xFF,0x0F,0xFF,0xFF,0xFF,
0xE3,0xFF,0xFF,0x7F,0xF8,0xFF,0x0F,0xFF,0xFF,0xFF,0xE3,0xFF,0xFF,0x7F,0xF8,0xFF,
0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xF8,0xFF,0x0F,0xFF,0xFF,0xF8,0xFF,0x8F,
0xFF,0x7F,0xF8,0xFF,0x0F,0xFF,0x1F,0xC0,0xFF,0x01,0xFC,0x7F,0xF8,0xFF,0x0F,0xFF,
0x07,0x00,0x7F,0x00,0xF0,0x7F,0xF8,0xFF,0x0F,0xFF,0x07,0x00,0x7F,0x00,0xF0,0x7F,
0xF8,0xFF,0x1F,0xFF,0x83,0x0F,0x1C,0xF8,0xC0,0x7F,0xF8,0xFF,0x1F,0xFF,0xE1,0x3F,
0x1C,0xFC,0xC3,0x7F,0xFC,0xFF,0x1F,0xFF,0xE1,0x7F,0x08,0xFF,0xC7,0x7F,0xFC,0xFF,
0x1F,0xFF,0xF1,0xFF,0x08,0xFF,0xC7,0x7F,0xFC,0xFF,0x3F,0xFE,0xF8,0xFF,0x80,0xFF,
0x8F,0x3F,0xFE,0xFF,0x3F,0xFE,0xF8,0xFF,0x80,0xFF,0x8F,0x3F,0xFE,0xFF,0x3F,0x7C,
0xF8,0xFF,0xC1,0xFF,0x0F,0x1F,0xFE,0xFF,0x3F,0x7C,0xF8,0xFF,0xE3,0xFF,0x0F,0x1F,
0xFE,0xFF,0x7F,0x7C,0xF8,0xFF,0xF3,0xFF,0x0F,0x1F,0xFE,0xFF,0x7F,0x7C,0xF8,0xFF,
0xFF,0xFF,0x0F,0x1F,0xFF,0xFF,0xFF,0x78,0xF8,0x03,0x7E,0xE0,0x0F,0x8F,0xFF,0xFF,
0xFF,0xF0,0xF8,0x01,0x3C,0x80,0x0F,0x87,0xFF,0xFF,0xFF,0xF0,0xF8,0x30,0x08,0x06,
0x8F,0x87,0xFF,0xFF,0xFF,0xF0,0xF8,0xF0,0x00,0x0F,0x8F,0x87,0xFF,0xFF,0xFF,0xE3,
0x71,0xFC,0x81,0x1F,0xC7,0xC3,0xFF,0xFF,0xFF,0xC3,0x71,0xFC,0x81,0x1F,0xC6,0xE1,
0xFF,0xFF,0xFF,0xC3,0x71,0xFC,0x83,0x3F,0xC6,0xE1,0xFF,0xFF,0xFF,0x87,0x61,0xFE,
0xC3,0x3F,0xC2,0xF0,0xFF,0xFF,0xFF,0x0F,0x61,0xFE,0xE3,0x3F,0x42,0xF0,0xFF,0xFF,
0xFF,0x0F,0x42,0xFE,0xFF,0x3F,0x20,0xF8,0xFF,0xFF,0xFF,0x1F,0x46,0xFC,0xFF,0x1F,
0x30,0xFC,0xFF,0xFF,0xFF,0x3F,0x04,0xFC,0x3C,0x1F,0x10,0xFE,0xFF,0xFF,0xFF,0x3F,
0x00,0x78,0x00,0x1E,0x00,0xFF,0xFF,0xFF,0xFF,0x7F,0x10,0x30,0x00,0x18,0x04,0xFF,
0xFF,0xFF,0xFF,0xFF,0x00,0x30,0x00,0x08,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x10,
0xC3,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x00,0xC3,0x00,0xE0,0xFF,0xFF,0xFF,
0xFF,0xFF,0x07,0x00,0xFE,0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0x7E,0x00,
0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0x7C,0x00,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,
0x3F,0x00,0x3C,0x00,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x80,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x0F,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x00,0xFE,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,//C:\Users\yzzjlmys\Desktop\爱心（自己画的）.bmp0
 };


long timer;

int pkj=0;

  u8g.setFont(u8g_font_7x14);

  u8g.setPrintPos(pkj, 64); 

  u8g.drawXBMP( 0, 0, 73, 72, u8g_logo_bits);
  }
  while( u8g.nextPage() );
 }
 }
 
