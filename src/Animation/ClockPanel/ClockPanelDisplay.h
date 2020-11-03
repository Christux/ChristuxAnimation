/*
 * Copyright (c) 2020 Christophe Rubeck.
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

#ifndef ChristuxAnimation_clockpaneldisplay_h
#define ChristuxAnimation_clockpaneldisplay_h

#include "../Base/GenericAnimation.h"
#include "../../ClockPanel/ClockPanel.h"
#include "Definition/Number.h"

namespace ChristuxAnimation
{
	class ClockPanelDisplay : public GenericAnimation
	{
	protected:
		ClockPanel *_clockPanel;
		unsigned const long _delay;
		unsigned long _nextFlicker;
		uint8_t _hours;
		uint8_t _minutes;
		uint8_t _seconds;
		bool _separatorState;
		const bool* _numbers[10] = {
			Number::Zero,
			Number::One,
			Number::Two,
			Number::Three,
			Number::Four,
			Number::Five,
			Number::Six,
			Number::Seven,
			Number::Height,
			Number::Nine
		};
		void run();
		void displayDigit(uint8_t, uint8_t);

	public:
		ClockPanelDisplay(ClockPanel *);
		~ClockPanelDisplay(){};
		void reset();
		void handle();
		void setTime(uint8_t, uint8_t, uint8_t);
	};
} // namespace ChristuxAnimation
#endif
