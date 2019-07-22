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

#ifndef sunrise_h
#define sunrise_h

#include "../Base/GenericAnimation.h"

namespace ChristuxAnimation
{

  class Sunrise : public GenericAnimation
  {
    protected:
      unsigned long _delay = 40;
      unsigned long _nextFlicker = 0;

      const unsigned int _Imax;
      const unsigned long _sunrise_during; // in seconds
      unsigned long _timestart = 0;
      unsigned long _timestop = 0;

      void run();

    public:
      Sunrise(uint8_t nLeds, LedStrip* ledstrip, unsigned long duration, uint8_t Imax = 255);
      ~Sunrise() {};
      void reset();
      void handle();
  };
}
#endif
