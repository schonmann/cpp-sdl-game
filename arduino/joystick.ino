
//Buffer para ativação das teclas.
uint8_t buf[8] = { 0 };
//Botão do analógico.
const int SW_pin = 2;
//Eixo Y.
const int Y_pin = 0;
//Eixo X.
const int X_pin = 1;
//Origem.
const int origin = 512;
//Frequência de atualização.
const int HZ = 60;

//Scancodes das teclas.
#define KEY_UP 82
#define KEY_RIGHT 79
#define KEY_DOWN 81
#define KEY_LEFT 80

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int sw = digitalRead(SW_pin);
  int x = analogRead(X_pin) - origin;

  if(x > 200) pressKey(KEY_RIGHT);
  else if (x < -200) pressKey(KEY_LEFT);
  
  int y = analogRead(Y_pin) - origin;
  
  if(y > 200) pressKey(KEY_UP);
  else if (y < -200) pressKey(KEY_DOWN);

  delay(1000/HZ);
}

void pressKey(int key)
{
  buf[2] = key;
  Serial.write(buf, 8);
  buf[2] = 0;
  Serial.write(buf, 8);
}