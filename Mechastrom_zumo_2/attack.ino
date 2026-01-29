void attack1(int a, int b, int c, int e, int f, int g) {

  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(e, LOW);
  analogWrite(f, 255);
  analogWrite(g, 255);
}

void attack2(int a, int b, int c, int e, int f, int g) {

  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(e, HIGH);
  analogWrite(f, 255);
  analogWrite(g, 127);
}

void attack3(int a, int b, int c, int e, int f, int g) {

  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(e, LOW);
  analogWrite(f, 127);
  analogWrite(g, 255);
}