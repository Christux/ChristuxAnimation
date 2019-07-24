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

#ifndef ShiftRegisterLedStrip_h
#define ShiftRegisterLedStrip_h

#include <Arduino.h>
#include <ChristuxAnimation.h>

namespace ChristuxAnimation {

	class ShiftRegisterLedStrip: public LedStrip
	{
	protected:
		const uint8_t _N;
		uint8_t *_T;
		const uint8_t _clockPin;
		const uint8_t _latchPin;
		const uint8_t _dataPin;
		const uint8_t CLOCK_TEMP = 50; // u-seconds
		
	public:
		ShiftRegisterLedStrip(uint8_t nLeds, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin);
		~ShiftRegisterLedStrip();
		void Begin();
		void Show();
		void SetPixelColor(int, RgbColor);
        void SetAllPixels(RgbColor);
		
	private:
		inline void putch() const;
		inline void clock() const;
		inline void latch() const;
	};

	/*
	* Construtor
	*/
	ShiftRegisterLedStrip::ShiftRegisterLedStrip(uint8_t nLeds, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin) :
		_N(nLeds),
		_T((uint8_t*)malloc(_N)),
		_clockPin(clockPin),
		_latchPin(latchPin),
		_dataPin(dataPin)
	{}

	ShiftRegisterLedStrip::~ShiftRegisterLedStrip() {
		free(_T);
	}

	/*
	* Setup transmission pins
	*/
	void ShiftRegisterLedStrip::Begin() {
		pinMode(_latchPin, OUTPUT);
		pinMode(_clockPin, OUTPUT);
		pinMode(_dataPin, OUTPUT);
	}

	/*
	* Sets value of the i-th led
	*/
	void ShiftRegisterLedStrip::SetPixelColor(int i, RgbColor color) {
		_T[i] = color.CalculateBrightness() > 64 ? 1 : 0;
	}

	void ShiftRegisterLedStrip::SetAllPixels(RgbColor color) {
		for (int i = 0; i < _N; i++) {
			SetPixelColor(i, color);
		}
	}

	/*
	* Commits led states to the physical led strip
	*/
	void ShiftRegisterLedStrip::Show() {
		for (int i = 0; i < _N; i++) {
			digitalWrite(_dataPin, _T[_N - i - 1]);
			clock();
		}
		latch();
	}

	/*
	* Transmission methods, see data sheet of your shiftregister
	*/
	inline void ShiftRegisterLedStrip::putch() const {
		delayMicroseconds(CLOCK_TEMP);
	}

	inline void ShiftRegisterLedStrip::clock() const {
		digitalWrite(_clockPin, HIGH);
		putch();
		digitalWrite(_clockPin, LOW);
		putch();
	}

	inline void ShiftRegisterLedStrip::latch() const {
		digitalWrite(_latchPin, HIGH);
		putch();
		digitalWrite(_latchPin, LOW);
		putch();
	}
}
#endif
