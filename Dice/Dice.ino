int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};
//7개의 LED를 setup 함수 안에서 초기화 해야 하므로, 해당하는 핀의 숫자를 배열 안에 모드 놓고
//이 배열 안을 하나씩 반복하면서 초기화 하는 것이 좋다.
int dicePatterns[7][7] = {
  {0, 0, 0, 0, 0, 0, 1},    // 1
  {0, 0, 1, 1, 0, 0, 0},    // 2
  {0, 0, 1, 1, 0, 0, 1},    // 3
  {1, 0, 1, 1, 0, 1, 0},    // 4
  {1, 0, 1, 1, 0, 1, 1},    // 5
  {1, 1, 1, 1, 1, 1, 0},    // 6
  {0, 0, 0, 0, 0, 0, 0}     // BLANK
};
  
int switchPin = 9;
int blank = 6;

void setup()                 
{
  for (int i = 0; i < 7; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  //이 함수를 호출하지 않으면 보드를 재시작 할 때마다 똑같은 순서로 주사위가 굴려진다.
  randomSeed(analogRead(0));
}


void loop()
{
  if (digitalRead(switchPin))
  {
    rollTheDice();
  }
  delay(100);
}

void rollTheDice()
{
  int result = 0;
  int lengthOfRoll = random(15, 25);
  for (int i = 0; i < lengthOfRoll; i++)
  {
    result = random(0, 6);  // result will be 0 to 5 not 1 to 6
    show(result);
    delay(50 + i * 10);
  }
  for (int j = 0; j < 3; j++)
  {
    show(blank);
    delay(500);
    show(result);
    delay(500);
  }
}

void show(int result)
{

 for (int i = 0; i < 7; i++)
 {
   digitalWrite(ledPins[i], dicePatterns[result][i]);
 }
}
