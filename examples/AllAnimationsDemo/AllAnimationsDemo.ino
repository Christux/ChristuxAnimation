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
#include <NeoPixelBus.h>

using namespace ChristuxAnimation;

int pixelCount = 5;
int pixelPin = 8;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(pixelCount, pixelPin);

UniversalLedStripAdapter strip(
  // Set here the number of leds
  pixelCount,
  // Set here the setup function from the ledstrip driver
  [&]() {
    neoPixelBus.Begin();
  },
  // Set here the commit function from the ledstrip driver
  [&](){
    neoPixelBus.Show();
  },
  // Set here the led color setup function from the ledstrip driver
  [&](int i, ChristuxAnimation::RgbColor color) {
    neoPixelBus.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
  }
);

Animator animator;

Rainbow rainbow(pixelCount, &strip);
Sunrise sunrise(pixelCount, &strip, 5);
UniColor unicolor(pixelCount, &strip);
Off off(pixelCount, &strip);
Flag flag(pixelCount, &strip);
Comet comet(pixelCount, &strip);
Theater theater(pixelCount, &strip);
KnightRider rider(pixelCount, &strip, 100);
RainbowLamp lamp(pixelCount, &strip);
RainbowLampRandom randlamp(pixelCount, &strip);
Fire fire(pixelCount, &strip);
Breathing breath(pixelCount, &strip);
Blink blink(pixelCount, &strip, 1000);
Bounce bounce(pixelCount, &strip, 200);

// For animation loop
const char * labels[] = {"Rainbow","Sunrise","Unicolor","Flag","Comet","Theater","Knight Rider","Rainbow lamp","Random rainbow lamp","Fire","Breathing","Blink","Bounce"};
unsigned long nextFlicker;
unsigned long temp = 6000; // Animation duration
int step = 0;
int numStep;

void setup() {

  Serial.begin(9600);

  strip.begin();

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
  animator.add(&blink);
  animator.add(&bounce);

  // Do not forget to set a color !
  animator.setColor(ChristuxAnimation::RgbColor::red);

  numStep = animator.animCount();
  nextFlicker = millis() + temp;
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
