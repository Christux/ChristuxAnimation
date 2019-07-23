
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
