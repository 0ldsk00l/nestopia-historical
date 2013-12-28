////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES / Famicom emulator written in C++
//
// Copyright (C) 2003-2005 Martin Freij
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

#ifndef NST_API_H
#define NST_API_H

#ifdef NST_PRAGMA_ONCE_SUPPORT
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( push )
#endif

#include "../NstCore.hpp"

#ifndef NST_CALLBACK
#define NST_CALLBACK NST_CALL
#endif

namespace Nes
{
	namespace Core
	{
		template<typename T> 
		class UserCallback
		{
		public:

			typedef void* UserData;
			typedef T Function;

		protected:

			Function function;
			UserData userdata;

			UserCallback()
			: function(NULL), userdata(NULL) {}

		public:

			void Set(Function f,UserData d)
			{
				function = f;
				userdata = d;
			}

			void Get(Function& f,UserData& d) const
			{
				f = function;
				d = userdata;
			}
		};
	}

	namespace Api
	{
		class Emulator;
		class Machine;
		class Video;
		class Sound;
		class Input;
		class User;
		class Cartridge;
		class Fds;
		class Nsf;
		class Movie;
		class GameGenie;
		class DipSwitches;

		class Base
		{
		public:

			typedef void* UserData;

		protected:

			Emulator& emulator;

			Base(Emulator& e)
			: emulator(e) {}
		};
	}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif
