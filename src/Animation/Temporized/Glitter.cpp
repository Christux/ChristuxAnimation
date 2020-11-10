/*
 * Copyright (c) 2019 Christophe Rubeck.
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

#include "Glitter.h"

namespace ChristuxAnimation
{
	Glitter::Glitter(uint8_t nLeds, LedStrip *ledstrip) : TemporizedAnimation(nLeds, ledstrip, 100, 1){};

	RgbColor Glitter::update(float delta)
	{
		return _color.ChangeRelativeBrightness(delta);
	}

	void Glitter::run()
	{
		for (int i = 0; i < _pixels; i++)
		{
			float delta = random(40, 100) / 100.0;
			_ledstrip->SetPixelColor(i, update(delta));
		}

		_ledstrip->Show();
		_delay = random(50, 150);
	}
} // namespace ChristuxAnimation
