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

#ifndef ChristuxAnimation_flag_h
#define ChristuxAnimation_flag_h

#include "Base/StaticAnimation.h"
#include "../../Color/Color.h"

namespace ChristuxAnimation
{

  class Flag: public StaticAnimation
  {
  public:
    Flag(uint8_t nLeds, LedStrip* ledstrip);
    ~Flag() {};
  protected:
    void run();
  };
}

#endif
