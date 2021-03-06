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

#include "ClockSeparator.h"

namespace ChristuxAnimation
{
	ClockSeparator::ClockSeparator(const int indexes[2], IClockPanel* clockPanel):
	SubLedStrip(2, indexes, clockPanel),
	_clockPanel(clockPanel)
	{}

	void ClockSeparator::show()
	{
		_clockPanel->showWithoutMask();
	}

	void ClockSeparator::setPixelColor(int i, RgbColor color)
	{
		_clockPanel->setSeparatorPixelColor(_indexes[i], color);
	}
}