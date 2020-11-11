/*
 * Copyright (c) 2012 Christophe Rubeck.
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

#ifndef ChristuxAnimation_rainbowclockpanel_h
#define ChristuxAnimation_rainbowclockpanel_h

#include "../LedStrip/ClockPanel.h"
#include "../../Animation/Temporized/Base/TemporizedAnimation.h"
#include "../../RainbowTable/RainbowTable.h"

namespace ChristuxAnimation
{
	class RainbowClockPanel : public TemporizedAnimation
	{
	public:
		RainbowClockPanel(ClockPanel *);
		~RainbowClockPanel(){};

	protected:
		ClockPanel * _clockPanel;
		static const int _indexes[12];
		void run();
		RgbColor getRainbowColor(int);
	};
} // namespace ChristuxAnimation
#endif
