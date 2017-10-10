  int fio1 = 1;
  int fio2 = 2;
  int fio3 = 3;
  int fio4 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode (fio1, OUTPUT);
  pinMode (fio2, OUTPUT);
  pinMode (fio3, OUTPUT);
  pinMode (fio4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite (fio1, HIGH);
  digitalWrite (fio2, HIGH);
  digitalWrite (fio3, HIGH);
  digitalWrite (fio4, LOW);
  delay (10);
  digitalWrite (fio1, HIGH);
  digitalWrite (fio2, LOW);
  digitalWrite (fio3, HIGH);
  digitalWrite (fio4, HIGH);
  delay (10);
  digitalWrite (fio1, LOW);
  digitalWrite (fio2, HIGH);
  digitalWrite (fio3, HIGH);
  digitalWrite (fio4, HIGH);
  delay (10);
  digitalWrite (fio1, HIGH);
  digitalWrite (fio2, HIGH);
  digitalWrite (fio3, LOW);
  digitalWrite (fio4, HIGH);
  delay (10);  
}
