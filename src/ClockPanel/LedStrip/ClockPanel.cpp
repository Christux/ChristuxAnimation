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
		TBegin Begin,
		TShow Show,
		TSetPixelColor SetPixelColor,
		const int firstDigitIndexes[12],
		const int secondDigitIndexes[12],
		const int separatorIndexes[2],
		const int thirdDigitIndexes[12],
		const int fourthDigitIndexes[12]) :
        _begin(Begin),
        _show(Show),
        _setPixelColor(SetPixelColor),
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
		_requestedCommit(false)
    {}

	void ClockPanel::AddMaskHandle(Observer* maskHandle)
	{
		_maskHandles[_nMaskHandles++] = maskHandle;
	}

	void ClockPanel::ApplyAllMasks()
	{
		for(int i = 0; i < _nMaskHandles; i++)
		{
			_maskHandles[i]->notify();
		}
	}

    void ClockPanel::Begin()
    {
        _begin();
    }

	void ClockPanel::ShowWithMask()
	{
		ApplyAllMasks();
		_requestedCommit = true;
	}
	
	void ClockPanel::ShowWithoutMask()
	{
		_requestedCommit = true;
	}

    void ClockPanel::Show()
    {
		ShowWithMask();
    }

	void ClockPanel::Commit()
	{
		if(_requestedCommit)
		{
			_show();
			_requestedCommit = false;
		}
	}

    void ClockPanel::SetAllPixels(RgbColor color)
    {
        for(int i = 0; i < pixelCount; i++)
        {
            SetPixelColor(i, color);
        }
    }

    void ClockPanel::SetPixelColor(int i, RgbColor color)
    {
		if(i == _separatorIndexes[0] || i == _separatorIndexes[1])
		{
			_separatorColor = color;
		}
		else {
			_setPixelColor(i, color);
		}
    }

	void ClockPanel::SetSeparatorPixelColor(int i, RgbColor color)
	{
		if(i == _separatorIndexes[0] || i == _separatorIndexes[1])
		{
			_setPixelColor(i, color);
		}
	}

	ClockDigit* ClockPanel::GetDigit(int i)
	{
		return &_digits[i];
	}

	ClockSeparator* ClockPanel::GetSeparator()
	{
		return &_separator;
	}

	RgbColor ClockPanel::GetSeparatorColor()
	{
		return _separatorColor;
	}
}
