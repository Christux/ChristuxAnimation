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

#ifndef ledstrip_h
#define ledstrip_h

#include <Arduino.h>
#include "../Color/Color.h"

namespace ChristuxAnimation
{

  class LedStrip
  {
    public:
      virtual ~LedStrip() {};
      virtual void Begin() = 0;
      virtual void SetPixelColor(int, RgbColor) = 0;
      virtual void SetAllPixels(RgbColor) = 0;
      virtual void Show() = 0;
  };
}
#endif
