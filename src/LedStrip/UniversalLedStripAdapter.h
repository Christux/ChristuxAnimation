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

#ifndef ChristuxAnimation_UnisersalLedStripAdapter_h
#define ChristuxAnimation_UnisersalLedStripAdapter_h

#include <Arduino.h>
#include "LedStrip.h"

namespace ChristuxAnimation
{
    typedef void (*TBegin)(void);
    typedef void (*TShow)(void);
    typedef void (*TSetPixelColor)(int, RgbColor);

    class UniversalLedStripAdapter : public LedStrip
    {
    protected:
        int _pixelCount;
        TBegin _begin;
        TShow _show;
        TSetPixelColor _setPixelColor;
        
    public:
        UniversalLedStripAdapter(int pixelCount, TBegin Begin, TShow Show, TSetPixelColor SetPixelColor);
        ~UniversalLedStripAdapter() {};
        void Begin();
        void SetPixelColor(int i, RgbColor color);
        void SetAllPixels(RgbColor color);
        void Show();
    };
}

#endif
