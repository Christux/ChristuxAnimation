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

#ifndef neopixeladapter_h
#define neopixeladapter_h

#include <NeoPixelBus.h>
#include <ChristuxAnimation.h>

namespace ChristuxAnimation {

template <typename Feature,  typename Method>
class NeoPixelAdapter : public LedStrip
{
    protected:
      NeoPixelBus<Feature, Method> _strip;

    public:
      NeoPixelAdapter(int pixelCount, int pixelPin);
      NeoPixelAdapter(int pixelCount, int ClockPin, int DataPin);
      NeoPixelAdapter(int pixelCount);
      ~NeoPixelAdapter() {};
      void begin();
      void setPixelColor(int i, RgbColor color);
      void setAllPixels(RgbColor color);
      void show();
  };

  /*
  * Implementation in same file because the templating (link edition does not work otherwise)
  */

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int pixelCount, int pixelPin):
    _strip(NeoPixelBus<Feature, Method>(pixelCount, pixelPin))
  {};

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int pixelCount, int ClockPin, int DataPin):
    _strip(NeoPixelBus<Feature, Method>(pixelCount, ClockPin, DataPin))
  {};

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int pixelCount):
    _strip(NeoPixelBus<Feature, Method>(pixelCount))
  {};

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::begin() {
    _strip.Begin();
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::setPixelColor(int i, RgbColor color) {
    _strip.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::setAllPixels(RgbColor color) {
    for(int i=0, N=_strip.PixelCount(); i<N; i++) {
      _strip.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
    }
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::show() {
    _strip.Show();
  }
}
#endif
