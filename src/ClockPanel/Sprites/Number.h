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
		static const bool Zero[12];
		static const bool One[12];
		static const bool Two[12];
		static const bool Three[12];
		static const bool Four[12];
		static const bool Five[12];
		static const bool Six[12];
		static const bool Seven[12];
		static const bool Height[12];
		static const bool Nine[12];
	};
} // namespace ChristuxAnimation
#endif
