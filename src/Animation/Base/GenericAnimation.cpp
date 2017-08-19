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

#include "GenericAnimation.h"

GenericAnimation::GenericAnimation(uint8_t nLeds, LedStrip* ledstrip):
 _pixels(nLeds),
 _ledstrip(ledstrip),
 _color(Color::blank),
 _brightness(0),
 _areChanges(true)
 {}

RgbColor GenericAnimation::applyBrightness(RgbColor color, uint8_t bright) {

 uint8_t newR = int( (float)color.R * ((float)bright / 255.0) );
 uint8_t newG = int( (float)color.G * ((float)bright / 255.0) );
 uint8_t newB = int( (float)color.B * ((float)bright / 255.0) );

 return RgbColor(newR, newG, newB);
}

RgbColor GenericAnimation::applyBrightness(RgbColor color) {
  return applyBrightness(color, _brightness);
}

void GenericAnimation::setColor(RgbColor color)
{
  _color = color;
  _brightness = color.CalculateBrightness();
  _areChanges = true;
}
