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

#include "Sunrise.h"

namespace ChristuxAnimation
{

  Sunrise::Sunrise(uint8_t nLeds, LedStrip* ledstrip, unsigned long duration, uint8_t Imax) :
    GenericAnimation(nLeds, ledstrip),
    _sunrise_during(duration),
    _Imax(Imax)
  {};

  void Sunrise::reset()
  {
    // Init sunrise vars
    unsigned long current = millis();
    _timestart = current;
    _timestop = current + _sunrise_during * 1000;

    // Turn off leds
    for(int i=0; i< _pixels;i++) {
      _ledstrip->SetPixelColor(i, RgbColor::blank);
    }
  }

  void Sunrise::handle()
  {
    unsigned long current = millis();

    if(current >= _nextFlicker)
    {
      _nextFlicker = current + _delay;
      run();
    }
  }

  void Sunrise::run()
  {
    unsigned long current = millis();

    if (current < _timestop) {

      unsigned long t = (current - _timestart) / 1000; // seconds
      float R = _Imax  * _pixels * 1.0  / (1 + exp(-0.4 * 30 / _sunrise_during * (t - _sunrise_during * 0.67) ) );
      float G = _Imax  * _pixels * 0.7  / (1 + exp(-0.5 * 30 / _sunrise_during * (t - _sunrise_during * 0.7 ) ) );
      float B = _Imax  * _pixels * 0.1  / (1 + exp(-0.6 * 30 / _sunrise_during * (t - _sunrise_during * 0.8 ) ) );

      uint8_t Rmean = (unsigned int)R / _pixels;
      uint8_t Gmean = (unsigned int)G / _pixels;
      uint8_t Bmean = (unsigned int)B / _pixels;
      int Ridx = (unsigned int)R % _pixels;
      int Gidx = (unsigned int)G % _pixels;
      int Bidx = (unsigned int)B % _pixels;

      for (int i = 0; i < _pixels; i++) {
        uint8_t r = Rmean;
        uint8_t g = Gmean;
        uint8_t b = Bmean;

        if (i < Ridx) r ++;
        if (i < Gidx) g ++;
        if (i < Bidx) b ++;

        _ledstrip->SetPixelColor(i,RgbColor(r,g,b));
      }

      _ledstrip->Show();
    }
  }
}
