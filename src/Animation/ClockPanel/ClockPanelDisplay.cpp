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

#include "ClockPanelDisplay.h"

namespace ChristuxAnimation
{
	ClockPanelDisplay::ClockPanelDisplay(ClockPanel *clockPanel, TSetTime setTime) : GenericAnimation(50, clockPanel),
																   _clockPanel(clockPanel),
																   _setTime(setTime),
																   _delay(500),
																   _nextFlicker(0),
																   _separatorState(true)
	{
	}

	void ClockPanelDisplay::reset()
	{
		_clockPanel->SetAllPixels(RgbColor::blank);
	}

	void ClockPanelDisplay::handle()
	{
		unsigned long currTime = millis();

		if (currTime >= _nextFlicker)
		{
			run();
			_nextFlicker = currTime + _delay;
		}
	}

	void ClockPanelDisplay::run()
	{
		ClockTime time = _setTime();

		uint8_t hourDecade = time.Hour / 10;

		if(hourDecade == 0)
		{
			_clockPanel->GetDigit(0)->SetAllPixels(RgbColor::blank);
		}
		else
		{
			displayDigit(0, hourDecade);
		}		
		
		displayDigit(1, time.Hour % 10);
		displayDigit(2, time.Minute / 10);
		displayDigit(3, time.Minute % 10);

		if(_separatorState)
		{
			_clockPanel->GetSeparator()->SetAllPixels(_color);
		}
		else
		{
			_clockPanel->GetSeparator()->SetAllPixels(
				_color.ChangeBrightness(_color.CalculateBrightness() / 2)
			);
		}
		
		_separatorState = !_separatorState;

		_clockPanel->Show();
	}

	void ClockPanelDisplay::displayDigit(uint8_t digitIndex, uint8_t number)
	{
		_clockPanel->GetDigit(digitIndex)->SetPattern(_numbers[number], _color);
	}

} // namespace ChristuxAnimation
