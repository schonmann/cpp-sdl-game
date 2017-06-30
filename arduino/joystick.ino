const int SW_pin = 2;
const int Y_pin = 0;
const int X_pin = 1;
const int origin = 512;

const int HZ = 60;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int sw = digitalRead(SW_pin);
  //Serial.print("sw: ");
  Serial.println(sw);
  int x = analogRead(X_pin) - origin;
  //Serial.print("x: ");
  Serial.println(x);
  int y = analogRead(Y_pin) - origin;
  //Serial.print("y: ");
  Serial.println(y);
  delay(1000/HZ);
}
