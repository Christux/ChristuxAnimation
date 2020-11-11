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

#ifndef ChristuxAnimation_iclockpanel_h
#define ChristuxAnimation_iclockpanel_h

#include <Arduino.h>
#include "../../LedStrip/LedStrip.h"
#include "../../Color/Color.h"

namespace ChristuxAnimation
{
	class IClockPanel : public LedStrip
	{
		public:
			virtual ~IClockPanel() {};
			virtual void setSeparatorPixelColor(int i, RgbColor color) = 0;
			virtual void showWithMask() = 0;
			virtual void showWithoutMask() = 0;
	};
}
#endif
