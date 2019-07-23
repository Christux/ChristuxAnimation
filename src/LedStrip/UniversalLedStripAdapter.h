
#include <Arduino.h>
#include "Base/LedStrip.h"

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
        UniversalLedStripAdapter(int PixelCount, TBegin Begin, TShow Show, TSetPixelColor SetPixelColor);
        ~UniversalLedStripAdapter() {};
        void Begin();
        void SetPixelColor(int i, RgbColor color);
        void SetAllPixels(RgbColor color);
        void Show();
    };
}
