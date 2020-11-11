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

const int pixelPin = 8;
const int pixelCount = 50;

const int kCePin   = 10;  // Chip Enable
const int kIoPin   = 11;  // Input/Output
const int kSclkPin = 12;  // Serial Clock

ThreeWire myWire(kIoPin, kSclkPin, kCePin); // IO, SCLK, CE
RtcDS1302<ThreeWire> rtc(myWire);

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> neoPixelBus(pixelCount, pixelPin);

// Clock panel settings, ledstrip methods and leds mapping
ClockPanel clockPanel(
	[]() {
		neoPixelBus.Begin();
	},
	[]() {
		neoPixelBus.Show();
	},
	[](int i, Color color) {
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

// Clock panel animator
// Manages animations and apply masks of digits
ClockPanelAnimator clockPanelAnimator(
	&clockPanel, 
	[](){
		// If you don't have a rtc, uncomment the following line and comment the next one.
		//return ClockTime(22, 55);
		return ClockTime(hour(), minute());
	});

// Digit animations
UniColor unicolor(pixelCount, &clockPanel);
RainbowLamp rainbowAll(pixelCount, &clockPanel);
Fire fire(pixelCount, &clockPanel);
Glitter glitter(pixelCount, &clockPanel);
RainbowClockPanel rainbow(&clockPanel);

// Separator animations
UniColor unicolorS(2, clockPanel.getSeparator());
Blink blinkS(2, clockPanel.getSeparator(), 1000);
Bounce bounceS(2, clockPanel.getSeparator(), 200);
Breathing breathS(2, clockPanel.getSeparator());
KnightRider knightRiderS(2, clockPanel.getSeparator(), 200);

// For animation demo
unsigned long nextFlicker;
unsigned long temp[] = {6000, 6000, 12000, 12000, 6000}; // Animation duration
int step = 0;
int numStep;

void setup()
{
	// Start of rtc
	rtc.Begin();

	// Setup of timelib time provider
	setSyncProvider([&](){
		// Returns number of seconds since 1 janv 1970
		return rtc.GetDateTime().TotalSeconds() + SECS_YR_2000;
	});

	// Start of ledstrip
	clockPanel.begin();

	// Setup of main animations
	clockPanelAnimator.add(&unicolor);
	clockPanelAnimator.add(&fire);
	clockPanelAnimator.add(&rainbowAll);
	clockPanelAnimator.add(&rainbow);
	clockPanelAnimator.add(&glitter);

	// Setup of animations of separator
	clockPanelAnimator.addSeparator(&blinkS);
	clockPanelAnimator.addSeparator(&unicolorS);
	clockPanelAnimator.addSeparator(&breathS);
	clockPanelAnimator.addSeparator(&knightRiderS);
	clockPanelAnimator.addSeparator(&bounceS);

	// Settings
	clockPanelAnimator.setColor(Color::purple.changeBrightness(64));
	clockPanelAnimator.setAnimation(0);
	clockPanelAnimator.setSeparatorAnimation(0);

	// Demo
	numStep = clockPanelAnimator.animCount();
	nextFlicker = millis() + temp[0];
}

// Infinite loop
void loop()
{
	unsigned long currTime = millis();
	
	if (currTime >= nextFlicker) {
		step = step < numStep - 1 ? step + 1 : 0;
		clockPanelAnimator.setAnimation(step);
		clockPanelAnimator.setSeparatorAnimation(step);
		nextFlicker = currTime + temp[step];
	}
  
	clockPanelAnimator.handle();
}
