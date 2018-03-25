// Trig接Arduino板的Digital 5口，触发测距；Echo接Digital 4口，接收距离信号。

int inputPin=12; // 定义超声波信号接收接口
int outputPin=11; // 定义超声波信号发出接口
int buzzerPin=13;
int DISTANCE = 5540;  //6000out   5540door
int LONGDISTANCE = 6000;
void setup()
{
    Serial.begin(9600);
    pinMode(buzzerPin,OUTPUT);
    pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT);
}
int  rangeFinder()
{
      digitalWrite(outputPin, LOW); // 使发出发出超声波信号接口低电平2μs
      delayMicroseconds(2);
      digitalWrite(outputPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
      delayMicroseconds(10);
      digitalWrite(outputPin, LOW); // 保持发出超声波信号接口低电平
      int distance = pulseIn(inputPin, HIGH); // 读出脉冲时间
      //distance= distance/58; // 将脉冲时间转化为距离（单位：厘米）
      Serial.println(distance); //输出距离值
      delay(50);
      return distance;
}
void loop()

{
  int distance = rangeFinder();
  Serial.println(distance);
  if (distance <=DISTANCE ||distance >=LONGDISTANCE)
  {
        delay(10000);
        int newDistance = rangeFinder();
        if(newDistance <= DISTANCE ||newDistance >=LONGDISTANCE){ 
          digitalWrite(buzzerPin,HIGH); 
          delay(3000);
          digitalWrite(buzzerPin,LOW);
           Serial.println(6666);
          Serial.println(distance);
          
          }
        else {digitalWrite(buzzerPin,LOW);Serial.println(distance);}
  }  else {
        digitalWrite(buzzerPin,LOW);
        Serial.println(distance);
    }
}







