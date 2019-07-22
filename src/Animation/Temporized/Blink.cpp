/*
 * Copyright (c) 2018 Christophe Rubeck.
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

#include "Blink.h"

namespace ChristuxAnimation
{

  Blink::Blink(uint8_t nLeds, LedStrip* ledstrip, unsigned int duration):
    TemporizedAnimation(nLeds, ledstrip, duration, 2)
    {};

  void Blink::run()
  {
    if (_step == 0)
    {
      for(int j=0; j<=_pixels; j++)
        _ledstrip->SetPixelColor(j, _color);
      _ledstrip->Show();
    }
    else
    {
      for(int j=0; j<=_pixels; j++)
        _ledstrip->SetPixelColor(j, Color::blank);
      _ledstrip->Show();
    }
  }
}
