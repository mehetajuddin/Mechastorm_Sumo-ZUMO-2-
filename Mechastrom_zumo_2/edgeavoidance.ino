void edge_a(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
  int state1 = digitalRead(a);
  int state2 = digitalRead(b);
  int state3 = digitalRead(c);
  if (state1 == HIGH) {
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    analogWrite(h, 255);
    analogWrite(j, 255);
  }

  if (state2 == HIGH && state3 == HIGH) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(e, LOW);
    analogWrite(f, 255);
    analogWrite(g, 255);
  }

  if (state2 == HIGH) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(e, LOW);
    analogWrite(f, 255);
    analogWrite(g, 255);
  }

  if (state3 == HIGH) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(e, LOW);
    analogWrite(f, 255);
    analogWrite(g, 255);
  }
}