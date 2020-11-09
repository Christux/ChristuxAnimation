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

#include <TimeLib.h>
#include <NeoPixelBus.h>
#include <ChristuxAnimation.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

using namespace ChristuxAnimation;
using Color = ChristuxAnimation::RgbColor;

const int PixelPin = 8;
const int PixelCount = 50;

const int kCePin   = 10;  // Chip Enable
const int kIoPin   = 11;  // Input/Output
const int kSclkPin = 12;  // Serial Clock

ThreeWire myWire(kIoPin, kSclkPin, kCePin); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(PixelCount, PixelPin);

ClockPanel clockPanel(
	[&]() {
		neoPixelBus.Begin();
	},
	[&]() {
		neoPixelBus.Show();
	},
	[&](int i, Color color) {
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

ClockPanelAnimator clockPanelAnimator(
	&clockPanel, 
	[&](){
		return ClockTime(hour(), minute());
	});

// Digit animations
UniColor unicolor(PixelCount, &clockPanel);
RainbowLamp rainbowAll(PixelCount, &clockPanel);
Rainbow rainbow(PixelCount, &clockPanel);
Fire fire(PixelCount, &clockPanel);

// Separator animations
UniColor unicolorS(2, clockPanel.GetSeparator());
Blink blinkS(2, clockPanel.GetSeparator(), 1000);
Breathing breathS(2, clockPanel.GetSeparator());
KnightRider knightRiderS(2, clockPanel.GetSeparator(), 200);

void setup()
{
	// Start of rtc
	Rtc.Begin();

	// Setup of timelib time provider
	setSyncProvider([&](){
		return Rtc.GetDateTime().TotalSeconds() + SECS_YR_2000;
	});

	// Start of ledstrip
	clockPanel.Begin();

	// Setup of main animations
	clockPanelAnimator.add(&unicolor);
	clockPanelAnimator.add(&rainbowAll);
	clockPanelAnimator.add(&rainbow);
	clockPanelAnimator.add(&fire);

	// Setup of animations of separator
	clockPanelAnimator.addSeparator(&unicolorS);
	clockPanelAnimator.addSeparator(&blinkS);
	clockPanelAnimator.addSeparator(&breathS);
	clockPanelAnimator.addSeparator(&knightRiderS);

	// Settings
	clockPanelAnimator.setColor(Color::purple.ChangeBrightness(64));
	clockPanelAnimator.setAnimation(3);
	clockPanelAnimator.setSeparatorAnimation(0);
}

void loop()
{
	clockPanelAnimator.handle();
}
