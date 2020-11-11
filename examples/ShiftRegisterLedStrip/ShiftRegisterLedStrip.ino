/*
   Copyright (c) 2019 Christophe Rubeck.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, version 3.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Lesser Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#define animationDemo
#include <ChristuxAnimation.h>
#include "ShiftRegisterLedStrip.h"

#define LATCH_PIN 9
#define CLOCK_PIN 8
#define DATA_PIN 10

using namespace ChristuxAnimation;

uint8_t pixelCount = 8;

ShiftRegisterLedStrip strip = ShiftRegisterLedStrip(pixelCount, CLOCK_PIN, LATCH_PIN, DATA_PIN);

Animator animator;

Comet comet(pixelCount, &strip);
Theater theater(pixelCount, &strip);
KnightRider rider(pixelCount, &strip, 100);
Blink blink(pixelCount, &strip, 1000);

// For animation loop
const char * labels[] = {"Rainbow","Sunrise","Unicolor","Flag","Comet","Theater","Knight Rider","Rainbow lamp","Random rainbow lamp","Fire","Breathing","Blink"};
unsigned long nextFlicker = 0;
unsigned long temp = 6000; // Animation duration
int step = 0;
int numStep;

void setup() {

  Serial.begin(9600);

  strip.begin();

  animator.add(&comet);
  animator.add(&theater);
  animator.add(&rider);
  animator.add(&blink);

  // Do not forget to set a color !
  animator.setColor(ChristuxAnimation::RgbColor::red);

  numStep = animator.animCount();
}

void loop() {

  unsigned long currTime = millis();
  if (currTime >= nextFlicker) {
    step = step < numStep - 1 ? step + 1 : 0;
    animator.setAnimation(step);
    Serial.println(labels[step]);
    nextFlicker = currTime + temp;
  }

  animator.handle();
}
