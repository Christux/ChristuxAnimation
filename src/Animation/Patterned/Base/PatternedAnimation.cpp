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

#include "PatternedAnimation.h"

PatternedAnimation::PatternedAnimation(uint8_t nLeds, LedStrip* ledstrip, unsigned int delay, const uint8_t pattern[], const int patternSize) :
  TemporizedAnimation(nLeds, ledstrip, delay, patternSize),
  _pattern(pattern),
  _patternSize(patternSize)
   {};

void PatternedAnimation::run()
{
  RgbColor col[2 * _patternSize];
  int j = _step;

  for (int n = 0; n < _patternSize; n++) {
    col[n] = applyBrightness(_color, _pattern[n]);
    col[n + _patternSize] = col[n];
  }

  for (int k = 0, l=_pixels / _patternSize; k < l; k++) {
      for (int i = 0; i < _patternSize; i++) {
        _ledstrip->SetPixelColor(k * _patternSize + i, col[i + j]);
      }
  }

  _ledstrip->Show();
}
