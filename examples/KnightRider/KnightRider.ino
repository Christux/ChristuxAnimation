/*
 * Copyright (c) 2017 Christophe Rubeck.
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

int PixelCount=5;
int PixelPin=8;

NeoPixelAdapter<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
KnightRider rider(PixelCount, &strip, 100); // Delay in _useconds (default is 25)

void setup() {

	strip.Begin();
	rider.reset();
	rider.setColor(ChristuxAnimation::RgbColor::red);
}

void loop() {
	rider.handle();
}