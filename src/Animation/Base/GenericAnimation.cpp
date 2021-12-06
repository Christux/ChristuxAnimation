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

#include "GenericAnimation.h"

namespace ChristuxAnimation
{
  GenericAnimation::GenericAnimation(uint8_t nLeds, LedStrip *ledstrip) : _pixels(nLeds),
                                                                          _ledstrip(ledstrip),
                                                                          _color(RgbColor::blank),
                                                                          _background(RgbColor::blank),
                                                                          _brightness(0),
                                                                          _areChanges(true)
  {
  }

  RgbColor GenericAnimation::applyBrightness(RgbColor color, uint8_t bright)
  {
    return color.changeBrightness(bright);
  }

  RgbColor GenericAnimation::applyBrightness(RgbColor color)
  {
    return color.changeBrightness(_brightness);
  }

  void GenericAnimation::setColor(RgbColor color)
  {
    _color = color;
    _brightness = color.calculateBrightness();;
    _areChanges = true;
  }

  void GenericAnimation::setBackgroundColor(RgbColor color)
  {
    _background = color;
  }
} // namespace ChristuxAnimation
