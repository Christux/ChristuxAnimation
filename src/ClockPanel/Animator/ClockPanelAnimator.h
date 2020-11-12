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

#include "../../Animator/Animator.h"
#include "../LedStrip/ClockPanel.h"
#include "../ClockTime/ClockTime.h"
#include "../Sprites/Number.h"
#include "../../Util/Observer/Observer.h"

namespace ChristuxAnimation
{
	typedef ClockTime (*TSetTime)(void);

	class ClockPanelAnimator : public Animator, public Observer
	{
	protected:
		ClockPanel *_clockPanel;
		TSetTime _setTime;
		unsigned const long _refreshDelay;
		unsigned long _nextRefreshFlicker;
		unsigned const long _triggerDelay;
		unsigned long _nextTriggerFlicker;
		Animator _separatorAnimator;
		const bool* _numbers[10] = {
			Number::zero,
			Number::one,
			Number::two,
			Number::three,
			Number::four,
			Number::five,
			Number::six,
			Number::seven,
			Number::eight,
			Number::nine
		};
		void applyMask();
		void displayDigit(uint8_t, uint8_t) const;
		void handleAnimations();
		void refreshLeds();
		void triggerAnimation();

	public:
		ClockPanelAnimator(ClockPanel *, TSetTime);
		~ClockPanelAnimator(){};
		void setColor(RgbColor color);
		void handle();
		void notify();
		void addSeparator(Animation*);
		void setSeparatorAnimation(uint8_t);
		uint8_t getSeparatorAnimation();
		uint8_t getSeparatorCount();
	};
} // namespace ChristuxAnimation
#endif
