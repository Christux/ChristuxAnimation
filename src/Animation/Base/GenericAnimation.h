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

#ifndef ChristuxAnimation_genericanimation_h
#define ChristuxAnimation_genericanimation_h

#include "Animation.h"
#include "../../LedStrip/LedStrip.h"
#include "../../Color/Color.h"

namespace ChristuxAnimation
{
  class GenericAnimation : public Animation
  {
    protected:
      const uint8_t _pixels;
      LedStrip* _ledstrip;
      RgbColor _color;
      RgbColor _background;
      uint8_t _brightness;
      bool _areChanges;
      RgbColor applyBrightness(RgbColor);
      RgbColor applyBrightness(RgbColor color, uint8_t bright);

    public:
      GenericAnimation(uint8_t nLeds, LedStrip* ledstrip);
      ~GenericAnimation() {};
      virtual void reset() = 0;
      virtual void handle() = 0;
      void setColor(RgbColor);
      void setBackgroundColor(RgbColor);
  };
}
#endif
