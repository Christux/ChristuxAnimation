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

#include "Breathing.h"

Breathing::Breathing(uint8_t nLeds, LedStrip* ledstrip):
  TemporizedAnimation(nLeds, ledstrip, 40, 1),
  _startTime(millis())
  {};

// Override method
void Breathing::reset()
{
  _startTime = millis();
  TemporizedAnimation::reset();
}

void Breathing::run()
{
  float val = (exp(sin((millis()-_startTime+3000.0) / 2000.0 * PI)) - 0.36787944) * 90 + 10;

  _ledstrip->SetAllPixels(applyBrightness(_color, (uint8_t)val));
  _ledstrip->Show();
}
