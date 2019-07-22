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

#include "StaticAnimation.h"

namespace ChristuxAnimation
{

  StaticAnimation::StaticAnimation(uint8_t nLeds, LedStrip* ledstrip) :
    GenericAnimation(nLeds, ledstrip)
  {}

  void StaticAnimation::reset()
  {
    _ledstrip->SetAllPixels(Color::blank);
  }

  void StaticAnimation::handle() {
    if(_areChanges)
    {
      run();
      _areChanges = false;
    }
  }
}
