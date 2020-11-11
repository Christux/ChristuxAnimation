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

#include "UniversalLedStripAdapter.h"

namespace ChristuxAnimation
{
    UniversalLedStripAdapter::UniversalLedStripAdapter(int pixelCount, TBegin begin, TShow show, TSetPixelColor setPixelColor) :
        _pixelCount(pixelCount),
        _begin(begin),
        _show(show),
        _setPixelColor(setPixelColor)
    {}

    void UniversalLedStripAdapter::begin()
    {
        _begin();
    }

    void UniversalLedStripAdapter::show()
    {
        _show();
    }

    void UniversalLedStripAdapter::setAllPixels(RgbColor color)
    {
        for(int i = 0; i < _pixelCount; i++)
        {
            _setPixelColor(i, color);
        }
    }

    void UniversalLedStripAdapter::setPixelColor(int i, RgbColor color)
    {
        _setPixelColor(i, color);
    }
}
