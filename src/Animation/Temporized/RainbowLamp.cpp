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

#include "RainbowLamp.h"

namespace ChristuxAnimation
{

  RainbowLamp::RainbowLamp(uint8_t nLeds, LedStrip* ledstrip) :
    TemporizedAnimation(nLeds, ledstrip, 50, 360)
    {};

  void RainbowLamp::run()
  {
    int i = _step;
    RgbColor color = applyBrightness(RainbowTable::getRainbowColor(i));

    for(int k=0; k<_pixels; k++)
    {
      _ledstrip->setPixelColor(k, color);
    }

    _ledstrip->show();
  }
}
