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
    UniversalLedStripAdapter::UniversalLedStripAdapter(int PixelCount, TBegin Begin, TShow Show, TSetPixelColor SetPixelColor) :
        _pixelCount(PixelCount),
        _begin(Begin),
        _show(Show),
        _setPixelColor(SetPixelColor)
    {}

    void UniversalLedStripAdapter::Begin()
    {
        _begin();
    }

    void UniversalLedStripAdapter::Show()
    {
        _show();
    }

    void UniversalLedStripAdapter::SetAllPixels(RgbColor color)
    {
        for(int i = 0; i < _pixelCount; i++)
        {
            _setPixelColor(i, color);
        }
    }

    void UniversalLedStripAdapter::SetPixelColor(int i, RgbColor color)
    {
        _setPixelColor(i, color);
    }
}
