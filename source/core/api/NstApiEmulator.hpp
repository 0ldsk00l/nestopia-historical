////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES/Famicom emulator written in C++
//
// Copyright (C) 2003-2008 Martin Freij
//
// This file is part of Nestopia.
//
// Nestopia is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Nestopia is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Nestopia; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef NST_API_EMULATOR_H
#define NST_API_EMULATOR_H

#ifndef NST_BASE_H
#include "../NstBase.hpp"
#endif

#ifdef NST_PRAGMA_ONCE
#pragma once
#endif

#if NST_MSVC >= 1200
#pragma warning( push )
#endif

namespace Nes
{
	namespace Core
	{
		class Machine;

		namespace Video
		{
			class Output;
		}

		namespace Sound
		{
			class Output;
		}

		namespace Input
		{
			class Controllers;
		}
	}

	namespace Api
	{
		class Emulator
		{
		public:

			Emulator();
			~Emulator() throw();

			Result Execute
			(
				Core::Video::Output*,
				Core::Sound::Output*,
				Core::Input::Controllers*
			)   throw();

			ulong Frame() const throw();

		private:

			Core::Machine& machine;

		public:

			operator Core::Machine& ()
			{
				return machine;
			}
		};
	}
}

#if NST_MSVC >= 1200
#pragma warning( pop )
#endif

#endif
