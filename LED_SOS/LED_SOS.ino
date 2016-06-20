
int ledPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //s
  flash(200); flash(200); flash(200);
  //글자와 글자 사이에는 -만큼의 간격이 있어야 하므로 LED를 300ms 만큼 지연한다.
  delay(300);
  //o
  flash(200); flash(200); flash(200);
  //s
  flash(200); flash(200); flash(200);
  //반복전 1초간 대기
  delay(1000);
}
void flash(int duration)
{
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}
