//Desert Slog
//Version 1.0
//(c) creeperspeak 2017
//@creeperspeak

#include <Arduboy2.h>
//#include "Character.h"

Arduboy2 arduboy;
//Character character;

byte sprite_num = 0;
byte sprite_timer = 0;
byte x_position = 60;
byte y_position = 56;

const unsigned char sprite[] PROGMEM = {
  0x00, 0xc0, 0xa0, 0x3c, 0xec, 0x93, 0x23, 0x00
};
const unsigned char sprite2[] PROGMEM = {
  0x00, 0xc0, 0x20, 0xfc, 0x8f, 0x13, 0x20, 0x00
};
const unsigned char sprite3[] PROGMEM = {
  0x00, 0x00, 0xe0, 0xbc, 0x0c, 0x13, 0x23, 0x00
};

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.display();
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  arduboy.setCursor(0,0);
//  int s = 0;
//  if (arduboy.pressed(UP_BUTTON)) {
//    arduboy.print("UP");
//    s = 1;
//  } else if (arduboy.pressed(DOWN_BUTTON)) {
//    arduboy.print("DOWN");
//    s = 2;
//  } else if (arduboy.pressed(LEFT_BUTTON)) {
//    arduboy.print("LEFT");
//  } else if (arduboy.pressed(RIGHT_BUTTON)) {
//    arduboy.print("RIGHT");
//  } else if (arduboy.pressed(A_BUTTON)) {
//    arduboy.print("A");
//  } else if (arduboy.pressed(B_BUTTON)) {
//    arduboy.print("B");
//  }
//  if (s == 0) {
//    arduboy.drawBitmap(20,20,sprite,8,8,WHITE);
//  } else if (s == 1) {
//    arduboy.drawBitmap(20,20,sprite2,8,8,WHITE);
//  } else if (s == 2) {
//    arduboy.drawBitmap(20,20,sprite3,8,8,WHITE); 
//  }
//  character.draw();
  drawCharacter();
//  arduboy.print(sprite_num);
  arduboy.display();
}

void drawCharacter() {
  if (sprite_timer == 10) {
    sprite_num++;
    sprite_timer = 0;
  }
  if (sprite_num == 3) {
    sprite_num = 0;
  }
  switch (sprite_num) {
    case 0:
      arduboy.drawBitmap(x_position, y_position, sprite, 8, 8, WHITE);
      break;
    case 1:
      arduboy.drawBitmap(x_position, y_position, sprite2, 8, 8, WHITE);
      break;
    case 2:
      arduboy.drawBitmap(x_position, y_position, sprite3, 8, 8, WHITE);
      break;
  }
  sprite_timer++;
}

