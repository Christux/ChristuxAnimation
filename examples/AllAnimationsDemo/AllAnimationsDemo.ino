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
#include <ChristuxAnimation.h>
#include <NeoPixelBus.h>


using namespace ChristuxAnimation;

int PixelCount = 5;
int PixelPin = 8;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(PixelCount, PixelPin);
//NeoPixelAdapter<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

// void begin()
// {
//   neoPixelBus.Begin();
// }

// void show()
// {
//   neoPixelBus.Show();
// }

// void setPixelColor(int i, ChristuxAnimation::RgbColor color)
// {
//   neoPixelBus.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
// }

UniversalLedStripAdapter strip(
  PixelCount,
  []() {
    neoPixelBus.Begin();
  },
  [](){
    neoPixelBus.Show();
  },
  [](int i, ChristuxAnimation::RgbColor color) {
    neoPixelBus.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
  }
);

Animator animator;

Rainbow rainbow(PixelCount, &strip);
Sunrise sunrise(PixelCount, &strip, 5);
UniColor unicolor(PixelCount, &strip);
Off off(PixelCount, &strip);
Flag flag(PixelCount, &strip);
Comet comet(PixelCount, &strip);
Theater theater(PixelCount, &strip);
KnightRider rider(PixelCount, &strip, 100);
RainbowLamp lamp(PixelCount, &strip);
RainbowLampRandom randlamp(PixelCount, &strip);
Fire fire(PixelCount, &strip);
Breathing breath(PixelCount, &strip);
Blink blink(PixelCount, &strip, 1000);

// For animation loop
const char * labels[] = {"Rainbow","Sunrise","Unicolor","Flag","Comet","Theater","Knight Rider","Rainbow lamp","Random rainbow lamp","Fire","Breathing","Blink"};
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
