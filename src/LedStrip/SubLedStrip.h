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

#ifndef ChristuxAnimation_subledstrip_h
#define ChristuxAnimation_subledstrip_h

#include <Arduino.h>
#include "LedStrip.h"

namespace ChristuxAnimation
{
	class SubLedStrip
	{
		protected:
			const uint8_t _pixels;
			const int* _indexes;
			LedStrip* _ledstrip;

		public:
			SubLedStrip(int, const int*, LedStrip*);
			~SubLedStrip() {};
			void SetPixelColor(int, RgbColor);
			void SetAllPixels(RgbColor);
			void SetPattern(const bool[], RgbColor);
			void SetPattern(const bool[], RgbColor, bool);
	};
}
#endif