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

#include "KnightRider.h"

namespace ChristuxAnimation
{

  KnightRider::KnightRider(uint8_t nLeds, LedStrip* ledstrip):
    TemporizedAnimation(nLeds, ledstrip, 25, 4 * nLeds)
    {};

  KnightRider::KnightRider(uint8_t nLeds, LedStrip* ledstrip, unsigned int timestep):
    TemporizedAnimation(nLeds, ledstrip, timestep, 4 * nLeds)
    {};

  void KnightRider::run()
  {
    if (_step < _pixels) {
      int i = _step;
      for(int j=0; j<=i; j++)
        _ledstrip->SetPixelColor(j, _color);
      _ledstrip->Show();
    }

    if (_step >= _pixels && _step < 2 * _pixels) {
      int i = _step - _pixels;
      for(int j=0; j<=i; j++)
        _ledstrip->SetPixelColor(j, RgbColor::blank);
      _ledstrip->Show();
    }

    if (_step >= 2 * _pixels && _step < 3 * _pixels) {
      int i = _step - 2 * _pixels;
      for(int j=0; j<=i; j++)
        _ledstrip->SetPixelColor(_pixels - j - 1, _color);
      _ledstrip->Show();
    }

    if (_step >= 3 * _pixels && _step < 4 * _pixels) {
      int i = _step - 3 * _pixels;
      for(int j=0; j<=i; j++)
        _ledstrip->SetPixelColor(_pixels - j - 1, RgbColor::blank);
      _ledstrip->Show();
    }
  }
}
