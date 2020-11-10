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

#ifndef ChristuxAnimation_color_h
#define ChristuxAnimation_color_h

#include <Arduino.h>

namespace ChristuxAnimation
{

  struct RgbColor
  {
  public:
    uint8_t R;
    uint8_t G;
    uint8_t B;
    RgbColor(uint8_t, uint8_t, uint8_t);
    RgbColor();
    ~RgbColor(){};
    uint8_t CalculateBrightness() const;// Get
    RgbColor ChangeBrightness(uint8_t) const; // Set
    RgbColor ChangeRelativeBrightness(float) const; // Set

    bool operator==(const RgbColor& other) const
    {
        return (R == other.R && G == other.G && B == other.B);
    }

    bool operator!=(const RgbColor& other) const
    {
        return !(*this == other);
    }

    /*
    * Define colors
    */
    static const RgbColor red;
    static const RgbColor green;
    static const RgbColor blue;
    static const RgbColor purple;
    static const RgbColor orange;
    static const RgbColor yellow;
    static const RgbColor blank;
    static const RgbColor white;
  };
}

#endif
