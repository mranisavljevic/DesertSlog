//Character Class

class Character {
  public:
    Character();
    void draw();
  private:
    byte x_position;
    byte y_position;
    byte sprite_timer;
    byte sprite_num;
};

const unsigned char sprite[] PROGMEM = {
  0x00, 0xc0, 0xa0, 0x3c, 0xec, 0x93, 0x23, 0x00
};
const unsigned char sprite2[] PROGMEM = {
  0x00, 0xc0, 0x20, 0xfc, 0x8f, 0x13, 0x20, 0x00
};
const unsigned char sprite3[] PROGMEM = {
  0x00, 0x00, 0xe0, 0xbc, 0x0c, 0x13, 0x23, 0x00
};

Character::Character() {
  x_position = 124;
  y_position = 56;
  sprite_num = 0;
  sprite_timer = 0;
}

void Character::draw() {
  byte s = sprite_num;
  if (sprite_timer == 20) {
    s++;
    sprite_timer = 0;
  }
  if (s == 3) {
    s = 0;
  }
  switch (s) {
    case 0:
      arduboy.drawBitmap(x_position, y_position, sprite, 8, 8, WHITE);
      break;
    case 1:
      arduboy.drawBitmap(x_position, y_position, sprite1, 8, 8, WHITE);
      break;
    case 2:
      arduboy.drawBitmap(x_position, y_position, sprite2, 8, 8, WHITE);
      break;
  }
  sprite_timer++
}

