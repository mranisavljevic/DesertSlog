//Desert Slog
//Version 1.0
//(c) creeperspeak 2017
//@creeperspeak

#include <Arduboy2.h>
#include "Character.h"

Arduboy2 arduboy;
Character character;

const unsigned char sprite[] PROGMEM = {
  0x06, 0x06, 0x18, 0x18, 0x14, 0x3A, 0x48, 0x6C
};
const unsigned char sprite2[] PROGMEM = {
  0x0C, 0x0C, 0x18, 0x18, 0x14, 0x32, 0x50, 0x58
};
const unsigned char sprite3[] PROGMEM = {
  0x06, 0x06, 0x18, 0x18, 0x14, 0x32, 0x20, 0x30
};

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.display();
}

void loop() {
  arduboy.clear();
  arduboy.setCursor(0,0);
  int s = 0;
  if (arduboy.pressed(UP_BUTTON)) {
    arduboy.print("UP");
    s = 1;
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    arduboy.print("DOWN");
    s = 2;
  } else if (arduboy.pressed(LEFT_BUTTON)) {
    arduboy.print("LEFT");
  } else if (arduboy.pressed(RIGHT_BUTTON)) {
    arduboy.print("RIGHT");
  } else if (arduboy.pressed(A_BUTTON)) {
    arduboy.print("A");
  } else if (arduboy.pressed(B_BUTTON)) {
    arduboy.print("B");
  }
  if (s == 0) {
    arduboy.drawBitmap(20,20,sprite,8,8,WHITE);
  } else if (s == 1) {
    arduboy.drawBitmap(20,20,sprite2,8,8,WHITE);
  } else if (s == 2) {
    arduboy.drawBitmap(20,20,sprite3,8,8,WHITE); 
  }
  arduboy.display();
}

void drawCharacter() {
  
}

