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

#include "ClockPanelAnimator.h"

namespace ChristuxAnimation
{
	ClockPanelAnimator::ClockPanelAnimator(ClockPanel *clockPanel, TSetTime setTime) : Animator(),
																   _clockPanel(clockPanel),
																   _setTime(setTime),
																   _refreshDelay(20),
																   _nextRefreshFlicker(0),
																   _triggerDelay(200),
																   _nextTriggerFlicker(0),
																   _separatorAnimator(Animator())
	{ 
		_clockPanel->addMaskHandle(this);
	}

	void ClockPanelAnimator::addSeparator(Animation* animation)
	{
		_separatorAnimator.add(animation);
	}

	void ClockPanelAnimator::setSeparatorAnimation(uint8_t anim)
	{
		_separatorAnimator.setAnimation(anim);
	}

	void ClockPanelAnimator::notify()
	{
		applyMask();
	}

	void ClockPanelAnimator::setColor(RgbColor color)
	{
		Animator::setColor(color);
		_separatorAnimator.setColor(color);
	}

	void ClockPanelAnimator::handle()
	{
		handleAnimations();
		refreshLeds();
		triggerAnimation();
	}

	void ClockPanelAnimator::handleAnimations()
	{
		// Main animation
		Animator::handle();

		// Set separator color and play animation
		_separatorAnimator.setColor(_clockPanel->getSeparatorColor());
		_separatorAnimator.handle();
	}

	void ClockPanelAnimator::refreshLeds()
	{
		unsigned long currTime = millis();

		if (currTime >= _nextRefreshFlicker)
		{
			_clockPanel->commit();
			_nextRefreshFlicker = currTime + _refreshDelay;
		}
	}

	void ClockPanelAnimator::triggerAnimation()
	{
		unsigned long currTime = millis();

		if (currTime >= _nextTriggerFlicker)
		{
			// tip to trigger static animations
			_animations[_currentAnim]->setColor(_currentColor);
			_nextTriggerFlicker = currTime + _triggerDelay;
		}
	}

	void ClockPanelAnimator::applyMask()
	{
		ClockTime time = _setTime();
		uint8_t hourDecade = time.Hour / 10;

		if(hourDecade == 0)
		{
			_clockPanel->getDigit(0)->setAllPixels(RgbColor::blank);
		}
		else
		{
			displayDigit(0, hourDecade);
		}
		
		displayDigit(1, time.Hour % 10);
		displayDigit(2, time.Minute / 10);
		displayDigit(3, time.Minute % 10);
	}

	void ClockPanelAnimator::displayDigit(uint8_t digitIndex, uint8_t number) const
	{
		_clockPanel->getDigit(digitIndex)->SetMask(_numbers[number]);
	}

} // namespace ChristuxAnimation
