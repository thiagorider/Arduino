int pot=0
void setup() {
Serial.begin(9600);
pinMode(pot,INPUT):

}

void loop()  {
int valor;
valor= analogRead(pot);
Serial.println(valor);

}

