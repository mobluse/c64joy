// Atari/C64 joystick DE9/DB9 to USB converter that runs on Arduino Leonardo, Olimexino-32U4 etc.
// Should work with THEC64 MINI 1.2.0+, Commodore 64 on Archive.org, VICE for Linux, and WinVICE.
// Never tested! It does compile with Arduino 1.8.8 (Windows Store 1.8.19.0).

// Preferred (left) fire button is different on different emulators:
// THEC64 MINI: Numpad 5 (with or without Num Lock), but Insert or Numpad 0 works.
// Archive.org: Insert or Numpad 0.
// WinVICE/VICE: Right Ctrl, but others can be configured.

// You may implement Right Fire, TL, TR, A, B, C, and Menu for THEC64 MINI using extra buttons
//   connected to the Arduino.
// References:
// https://retrogames.biz/app/uploads/THEC64-User-Guide-June-2018-2018-06-15-EN-US.pdf
// https://retrogames.biz/support/virtual-joystick/
// https://retrogames.biz/support/file-loader/
// https://www.thec64minizone.com/cjm-configuration-file-tool/
// https://create.arduino.cc/projecthub/fpfaffendorf/commodore-64-joystick-usb-adapter-c64joy-fc2389
// The above site has a Fritzing fzz-file with schematic, but check a C64 manual -- only cables needed.
// http://forum.arduino.cc/index.php?topic=179548.0
// https://www.arduino.cc/en/Reference/KeyboardModifiers

#include <Keyboard.h>

#define JOY_UP        11
#define JOY_DOWN      10
#define JOY_LEFT      9
#define JOY_RIGHT     8
#define JOY_BUTTON    12

/* Numpad keys:
220 '\334' Keypad /
221 '\335' Keypad *
222 '\336' Keypad -
223 '\337' Keypad +
224 '\340' Keypad Enter
225 '\341' Keypad 1 and End
226 '\342' Keypad 2 and Down Arrow
227 '\343' Keypad 3 and PageDn
228 '\344' Keypad 4 and Left Arrow
229 '\345' Keypad 5
230 '\346' Keypad 6 and Right Arrow
231 '\347' Keypad 7 and Home
232 '\350' Keypad 8 and Up Arrow
233 '\351' Keypad 9 and PageUp
234 '\352' Keypad 0 and Insert
235 '\353' Keypad . and Delete
*/

#define NUMPAD_UP     '\350'
#define NUMPAD_DOWN   '\342'
#define NUMPAD_LEFT   '\344'
#define NUMPAD_RIGHT  '\346'

// Left Fire alternatives
#define NUMPAD_5      '\345'
#define NUMPAD_INS    '\352'
// KEY_RIGHT_CTRL
// TODO: You could choose which by tilting the joystick in different directions at start.

// Right Fire
#define NUMPAD_ENTER  '\340'

// TL and TR
#define NUMPAD_DIV    '\334'
#define NUMPAD_MUL    '\335'

// A, B, C
// KEY_F9
// KEY_F10
// KEY_F11

// Menu
#define NUMPAD_DEL    '\353'

void setup() {

  Keyboard.begin();

  pinMode(JOY_BUTTON, INPUT_PULLUP);
  pinMode(JOY_UP, INPUT_PULLUP);
  pinMode(JOY_DOWN, INPUT_PULLUP);
  pinMode(JOY_LEFT, INPUT_PULLUP);
  pinMode(JOY_RIGHT, INPUT_PULLUP);

}

void loop() {

  if (!digitalRead(JOY_BUTTON)) { Keyboard.press(NUMPAD_INS); }
  else { Keyboard.release(NUMPAD_INS); }
  
  if (!digitalRead(JOY_UP)) { Keyboard.press(NUMPAD_UP); }
  else {  Keyboard.release(NUMPAD_UP); }

  if (!digitalRead(JOY_DOWN)) { Keyboard.press(NUMPAD_DOWN); }
  else {  Keyboard.release(NUMPAD_DOWN); }

  if (!digitalRead(JOY_LEFT)) { Keyboard.press(NUMPAD_LEFT); }
  else {  Keyboard.release(NUMPAD_LEFT); }

  if (!digitalRead(JOY_RIGHT)) { Keyboard.press(NUMPAD_RIGHT); }
  else {  Keyboard.release(NUMPAD_RIGHT); }

}
