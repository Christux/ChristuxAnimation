/*
 * Copyright (c) 2012 Christophe Rubeck.
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

#include "RainbowClockPanel.h"

namespace ChristuxAnimation
{
	RainbowClockPanel::RainbowClockPanel(
		ClockPanel *clockPanel) : 
		TemporizedAnimation(50, clockPanel, 60, 72),
		_clockPanel(clockPanel){};

	const int RainbowClockPanel::_indexes[] = {
		1,3,
	   0,2,4,
	    1,3,
	   0,2,4,
	    1,3
	};

	void RainbowClockPanel::run()
	{
		int i = _step;
		unsigned int delta = 5;

		for(uint8_t j = 0; j < 4; j++)
		{
			uint8_t offset = j < 2 ? j * 5 : j * 5 + 1;

			for(uint8_t k = 0; k < 12; k++)
			{
				_clockPanel->getDigit(j)->setPixelColor(k, getRainbowColor(360 - delta * (offset + _indexes[k] - i)));
			}
		}

		_clockPanel->setSeparatorColor(getRainbowColor(360 - delta * (10 - i)));

		_ledstrip->show();
	}

	RgbColor RainbowClockPanel::getRainbowColor(int phase)
	{
		return applyBrightness(RainbowTable::getRainbowColor(phase));
	}

} // namespace ChristuxAnimation