/*
 * Copyright (c) 2017 Christophe Rubeck.
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

#include "Fire.h"

namespace ChristuxAnimation
{

  Fire::Fire(uint8_t nLeds, LedStrip* ledstrip):
    TemporizedAnimation(nLeds, ledstrip, 100, 1)
    {};

  void Fire::run()
  {
    uint8_t r = 255;
    uint8_t g = 100;
    uint8_t b = 0;

    for (int i = 0; i < _pixels; i++) {

        int delta = random(40, 100);
        RgbColor col = applyBrightness(RgbColor((r * delta) / 100, (g * delta) / 100, b));
        _ledstrip->SetPixelColor(i, col);
        //strip.SetPixelColor(i,RgbColor((r*delta)/100,(g*delta)/100,b));
      }
      _ledstrip->Show();

      _delay = random(50, 150);
  }
}
