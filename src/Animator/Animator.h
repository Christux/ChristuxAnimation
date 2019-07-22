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

#ifndef Animator_hpp
#define Animator_hpp

#include <NeoPixelBus.h>
#include "../Animation/Base/Animation.h"
#include "../Color/Color.h"

namespace ChristuxAnimation
{

  /*
  * Interface for animation classes
  */
  class Animator
  {
    protected:
      uint8_t _nAnim;
      uint8_t _currentAnim;
      Animation * _animations[20];
      RgbColor _currentColor;
      uint8_t brightness;

    public:
      Animator();
      void add(Animation*);
      uint8_t animCount() const;
      void handle() const;
      void nextAnimation();
      void setAnimation(uint8_t);
      uint8_t getAnimation();
      void setColor(RgbColor);
      RgbColor getColor();
  };
}
#endif
