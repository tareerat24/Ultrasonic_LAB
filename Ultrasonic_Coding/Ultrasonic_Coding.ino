#define TRIG  5 // Trig pin pin5
#define ECHO  35 // Echo pin

long microsecondsToCentimeters(long microseconds)     // function การแปลงหน่วยให้เป็น เซนติเมตร
{
return microseconds / 29 / 2;    // การแปลงหน่วยที่อ่านได้ ให้เป็นเซนติเมตร
}

void setup() {

  Serial.begin(115200);                // เปิดพอร์ตสื่อสาร serial monitor
  Serial.println("Hello, Ultrasonic Sensor!");

  pinMode(TRIG, OUTPUT);               // กำหนดให้ trig เป็น output
  pinMode(ECHO, INPUT);                // กำหนดให้ echo เป็น input

}

void loop() {

 long duration, cm;
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(5);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    cm = microsecondsToCentimeters(duration);

    Serial.print("distance =  ");         // กำหนดชื่อ
    Serial.println(cm);                   // ให้แสดงค่าที่ อ่านได้
    delay(100);
}





