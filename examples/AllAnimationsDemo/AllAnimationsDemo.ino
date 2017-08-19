/*
   Copyright (c) 2017 Christophe Rubeck.

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
#include <NeoPixelBus.h>
#include <ChristuxAnimation.h>

int PixelCount = 5;
int PixelPin = 8;

NeoPixelAdapter<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

Animator animator;

Rainbow rainbow(PixelCount, &strip);
Sunrise sunrise(PixelCount, &strip, 5);
UniColor unicolor(PixelCount, &strip);
Off off(PixelCount, &strip);
Flag flag(PixelCount, &strip);
Comet comet(PixelCount, &strip);
Theater theater(PixelCount, &strip);
KnightRider rider(PixelCount, &strip);
RainbowLamp lamp(PixelCount, &strip);
RainbowLampRandom randlamp(PixelCount, &strip);
Fire fire(PixelCount, &strip);
Breathing breath(PixelCount, &strip);

// For animation loop
const char * labels[] = {"Rainbow","Sunrise","Unicolor","Flag","Comet","Theater","Knight Rider","Rainbow lamp","Random rainbow lamp","Fire","Breathing"};
unsigned long nextFlicker = 0;
unsigned long temp = 6000; // Animation duration
int step = 0;
int numStep;

void setup() {

  Serial.begin(9600);

  strip.Begin();

  animator.add(&rainbow);
  animator.add(&sunrise);
  animator.add(&unicolor);
  animator.add(&flag);
  animator.add(&comet);
  animator.add(&theater);
  animator.add(&rider);
  animator.add(&lamp);
  animator.add(&randlamp);
  animator.add(&fire);
  animator.add(&breath);

  // Do not forget to set a color !
  animator.setColor(Color::red);

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