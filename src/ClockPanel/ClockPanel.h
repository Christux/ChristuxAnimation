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

/**
 * Clock panel design :
 * 
 *           o o     o o         o o     o o
 *          o o o   o o o   o   o o o   o o o
 *           o o     o o         o o     o o
 *          o o o   o o o   o   o o o   o o o
 *           o o     o o         o o     o o
 *          \___/   \___/  \_/  \___/   \___/
 * Digit# :   1       2           3       4
 */

#ifndef ChristuxAnimation_clockpanel_h
#define ChristuxAnimation_clockpanel_h

#include <Arduino.h>
#include "../LedStrip/LedStrip.h"
#include "../Color/Color.h"
#include "ClockDigit/ClockDigit.h"
#include "ClockSeparator/ClockSeparator.h"

namespace ChristuxAnimation
{
	typedef void (*TBegin)(void);
	typedef void (*TShow)(void);
	typedef void (*TSetPixelColor)(int, RgbColor);

	class ClockPanel : public LedStrip
	{
		protected:
			TBegin _begin;
			TShow _show;
			TSetPixelColor _setPixelColor;
			ClockDigit _digits[4];
			ClockSeparator _separator;

		public:
			static const int pixelCount = 50;
			ClockPanel(
				TBegin,
				TShow,
				TSetPixelColor,
				const int[],
				const int[],
				const int[],
				const int[],
				const int[]);
			~ClockPanel() {};
			void Begin();
			void SetPixelColor(int i, RgbColor color);
			void SetAllPixels(RgbColor color);
			void Show();
			ClockDigit* GetDigit(int i);
			ClockSeparator* GetSeparator();
	};
}
#endif
