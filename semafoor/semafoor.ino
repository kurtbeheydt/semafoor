// https://playground.arduino.cc/Main/PS2Keyboard/

#include <Servo.h>
#include <PS2Keyboard.h>

const int wachttijd_tussen_letters = 500;

const int DataPin = 2;
const int IRQpin =  3;

PS2Keyboard keyboard;
Servo servo0;
Servo servo1;
Servo servo2;

void attachServos() {
  servo0.attach(9);
  servo1.attach(10);
  servo2.attach(11);
  delay(30);
  setServos(0, 0, 0);
  delay(50);
}

void setServos(int pos0, int pos1, int pos2) {
  if (pos0 == 0) {
    pos0 = 180;
  } else if (pos0 == 1) {
    pos0 = 120;    
  } else if (pos0 == 2) {
    pos0 = 60;   
  } else {
    pos0 = 0;    
  }

  if (pos1 == 0) {
    pos1 = 180;
  } else if (pos1 == 1) {
    pos1 = 120;    
  } else if (pos1 == 2) {
    pos1 = 60;   
  } else {
    pos1 = 0;    
  }

  if (pos2 == 0) {
    pos2 = 180;
  } else if (pos2 == 1) {
    pos2 = 120;    
  } else if (pos2 == 2) {
    pos2 = 60;   
  } else {
    pos2 = 0;    
  }
  
  servo0.write(pos0);
  servo1.write(pos1);
  servo2.write(pos2);
}

void setup() {
  keyboard.begin(DataPin, IRQpin);

  attachServos();
  
//  Serial.begin(9600);
//  Serial.println("Keyboard Test:");

  delay(500);
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();

    setServos(0, 0, 0);
    delay(wachttijd_tussen_letters);
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      //Serial.println();
    } else if (c == PS2_TAB) {
      //Serial.print("[Tab]");
      setServos(0, 0, 0);
    } else if (c == PS2_ESC) {
      //Serial.print("[ESC]");
      setServos(0, 0, 0);
    } else if (c == PS2_PAGEDOWN) {
      //Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      //Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      //Serial.print("[Left]");
      setServos(0, 0, 0);
    } else if (c == PS2_RIGHTARROW) {
      //Serial.print("[Right]");
      setServos(0, 0, 0);
    } else if (c == PS2_UPARROW) {
      //Serial.print("[Up]");
      setServos(0, 0, 0);
    } else if (c == PS2_DOWNARROW) {
      //Serial.print("[Down]");
      setServos(0, 0, 0);
    } else if (c == PS2_DELETE) {
      //Serial.print("[Del]");
      setServos(2, 3, 1);
    } else {
      if (c == 'q') { // querty klavier!!! = a
        setServos(0, 0, 1);
      } else if (c == 'b') {
        setServos(0, 0, 2);
      } else if (c == 'c') {
        setServos(0, 0, 3);
      } else if (c == 'd') {
        setServos(0, 1, 0);
      } else if (c == 'e') {
        setServos(0, 1, 1);
      } else if (c == 'f') {
        setServos(0, 1, 2);
      } else if (c == 'g') {
        setServos(0, 1, 3);
      } else if (c == 'h') {
        setServos(0, 2, 0);
      } else if (c == 'i') {
        setServos(0, 2, 1);
      } else if (c == 'j') {
        setServos(0, 2, 2);
      } else if (c == 'k') {
        setServos(0, 2, 3);
      } else if (c == 'l') {
        setServos(0, 3, 0);
      } else if (c == ';') { // querty = m
        setServos(0, 3, 1);
      } else if (c == 'n') {
        setServos(0, 3, 2);
      } else if (c == 'o') {
        setServos(0, 3, 3);
      } else if (c == 'p') {
        setServos(1, 0, 0);
      } else if (c == 'a') { // querty = q
        setServos(1, 0, 1);
      } else if (c == 'r') {
        setServos(1, 0, 2);
      } else if (c == 's') {
        setServos(1, 0, 3);
      } else if (c == 't') {
        setServos(1, 1, 0);
      } else if (c == 'u') {
        setServos(1, 1, 1);
      } else if (c == 'v') {
        setServos(1, 1, 2);
      } else if (c == 'z') { // querty = w
        setServos(1, 1, 3);
      } else if (c == 'x') {
        setServos(1, 2, 0);
      } else if (c == 'y') {
        setServos(1, 2, 1);
      } else if (c == 'w') { // query = z
        setServos(1, 2, 2);
      } else if (c == ' ') {
        setServos(2, 3, 0);
      } else if (c == '1') {
        setServos(1, 3, 0);
      } else if (c == '2') {
        setServos(1, 3, 1);
      } else if (c == '3') {
        setServos(1, 3, 2);
      } else if (c == '4') {
        setServos(1, 3, 3);
      } else if (c == '5') {
        setServos(2, 0, 0);
      } else if (c == '6') {
        setServos(2, 0, 1);
      } else if (c == '7') {
        setServos(2, 0, 2);
      } else if (c == '8') {
        setServos(2, 0, 3);
      } else if (c == '9') {
        setServos(2, 1, 0);
      } else if (c == 'm') { // querty  = ,
        setServos(2, 2, 2);
      } else if (c == '8') { // querty = !
        setServos(2, 2, 1);
      } else if (c == 'M') { // querty = ?
        setServos(2, 2, 0);
      } else if (c == '<') { // querty = .
        setServos(1, 2, 3);
      } else if (c == '.') { // querty = :
        setServos(2, 2, 3);
      }
      
      // otherwise, just print all normal characters
      //Serial.print(c);      
    }
  }
}
