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

#include "../NstMapper.hpp"
#include "../board/NstBrdMmc3.hpp"
#include "../board/NstBrdTaiwanMmc3.hpp"
#include "NstMapper074.hpp"

namespace Nes
{
	namespace Core
	{
        #ifdef NST_PRAGMA_OPTIMIZE
        #pragma optimize("s", on)
        #endif
	
		uint Mapper74::GetType(dword crc)
		{
			switch (crc)
			{
       			case 0xC856F188UL: return CRAM_4K; // Crystalis (C)
				case 0x1A13BA25UL: return CRAM_4K; // Captain Tsubasa Vol 2 - Super Striker (C)
				case 0xE80D8741UL: return CRAM_8K; // Sangokushi - Hanou No Tairiku (C)
				case 0xA3279880UL: return CRAM_8K; // Dragon Ball Z 2 - Gekishin Freeza! (C)
				case 0x12B496E2UL: return CRAM_8K; // Dragon Ball Z Gaiden - Saiya Jin Zetsumetsu Keikaku (C)
			}

			return CRAM_2K;
		}

		Mapper74::Mapper74(Context& c)
		: 
		TaiwanMmc3 (c,GetType(c.pRomCrc)), 
		type       (GetType(c.pRomCrc))
		{}

		void Mapper74::SubLoad(State::Loader& state)
		{
			while (const dword chunk = state.Begin())
			{
				if (chunk == NES_STATE_CHUNK_ID('E','C','H','\0'))
				{
					NST_VERIFY( type == CRAM_8K );

					if (type == CRAM_8K)
					{
						const State::Loader::Data<2> data( state );

						exChr[0] = data[0];
						exChr[1] = data[1];
					}
				}

				state.End();
			}
		}

		void Mapper74::SubSave(State::Saver& state) const
		{
			if (type == CRAM_8K)
			{
				const u8 data[] = { exChr[0], exChr[1] };
				state.Begin('E','C','H','\0').Write( data ).End();
			}
		}
	
		void Mapper74::SubReset(const bool hard)
		{
			exChr[1] = exChr[0] = 0;

			TaiwanMmc3::SubReset( hard );

			if (type == CRAM_8K)
			{
				for (uint i=0x0000U; i < 0x2000U; i += 0x2)
					Map( i + 0x8001U, &Mapper74::Poke_8001 );
			}
		}

        #ifdef NST_PRAGMA_OPTIMIZE
        #pragma optimize("", on)
        #endif

		NES_POKE(Mapper74,8001)
		{
			NST_ASSERT( type == CRAM_8K );

			address = regs.ctrl0 & 0xF;

			switch (address)
			{
				case 0x0:
				case 0x1:
				case 0x2:
				case 0x3:
				case 0x4:
				case 0x5:

					banks.chr[address] = data;
					Mapper74::UpdateChr();
					break;

				case 0x6:
				case 0x7:
				case 0x8:
				case 0x9:

					banks.prg[address - 0x6] = data;
					TaiwanMmc3::UpdatePrg();
					break;
				
				case 0xA:
				case 0xB:

					exChr[address - 0xA] = data;
					Mapper74::UpdateChr();
					break;
			}
		}

		uint Mapper74::GetChrSource(uint bank) const
		{
			NST_ASSERT( type == CRAM_4K || type == CRAM_2K );
			return (type == CRAM_4K) ? (bank - 0U <= 3U) : (bank - 8U <= 1U);
		}

		void Mapper74::UpdateChr() const
		{
			if (type == CRAM_8K)
			{
				ppu.Update();

				const uint swap = (regs.ctrl0 & Regs::CTRL0_XOR_CHR) << 5;

				chr.Source( banks.chr[0] <= 7 ).SwapBank<SIZE_1K>( 0x0000U ^ swap, banks.chr[0] ); 
				chr.Source( exChr[0]     <= 7 ).SwapBank<SIZE_1K>( 0x0400U ^ swap, exChr[0]     ); 
				chr.Source( banks.chr[1] <= 7 ).SwapBank<SIZE_1K>( 0x0800U ^ swap, banks.chr[1] ); 
				chr.Source( exChr[1]     <= 7 ).SwapBank<SIZE_1K>( 0x0C00U ^ swap, exChr[1]     ); 
				chr.Source( banks.chr[2] <= 7 ).SwapBank<SIZE_1K>( 0x1000U ^ swap, banks.chr[2] ); 
				chr.Source( banks.chr[3] <= 7 ).SwapBank<SIZE_1K>( 0x1400U ^ swap, banks.chr[3] ); 
				chr.Source( banks.chr[4] <= 7 ).SwapBank<SIZE_1K>( 0x1800U ^ swap, banks.chr[4] ); 
				chr.Source( banks.chr[5] <= 7 ).SwapBank<SIZE_1K>( 0x1C00U ^ swap, banks.chr[5] ); 
			}
			else
			{
				TaiwanMmc3::UpdateChr();
			}
		}
	}
}
