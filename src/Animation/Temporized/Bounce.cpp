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

#include "Bounce.h"

namespace ChristuxAnimation
{

	Bounce::Bounce(uint8_t nLeds, LedStrip *ledstrip) : TemporizedAnimation(nLeds, ledstrip, 25, 2 * nLeds){};
	Bounce::Bounce(uint8_t nLeds, LedStrip *ledstrip, unsigned int timestep) : TemporizedAnimation(nLeds, ledstrip, timestep, 2 * nLeds){};

	void Bounce::run()
	{
		if (_step < _pixels)
		{
			int i = _step;
			_ledstrip->SetPixelColor(i, _color);

			if(i > 0)
			{
				_ledstrip->SetPixelColor(i - 1, RgbColor::blank);
			}

			_ledstrip->Show();
		}

		if (_step >= _pixels)
		{
			int i = _step - _pixels;
			_ledstrip->SetPixelColor(_pixels - i - 1, _color);

			if(i > 0)
			{
				_ledstrip->SetPixelColor(_pixels - i, RgbColor::blank);
			}
				
			_ledstrip->Show();
		}
	}
} // namespace ChristuxAnimation
