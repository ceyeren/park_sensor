#include <Ultrasonic.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(0,1,8,9,10,11); //lcd çıkış pinleri
#define trig1  2//çıkış
#define echo1  3 // giriş
#define trig2  4
#define echo2  5
#define trig3  6
#define echo3  7
#define buzzer 12 

Ultrasonic ultrasonic1(trig1, echo1);
Ultrasonic ultrasonic2(trig2, echo2);
Ultrasonic ultrasonic3(trig3, echo3);



long Interval(int trig,int echo)
{
  long duration,distance;
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); // geçikmelerin amacı kusursuz çalışma için lazım çakışmayı önlemek için
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;//yukarıda pulsein komutu ile buldugumuz süreyi ses hızına bölerek mesayafeyi bulduk
  return distance;
}
void setup() 
{
  lcd.begin(16,2); //lcd başlatma komutu
  
  pinMode(trig1, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echo1, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(trig2, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echo2, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(trig3, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echo3, INPUT);// set the echo pin to input (recieve sound waves)
  
}


void loop()
{
  long distance1=Interval(trig1,echo1); // start the scan
  long distance2=Interval(trig2,echo2); // start the scan
  long distance3=Interval(trig3,echo3); // start the scan
  
  
  // lcd yazdırma kısmı
  lcd.clear();                            // ekranı temizliyor
  lcd.print("Distance in cm:");           // ekrana yazdırma
  lcd.setCursor(0,1);                     //  sagdaki 1 ya da 0 olması alt üst satırı temsil ediyor 1 alt satır demek, soldakide sütün sayısı 
  lcd.print(distance1);                   // Takes measurement from US and prints it to LCD
  lcd.setCursor(6,1);                     // Moves cursor tot he second line of display
  lcd.print(distance2);
  lcd.setCursor(12,1);                    // Moves cursor tot he second line of display
  lcd.print(distance3);
  
  if (distance1 > 25  ) {
    noTone(buzzer);// 25 büyükse no tone
  }
  if (distance2 > 25  ) {
    noTone(buzzer);
  }
  if (distance3 > 25  ) {
    noTone(buzzer);
  }
  if (distance1 >= 15 && distance1 < 25) {
    tone(buzzer, 200000, 200);
    delay(400);// ötüş süresinin sıklıgı
  }
  if (distance2 >= 15 && distance2 < 25) {
    tone(buzzer, 200000, 200);
    delay(400);
  }
  if (distance3 >= 15 && distance3 < 25) {
    tone(buzzer, 200000, 200);
    delay(400);
  }
  if (distance1 >= 10 && distance1 < 15) {
    tone(buzzer, 200000, 200);
    delay(200);
  }
  if (distance2 >= 10 && distance2 < 15) {
    tone(buzzer, 200000, 200);
    delay(200);
  }
  if (distance3 >= 10 && distance3 < 15) {
    tone(buzzer, 200000, 200);
    delay(200);
  }
  if (distance1 >= 6  && distance1 < 10  ) {
    tone(buzzer, 200000, 200);
    delay(50);
  }
  if (distance2 >= 6 && distance2 < 10  ) {
    tone(buzzer, 200000, 200);
    delay(50);
  }
  if (distance3 >= 6  && distance3 < 10  ) {
    tone(buzzer, 200000, 200);
    delay(50);
  }
    if (distance1 < 6  ) {
    tone(buzzer, 200000,10000); // delay yapmadıgımız için sürekli ötücek
  }
  if (distance2 < 6  ) {
    tone(buzzer, 200000,10000);
  }
  if (distance3 < 6  ) {
    tone(buzzer, 200000,10000);
  }


  

}

