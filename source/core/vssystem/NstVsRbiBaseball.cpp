////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES / Famicom emulator written in C++
//
// Copyright (C) 2003 Martin Freij
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

#include "../NstTypes.h"
#include "../NstMap.h"
#include "../NstCpu.h"
#include "../vssystem/NstVsSystem.h"
#include "../vssystem/NstVsRbiBaseball.h"

NES_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////

VOID VSRBIBASEBALL::Reset()
{
	cpu->SetPort( 0x5E00, this, Peek_5E00, Poke );
	cpu->SetPort( 0x5E01, this, Peek_5E01, Poke );	
	counter = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////

NES_PEEK(VSRBIBASEBALL,5E00)
{
	counter = 0;
	return 0x00;
}

////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////

NES_PEEK(VSRBIBASEBALL,5E01)
{
	return (counter++ == 0x9) ? 0x6F : 0xB4;
}

NES_NAMESPACE_END
