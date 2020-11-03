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

#include "Number.h"

namespace ChristuxAnimation
{
	const bool Number::Zero[] = {
			 1,1,
			1,0,1,
			 0,0,
			1,0,1,
			 1,1
	};

	const bool Number::One[] = {
			 0,1,
			0,0,1,
			 0,1,
			0,0,1,
			 0,1
	};

	const bool Number::Two[] = {
			 1,1,
			0,0,1,
			 1,1,
			1,0,0,
			 1,1
	};

	const bool Number::Three[] = {
			 1,1,
			0,0,1,
			 1,1,
			0,0,1,
			 1,1
	};

	const bool Number::Four[] = {
			 1,0,
			1,0,1,
			 1,1,
			0,0,1,
			 0,1
	};

	const bool Number::Five[] = {
			 1,1,
			1,0,0,
			 1,1,
			0,0,1,
			 1,1
	};

	const bool Number::Six[] = {
			 0,1,
			0,1,0,
			 1,1,
			1,0,1,
			 1,1
	};

	const bool Number::Seven[] = {
			 1,1,
			0,0,1,
			 0,1,
			0,1,0,
			 1,0
	};

	const bool Number::Height[] = {
			 1,1,
			1,0,1,
			 1,1,
			1,0,1,
			 1,1
	};

	const bool Number::Nine[] = {
			 1,1,
			1,0,1,
			 1,1,
			0,1,0,
			 1,0
	};
} // namespace ChristuxAnimation
