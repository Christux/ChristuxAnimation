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

#include "TemporizedAnimation.h"

namespace ChristuxAnimation
{

  TemporizedAnimation::TemporizedAnimation(uint8_t nLeds, LedStrip* ledstrip, unsigned int delay, unsigned int numStep) :
    GenericAnimation(nLeds, ledstrip),
    _delay(delay),
    _nextFlicker(0),
    _step(0),
    _numStep(numStep)
  {}

  void TemporizedAnimation::reset()
  {
    _step = 0;
    _ledstrip->SetAllPixels(RgbColor::blank);
  }

  void TemporizedAnimation::handle() {
    unsigned long currTime = millis();
    if (currTime >= _nextFlicker) {
      run();
      _step = _step < _numStep - 1 ? _step + 1 : 0;
      _nextFlicker = currTime + _delay;
    }
  }
}
