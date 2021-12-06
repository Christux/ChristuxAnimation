/*
 * Copyright (c) 2021 Christophe Rubeck.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <NeoPixelBus.h>
#include <ChristuxAnimation.h>

using namespace ChristuxAnimation;

int pixelCount=24;
int pixelPin=8;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(pixelCount, pixelPin);

UniversalLedStripAdapter strip(
  pixelCount,
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



void setup() {

	strip.begin();
	
}

void loop() {

}