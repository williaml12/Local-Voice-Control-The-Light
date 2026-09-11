// SPDX-FileCopyrightText: Copyright (C) Arduino s.r.l. and/or its affiliated companies
//
// SPDX-License-Identifier: MPL-2.0
#include <Arduino_LED_Matrix.h>
#include <Arduino_RouterBridge.h>
#include "heart_frames.h"

const int LIGHT_RELAY_PIN = 7;  // wired to relay module's IN/signal pin

Arduino_LED_Matrix matrix;

void setup() {
  matrix.begin();
  matrix.clear();
  matrix.loadFrame(HeartStatic);

  pinMode(LIGHT_RELAY_PIN, OUTPUT);
  digitalWrite(LIGHT_RELAY_PIN, HIGH);  // HIGH = relay off (active-LOW module)

  Bridge.begin();
  Bridge.provide("light_on", light_on);
  Bridge.provide("light_off", light_off);
}

void loop() {}

void light_on() {
  digitalWrite(LIGHT_RELAY_PIN, LOW);   // LOW = relay on (active-LOW module)
  matrix.loadSequence(HeartAnim);
  matrix.playSequence();
  delay(500);
  matrix.loadFrame(HeartStatic);        // solid heart = light is on
}

void light_off() {
  digitalWrite(LIGHT_RELAY_PIN, HIGH);  // HIGH = relay off (active-LOW module)
  matrix.loadSequence(HeartAnim);
  matrix.playSequence();
  delay(500);
  matrix.clear();                       // blank = light is off
}