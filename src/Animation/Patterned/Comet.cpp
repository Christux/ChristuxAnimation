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

#include "Comet.h"

#ifdef animationDemo // 5 pixels leds

const uint8_t Comet::cometPattern[5] = {255, 192, 60, 0, 0};

Comet::Comet(uint8_t nLeds, LedStrip* ledstrip):
  PatternedAnimation(nLeds, ledstrip, 100, cometPattern, 5)
  {};

#else

const uint8_t Comet::cometPattern[10] = {255, 238, 192, 128, 64, 18, 1, 0, 0, 0};

Comet::Comet(uint8_t nLeds, LedStrip* ledstrip):
  PatternedAnimation(nLeds, ledstrip, 100, cometPattern, 10)
  {};

#endif
