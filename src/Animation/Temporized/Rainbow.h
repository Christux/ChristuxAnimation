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

#ifndef ChristuxAnimation_rainbow_h
#define ChristuxAnimation_rainbow_h

#include "Base/TemporizedAnimation.h"
#include "../../RainbowTable/RainbowTable.h"

namespace ChristuxAnimation
{

  class Rainbow : public TemporizedAnimation
  {
    public:
      Rainbow(uint8_t nLeds, LedStrip* ledstrip);
      ~Rainbow() {};
    protected:
      void run();
  };
}
#endif
