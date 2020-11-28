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

#include "ClockDigit.h"

namespace ChristuxAnimation
{
	ClockDigit::ClockDigit(const int indexes[12], LedStrip* ledstrip):
	SubLedStrip(12, indexes, ledstrip),
	_mirror(false)
	{}

	void ClockDigit::setMirror(bool mirror)
	{
		_mirror = mirror;
	}

	void ClockDigit::setPixelColor(int i, RgbColor color)
	{
		if(_mirror) 
		{
			_ledstrip->setPixelColor(_indexes[mirrorPattern[i]], color);
		}
		else
		{
			_ledstrip->setPixelColor(_indexes[i], color);
		}
	}

	const uint8_t ClockDigit::mirrorPattern[] = {
				1, 0,
			   4, 3, 2,
				6, 5,
			   9, 8, 7,
				11, 10
	};
}