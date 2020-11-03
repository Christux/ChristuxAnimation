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

#include "SubLedStrip.h"

namespace ChristuxAnimation
{
	SubLedStrip::SubLedStrip(int pixels, const int* indexes, LedStrip* ledstrip):
	_pixels(pixels),
	_indexes(indexes),
	_ledstrip(ledstrip)
	{}

	void SubLedStrip::SetPixelColor(int i, RgbColor color)
	{
		_ledstrip->SetPixelColor(_indexes[i], color);
	}

	void SubLedStrip::SetAllPixels(RgbColor color)
	{
		for(int i = 0; i < _pixels; i++)
		{
			_ledstrip->SetPixelColor(_indexes[i], color);
		}
	}

	void SubLedStrip::SetPattern(const bool pattern[], RgbColor color)
	{
		SetPattern(pattern, color, true);
	}

	void SubLedStrip::SetPattern(const bool pattern[], RgbColor color, bool erasePixel)
	{
		for(int i = 0; i < _pixels; i++)
		{
			if(pattern[i])
			{
				_ledstrip->SetPixelColor(_indexes[i], color);
			}
			else
			{
				if(erasePixel)
				{
					_ledstrip->SetPixelColor(_indexes[i], RgbColor::blank);
				}
			}			
		}
	}
}