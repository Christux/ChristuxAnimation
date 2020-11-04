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

#ifndef ChristuxAnimation_clocktime_h
#define ChristuxAnimation_clocktime_h

#include <Arduino.h>

namespace ChristuxAnimation
{
	struct ClockTime
	{
	public:
		uint8_t Hour;
		uint8_t Minute;
		uint8_t Second;
		ClockTime(uint8_t, uint8_t, uint8_t);
		ClockTime();
		~ClockTime(){};

		bool operator==(const ClockTime &other) const
		{
			return (Hour == other.Hour && Minute == other.Minute && Second == other.Second);
		}

		bool operator!=(const ClockTime &other) const
		{
			return !(*this == other);
		}
	};
} // namespace ChristuxAnimation

#endif
