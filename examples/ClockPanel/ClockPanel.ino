/*
 * Copyright (c) 2020 Christophe Rubeck.
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

int PixelPin = 8;
int PixelCount = 50;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(PixelCount, PixelPin);

ClockPanel clockPanel(
	[&]() {
		neoPixelBus.Begin();
	},
	[&]() {
		neoPixelBus.Show();
	},
	[&](int i, ChristuxAnimation::RgbColor color) {
		neoPixelBus.SetPixelColor(i, ::RgbColor(color.R, color.G, color.B));
	},
	(int[]){
		 7,8,
		5,6,9,
		 4,10,
		2,3,11,
		 1,0
	},
	(int[]){
		19,20,
	  17,18,21,
	  	16,22,
	  12,15,23,
	  	13,14
	},
	(int[]){
		25,
		24
	},
	(int[]){
		28,29,
	  26,27,30,
	  	32,31,
	  33,36,37,
	  	34,35
	},
	(int[]){
		48,49,
	  47,46,45,
	  	44,43,
	  38,41,42,
		39,40
	}
);

ClockPanelDisplay clockPanelDisplay(&clockPanel);

int i = 0;

void setup()
{
	clockPanel.Begin();

	clockPanelDisplay.reset();
	clockPanelDisplay.setColor(ChristuxAnimation::RgbColor(64,0,0));
}

void loop()
{
	clockPanelDisplay.handle();

	clockPanelDisplay.setTime(i/100, (i%100), 0);

	i++;
	delay(500);
}
