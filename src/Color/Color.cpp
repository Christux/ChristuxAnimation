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

#include "Color.h"

namespace ChristuxAnimation
{

    RgbColor::RgbColor() :
    R(0),G(0),B(0)
    {}

    RgbColor::RgbColor(uint8_t r, uint8_t g, uint8_t b) :
        R(r),G(g),B(b)
        {}

    uint8_t RgbColor::calculateBrightness() const
    {
        return R > G ? (R > B ? R : B) : (G > B ? G : B);
    }

    RgbColor RgbColor::changeBrightness(uint8_t bright) const 
    {
        float alpha = (float)bright / (float)calculateBrightness();

        return changeRelativeBrightness(alpha);
    }

    RgbColor RgbColor::changeRelativeBrightness(float alpha) const
    {
        uint8_t newR = int( (float)R * alpha );
        uint8_t newG = int( (float)G * alpha );
        uint8_t newB = int( (float)B * alpha );

        return RgbColor(newR, newG, newB);
    }

    const RgbColor RgbColor::red = RgbColor(255, 0, 0);
    const RgbColor RgbColor::green = RgbColor(0, 255, 0);
    const RgbColor RgbColor::blue = RgbColor(0, 0, 255);
    const RgbColor RgbColor::purple = RgbColor(146, 0, 255);
    const RgbColor RgbColor::orange = RgbColor(255, 128, 0);
    const RgbColor RgbColor::yellow = RgbColor(255, 255, 0);
    const RgbColor RgbColor::blank = RgbColor(0, 0, 0);
    const RgbColor RgbColor::white = RgbColor(255, 255, 255);
}
