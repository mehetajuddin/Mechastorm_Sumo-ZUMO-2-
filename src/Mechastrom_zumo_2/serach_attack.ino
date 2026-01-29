void search(int a, int b, float c, int d, int e, int f, int g, int h, int j) {
  bool attack_2 = false;  // alligning the bot with the enemy
  bool attack_3 = false;  // alligning the bot with the enemy

  // attack! with the value of vl53l0x.
  if (c >= 3.0 && c <= 30.0) {
    attack1(d, e, f, g, h, j);
  }
  // taking the value of right sensor and alligning the bot with the value of vl53l0x and attacking!.
  if (a > 3 && a <= 30) {
    if (c >= 3.0 && c <= 30.0) {

      attack_2 = false;
    } else {
      attack_2 = true;
    }
    if (attack_2 == true) {
      attack2(d, e, f, g, h, j);
    }
  }
  if (b > 3 && b <= 30) {
    if (c >= 3.0 && c <= 30.0) {

      attack_3 = false;
    } else {
      attack_3 = true;
    }
    if (attack_3 == true) {
      attack3(d, e, f, g, h, j);
    }
  }

  else {
    //add else code!
  }
}
