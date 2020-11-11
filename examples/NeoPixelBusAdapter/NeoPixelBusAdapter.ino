/*
 * Copyright (c) 2019 Christophe Rubeck.
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

#include <ChristuxAnimation.h>
#include "NeoPixelAdapter.h"

using namespace ChristuxAnimation;

int pixelCount=5;
int pixelPin=8;

NeoPixelAdapter<NeoGrbFeature, Neo800KbpsMethod> strip(pixelCount, pixelPin);

Rainbow rainbow(pixelCount, &strip);

void setup() {

	strip.begin();
	rainbow.reset();
	rainbow.setColor(ChristuxAnimation::RgbColor(16,0,0));
}

void loop() {
	rainbow.handle();
}
