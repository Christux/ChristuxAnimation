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

#include "Flag.h"

namespace ChristuxAnimation
{

  Flag::Flag(uint8_t nLeds, LedStrip* ledstrip):
  StaticAnimation(nLeds, ledstrip)
  {};

  void Flag::run()
  {
    RgbColor col[3];
    const int L = _pixels / 3;
    const int r = _pixels % 3;

    int N[4];
    N[0] = 0;
    N[1] = (r > 0) ? L + 1 : L;
    N[2] = N[1] + L;
    N[3] = N[2] + ( (r > 1) ? L + 1 : L );

    col[0] = applyBrightness(RgbColor::blue);
    col[1] = applyBrightness(RgbColor::white);
    col[2] = applyBrightness(RgbColor::red);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < (N[i + 1] - N[i]); j++) {
        _ledstrip->setPixelColor( N[i] + j, col[i]);
      }
    }
    _ledstrip->show();
  }
}
