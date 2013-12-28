////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES/Famicom emulator written in C++
//
// Copyright (C) 2003-2006 Martin Freij
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

#include "../NstState.hpp"
#include "../NstCpu.hpp"
#include "../vssystem/NstVsSystem.hpp"
#include "../vssystem/NstVsRbiBaseball.hpp"

namespace Nes
{
	namespace Core
	{
		#ifdef NST_PRAGMA_OPTIMIZE
		#pragma optimize("s", on)
		#endif

		void VsRbiBaseball::Reset()
		{
			cpu.Map( 0x5E00U ).Set( &VsRbiBaseball::Peek_5E00 );
			cpu.Map( 0x5E01U ).Set( &VsRbiBaseball::Peek_5E01 );

			counter = 0;
		}

		void VsRbiBaseball::SubSave(State::Saver& state) const
		{
			state.Begin('R','B','I','\0').Write8( counter & 0xFF ).End();
		}

		void VsRbiBaseball::SubLoad(State::Loader& state,const dword id)
		{
			if (id == NES_STATE_CHUNK_ID('R','B','I','\0'))
				counter = state.Read8();
		}

		#ifdef NST_PRAGMA_OPTIMIZE
		#pragma optimize("", on)
		#endif

		NES_PEEK(VsRbiBaseball,5E00)
		{
			counter = 0;
			return 0x00;
		}

		NES_PEEK(VsRbiBaseball,5E01)
		{
			return (counter++ == 0x9) ? 0x6F : 0xB4;
		}
	}
}
