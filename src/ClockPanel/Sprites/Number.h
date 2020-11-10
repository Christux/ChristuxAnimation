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

#ifndef ChristuxAnimation_number_h
#define ChristuxAnimation_number_h

#include <Arduino.h>

namespace ChristuxAnimation
{
	struct Number
	{
	public:
		static const bool zero[12];
		static const bool one[12];
		static const bool two[12];
		static const bool three[12];
		static const bool four[12];
		static const bool five[12];
		static const bool six[12];
		static const bool seven[12];
		static const bool eight[12];
		static const bool nine[12];
	};
} // namespace ChristuxAnimation
#endif
