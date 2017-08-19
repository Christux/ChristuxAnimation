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

#include "RainbowLampRandom.h"

RainbowLampRandom::RainbowLampRandom(uint8_t nLeds, LedStrip* ledstrip) :
  GenericAnimation(nLeds, ledstrip),
  _delay(0),
  _nextFlicker(0),
  _phase(0)
  {};

void RainbowLampRandom::reset()
{
  _ledstrip->SetAllPixels(Color::blank);
}

void RainbowLampRandom::handle()
{
  unsigned long currTime = millis();

  if (currTime >= _nextFlicker) {

    // New phase
    _phase = _phase + random(180);
    _phase = _phase < 360 ? _phase : _phase - 360;

    RgbColor color = applyBrightness(RainbowTable::getRainbowColor(_phase));

    // Set all leds
    _ledstrip->SetAllPixels(color);
    _ledstrip->Show();

    _delay = (20 + random(40)) * 100;
    _nextFlicker = currTime + _delay;
  }
}
