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
      NeoPixelAdapter(int PixelCount, int PixelPin);
      NeoPixelAdapter(int PixelCount, int ClockPin, int DataPin);
      NeoPixelAdapter(int PixelCount);
      ~NeoPixelAdapter() {};
      void Begin();
      void SetPixelColor(int i, RgbColor color);
      void SetAllPixels(RgbColor color);
      void Show();
  };

  /*
  * Implementation in same file because the templating (link edition does not work otherwise)
  */

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int PixelCount, int PixelPin):
    _strip(NeoPixelBus<Feature, Method>(PixelCount, PixelPin))
  {};

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int PixelCount, int ClockPin, int DataPin):
    _strip(NeoPixelBus<Feature, Method>(PixelCount, ClockPin, DataPin))
  {};

  template <typename Feature,  typename Method>
  NeoPixelAdapter<Feature, Method>::NeoPixelAdapter(int PixelCount):
    _strip(NeoPixelBus<Feature, Method>(PixelCount))
  {};

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::Begin() {
    _strip.Begin();
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::SetPixelColor(int i, RgbColor color) {
    _strip.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::SetAllPixels(RgbColor color) {
    for(int i=0, N=_strip.PixelCount(); i<N; i++) {
      _strip.SetPixelColor(i, ::RgbColor(color.R,color.G,color.B));
    }
  }

  template <typename Feature,  typename Method>
  void NeoPixelAdapter<Feature, Method>::Show() {
    _strip.Show();
  }
}
#endif
