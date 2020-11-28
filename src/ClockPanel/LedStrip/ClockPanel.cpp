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

#include "ClockPanel.h"

namespace ChristuxAnimation
{
	ClockPanel::ClockPanel(
		TBegin begin,
		TShow show,
		TSetPixelColor setPixelColor,
		const int firstDigitIndexes[12],
		const int secondDigitIndexes[12],
		const int separatorIndexes[2],
		const int thirdDigitIndexes[12],
		const int fourthDigitIndexes[12]) :
        _begin(begin),
        _show(show),
        _setPixelColor(setPixelColor),
		_digits({
			ClockDigit(firstDigitIndexes, this),
			ClockDigit(secondDigitIndexes, this),
			ClockDigit(thirdDigitIndexes, this),
			ClockDigit(fourthDigitIndexes, this)
		}),
		_separator(ClockSeparator(separatorIndexes, this)),
		_separatorIndexes(separatorIndexes),
		_separatorColor(RgbColor::blank),
		_nMaskHandles(0),
		_requestedCommit(false),
		_mirror(false)
    {}

	void ClockPanel::addMaskHandle(Observer* maskHandle)
	{
		_maskHandles[_nMaskHandles++] = maskHandle;
	}

	void ClockPanel::setMirror(bool mirror)
	{
		_mirror = mirror;

		for(int i = 0; i < 4; i++)
		{
			_digits[i].setMirror(mirror);
		}
	}

	bool ClockPanel::getMirror()
	{
		return _mirror;
	}

	void ClockPanel::applyAllMasks()
	{
		for(int i = 0; i < _nMaskHandles; i++)
		{
			_maskHandles[i]->notify();
		}
	}

    void ClockPanel::begin()
    {
        _begin();
    }

	void ClockPanel::showWithMask()
	{
		applyAllMasks();
		_requestedCommit = true;
	}
	
	void ClockPanel::showWithoutMask()
	{
		_requestedCommit = true;
	}

    void ClockPanel::show()
    {
		showWithMask();
    }

	void ClockPanel::commit()
	{
		if(_requestedCommit)
		{
			_show();
			_requestedCommit = false;
		}
	}

    void ClockPanel::setAllPixels(RgbColor color)
    {
        for(int i = 0; i < pixelCount; i++)
        {
            setPixelColor(i, color);
        }
    }

    void ClockPanel::setPixelColor(int i, RgbColor color)
    {
		if(i == _separatorIndexes[0] || i == _separatorIndexes[1])
		{
			setSeparatorColor(color);
		}
		else {
			_setPixelColor(i, color);
		}
    }

	void ClockPanel::setSeparatorPixelColor(int i, RgbColor color)
	{
		if(i == _separatorIndexes[0] || i == _separatorIndexes[1])
		{
			_setPixelColor(i, color);
		}
	}

	void ClockPanel::setSeparatorColor(RgbColor color)
	{
		_separatorColor = color;
	}

	ClockDigit* ClockPanel::getDigit(int i)
	{
		if(_mirror)
		{
			return &_digits[3-i];
		}
		else
		{
			return &_digits[i];
		}
	}

	ClockSeparator* ClockPanel::getSeparator()
	{
		return &_separator;
	}

	RgbColor ClockPanel::getSeparatorColor()
	{
		return _separatorColor;
	}
}
