#include "Mouse.h"
#include <Arduino.h>


const int mouseButtonLeft = 3;
const int mouseButtonRight = 4;

const int xAxis = A0;
const int yAxis = A1;

int range = 12;
int responseDelay = 5;
int threshold = range / 6;
int center = range / 2;


int readAxis(int thisAxis) {
  int reading = analogRead(thisAxis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }
  return distance;
}

void setup() {
  Mouse.begin();
}

void loop() {
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);

  Mouse.move(xReading, yReading, 0);

  if (digitalRead(mouseButtonLeft) == HIGH) {

    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  } else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  // if (digitalRead(mouseButtonRight) == HIGH) {

  //   if (!Mouse.isPressed(MOUSE_RIGHT)) {
  //     Mouse.press(MOUSE_RIGHT);
  //   }
  // } else {
  //   if (Mouse.isPressed(MOUSE_RIGHT)) {
  //     Mouse.release(MOUSE_RIGHT);
  //   }
  // }

  delay(responseDelay);
}
