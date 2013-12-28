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

#include "NstApplicationException.hpp"
#include "NstApplicationMain.hpp"

#ifdef _MSC_VER

 #ifdef NDEBUG
  #pragma comment(lib,"emucore")
 #else
  #pragma comment(lib,"emucoredebug")
  #define CRTDBG_MAP_ALLOC
  #include <crtdbg.h>
 #endif

 #if _MSC_VER >= 1400
  #pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='6595b64144ccf1df' language='*'\"")
 #endif

#endif

NST_COMPILE_ASSERT
(
 	IDM_FILE_QUICK_SAVE_STATE_SLOT_1 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 1 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_2 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 2 &&
	IDM_FILE_QUICK_SAVE_STATE_SLOT_3 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 3 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_4 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 4 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_5 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 5 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_6 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 6 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_7 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 7 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_8 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 8 &&	 
	IDM_FILE_QUICK_SAVE_STATE_SLOT_9 == IDM_FILE_QUICK_SAVE_STATE_SLOT_NEXT + 9	&&

	IDM_FILE_QUICK_LOAD_STATE_SLOT_1 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 1 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_2 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 2 &&
	IDM_FILE_QUICK_LOAD_STATE_SLOT_3 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 3 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_4 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 4 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_5 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 5 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_6 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 6 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_7 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 7 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_8 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 8 &&	 
	IDM_FILE_QUICK_LOAD_STATE_SLOT_9 == IDM_FILE_QUICK_LOAD_STATE_SLOT_LAST + 9	&&

	IDM_FILE_RECENT_2 == IDM_FILE_RECENT_1 + 1 &&
	IDM_FILE_RECENT_3 == IDM_FILE_RECENT_1 + 2 &&
	IDM_FILE_RECENT_4 == IDM_FILE_RECENT_1 + 3 &&
	IDM_FILE_RECENT_5 == IDM_FILE_RECENT_1 + 4 &&
	IDM_FILE_RECENT_6 == IDM_FILE_RECENT_1 + 5 &&
	IDM_FILE_RECENT_7 == IDM_FILE_RECENT_1 + 6 &&
	IDM_FILE_RECENT_8 == IDM_FILE_RECENT_1 + 7 &&
	IDM_FILE_RECENT_9 == IDM_FILE_RECENT_1 + 8 &&

	IDM_FILE_RECENT_DIR_2 == IDM_FILE_RECENT_DIR_1 + 1 &&
	IDM_FILE_RECENT_DIR_3 == IDM_FILE_RECENT_DIR_1 + 2 &&
	IDM_FILE_RECENT_DIR_4 == IDM_FILE_RECENT_DIR_1 + 3 &&
	IDM_FILE_RECENT_DIR_5 == IDM_FILE_RECENT_DIR_1 + 4 &&

	IDM_MACHINE_INPUT_PORT1_PAD1		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  1 &&  
	IDM_MACHINE_INPUT_PORT1_PAD2		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  2 && 
	IDM_MACHINE_INPUT_PORT1_PAD3		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  3 && 
	IDM_MACHINE_INPUT_PORT1_PAD4	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  4 && 
	IDM_MACHINE_INPUT_PORT1_ZAPPER	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  5 && 
	IDM_MACHINE_INPUT_PORT1_PADDLE	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  6 && 
	IDM_MACHINE_INPUT_PORT1_POWERPAD            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  7 && 
	IDM_MACHINE_INPUT_PORT1_MOUSE               == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  8 && 
	IDM_MACHINE_INPUT_PORT2_UNCONNECTED         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED +  9 && 
	IDM_MACHINE_INPUT_PORT2_PAD1		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 10 &&
	IDM_MACHINE_INPUT_PORT2_PAD2		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 11 && 
	IDM_MACHINE_INPUT_PORT2_PAD3	  	        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 12 &&  
	IDM_MACHINE_INPUT_PORT2_PAD4	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 13 && 
	IDM_MACHINE_INPUT_PORT2_ZAPPER	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 14 && 
	IDM_MACHINE_INPUT_PORT2_PADDLE	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 15 && 
	IDM_MACHINE_INPUT_PORT2_POWERPAD            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 16 && 
	IDM_MACHINE_INPUT_PORT2_MOUSE               == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 17 && 
	IDM_MACHINE_INPUT_PORT3_UNCONNECTED         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 18 && 
	IDM_MACHINE_INPUT_PORT3_PAD1		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 19 && 
	IDM_MACHINE_INPUT_PORT3_PAD2		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 20 && 
	IDM_MACHINE_INPUT_PORT3_PAD3		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 21 &&
	IDM_MACHINE_INPUT_PORT3_PAD4	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 22 && 
	IDM_MACHINE_INPUT_PORT4_UNCONNECTED         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 23 && 
	IDM_MACHINE_INPUT_PORT4_PAD1		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 24 && 
	IDM_MACHINE_INPUT_PORT4_PAD2		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 25 && 
	IDM_MACHINE_INPUT_PORT4_PAD3		        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 26 && 
	IDM_MACHINE_INPUT_PORT4_PAD4	            == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 27 && 
	IDM_MACHINE_INPUT_EXP_UNCONNECTED           == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 28 &&
	IDM_MACHINE_INPUT_EXP_FAMILYTRAINER         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 29 &&
	IDM_MACHINE_INPUT_EXP_FAMILYBASICKEYBOARD   == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 30 &&
	IDM_MACHINE_INPUT_EXP_SUBORKEYBOARD         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 31 &&
	IDM_MACHINE_INPUT_EXP_DOREMIKKOKEYBOARD     == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 32 &&
	IDM_MACHINE_INPUT_EXP_PADDLE                == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 33 &&
	IDM_MACHINE_INPUT_EXP_OEKAKIDSTABLET        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 34 &&
	IDM_MACHINE_INPUT_EXP_HYPERSHOT             == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 35 &&
	IDM_MACHINE_INPUT_EXP_CRAZYCLIMBER          == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 36 &&
	IDM_MACHINE_INPUT_EXP_MAHJONG               == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 37 &&
	IDM_MACHINE_INPUT_EXP_EXCITINGBOXING        == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 38 &&
	IDM_MACHINE_INPUT_EXP_TOPRIDER              == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 39 &&
	IDM_MACHINE_INPUT_EXP_POKKUNMOGURAA         == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 40 &&
	IDM_MACHINE_INPUT_EXP_PARTYTAP              == IDM_MACHINE_INPUT_PORT1_UNCONNECTED + 41 &&

	IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  1 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_2_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  2 &&  
	IDM_MACHINE_EXT_FDS_INSERT_DISK_2_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  3 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_3_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  4 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_3_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  5 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_4_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  6 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_4_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  7 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_5_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  8 && 
	IDM_MACHINE_EXT_FDS_INSERT_DISK_5_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A +  9 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_6_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 10 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_6_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 11 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_7_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 12 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_7_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 13 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_8_SIDE_A == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 14 &&
	IDM_MACHINE_EXT_FDS_INSERT_DISK_8_SIDE_B == IDM_MACHINE_EXT_FDS_INSERT_DISK_1_SIDE_A + 15 &&

	IDM_MACHINE_SYSTEM_NTSC == IDM_MACHINE_SYSTEM_AUTO + 1 &&
	IDM_MACHINE_SYSTEM_PAL  == IDM_MACHINE_SYSTEM_AUTO + 2 &&

	IDM_VIEW_WINDOWSIZE_2X  == IDM_VIEW_WINDOWSIZE_1X + 1 &&
	IDM_VIEW_WINDOWSIZE_3X  == IDM_VIEW_WINDOWSIZE_1X + 2 &&
	IDM_VIEW_WINDOWSIZE_4X  == IDM_VIEW_WINDOWSIZE_1X + 3 &&
	IDM_VIEW_WINDOWSIZE_5X  == IDM_VIEW_WINDOWSIZE_1X + 4 &&
	IDM_VIEW_WINDOWSIZE_6X  == IDM_VIEW_WINDOWSIZE_1X + 5 &&
	IDM_VIEW_WINDOWSIZE_7X  == IDM_VIEW_WINDOWSIZE_1X + 6 &&
	IDM_VIEW_WINDOWSIZE_8X  == IDM_VIEW_WINDOWSIZE_1X + 7 &&
	IDM_VIEW_WINDOWSIZE_9X  == IDM_VIEW_WINDOWSIZE_1X + 8 &&
	IDM_VIEW_WINDOWSIZE_MAX == IDM_VIEW_WINDOWSIZE_1X + 9 &&

	IDS_MENU_2X == IDS_MENU_1X + 1 &&
	IDS_MENU_3X == IDS_MENU_1X + 2 &&
	IDS_MENU_4X == IDS_MENU_1X + 3 &&
	IDS_MENU_5X == IDS_MENU_1X + 4 &&
	IDS_MENU_6X == IDS_MENU_1X + 5 &&
	IDS_MENU_7X == IDS_MENU_1X + 6 &&
	IDS_MENU_8X == IDS_MENU_1X + 7 &&
	IDS_MENU_9X == IDS_MENU_1X + 8 &&

	IDS_FDS_DISK_1_SIDE_B == IDS_FDS_DISK_1_SIDE_A +  1 &&
	IDS_FDS_DISK_2_SIDE_A == IDS_FDS_DISK_1_SIDE_A +  2 &&
	IDS_FDS_DISK_2_SIDE_B == IDS_FDS_DISK_1_SIDE_A +  3 &&
	IDS_FDS_DISK_3_SIDE_A == IDS_FDS_DISK_1_SIDE_A +  4 &&
	IDS_FDS_DISK_3_SIDE_B == IDS_FDS_DISK_1_SIDE_A +  5 &&
	IDS_FDS_DISK_4_SIDE_A == IDS_FDS_DISK_1_SIDE_A +  6 &&
	IDS_FDS_DISK_4_SIDE_B == IDS_FDS_DISK_1_SIDE_A +  7 &&
	IDS_FDS_DISK_5_SIDE_A == IDS_FDS_DISK_1_SIDE_A +  8 &&
	IDS_FDS_DISK_5_SIDE_B == IDS_FDS_DISK_1_SIDE_A +  9 &&
	IDS_FDS_DISK_6_SIDE_A == IDS_FDS_DISK_1_SIDE_A + 10 &&
	IDS_FDS_DISK_6_SIDE_B == IDS_FDS_DISK_1_SIDE_A + 11 &&
	IDS_FDS_DISK_7_SIDE_A == IDS_FDS_DISK_1_SIDE_A + 12 &&
	IDS_FDS_DISK_7_SIDE_B == IDS_FDS_DISK_1_SIDE_A + 13 &&
	IDS_FDS_DISK_8_SIDE_A == IDS_FDS_DISK_1_SIDE_A + 14 &&
	IDS_FDS_DISK_8_SIDE_B == IDS_FDS_DISK_1_SIDE_A + 15 &&

	IDS_SCREEN_SLOT_2 == IDS_SCREEN_SLOT_1 + 1 &&
	IDS_SCREEN_SLOT_3 == IDS_SCREEN_SLOT_1 + 2 &&
	IDS_SCREEN_SLOT_4 == IDS_SCREEN_SLOT_1 + 3 &&
	IDS_SCREEN_SLOT_5 == IDS_SCREEN_SLOT_1 + 4 &&
	IDS_SCREEN_SLOT_6 == IDS_SCREEN_SLOT_1 + 5 &&
	IDS_SCREEN_SLOT_7 == IDS_SCREEN_SLOT_1 + 6 &&
	IDS_SCREEN_SLOT_8 == IDS_SCREEN_SLOT_1 + 7 &&
	IDS_SCREEN_SLOT_9 == IDS_SCREEN_SLOT_1 + 8 &&

	IDS_SCREEN_DISK_1_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  1 &&
	IDS_SCREEN_DISK_2_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  2 &&
	IDS_SCREEN_DISK_2_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  3 &&
	IDS_SCREEN_DISK_3_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  4 &&
	IDS_SCREEN_DISK_3_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  5 &&
	IDS_SCREEN_DISK_4_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  6 &&
	IDS_SCREEN_DISK_4_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  7 &&
	IDS_SCREEN_DISK_5_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  8 &&
	IDS_SCREEN_DISK_5_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED +  9 &&
	IDS_SCREEN_DISK_6_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 10 &&
	IDS_SCREEN_DISK_6_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 11 &&
	IDS_SCREEN_DISK_7_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 12 &&
	IDS_SCREEN_DISK_7_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 13 &&
	IDS_SCREEN_DISK_8_SIDE_A_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 14 &&
	IDS_SCREEN_DISK_8_SIDE_B_INSERTED == IDS_SCREEN_DISK_1_SIDE_A_INSERTED + 15 &&

	IDS_SCREEN_DISK_2_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 1 &&
	IDS_SCREEN_DISK_3_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 2 &&
	IDS_SCREEN_DISK_4_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 3 &&
	IDS_SCREEN_DISK_5_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 4 &&
	IDS_SCREEN_DISK_6_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 5 &&
	IDS_SCREEN_DISK_7_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 6 &&
	IDS_SCREEN_DISK_8_EJECTED == IDS_SCREEN_DISK_1_EJECTED + 7
);

int WINAPI WinMain(HINSTANCE,HINSTANCE,char*,int cmdShow)
{
#if defined(_MSC_VER) && !defined(NDEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	try
	{
		return Nestopia::Application::Main( cmdShow ).Run();
	}
	catch (const Nestopia::Application::Exception& exception)
	{
		exception.Issue( Nestopia::Application::Exception::FINAL );
		return EXIT_FAILURE;
	}
	catch (const std::bad_alloc&)
	{
		Nestopia::Application::Exception( IDS_ERR_OUT_OF_MEMORY ).Issue();
		return EXIT_FAILURE;
	}
	catch (Nestopia::Application::Exception::ExitCode exitcode)
	{
		return exitcode;
	}
#ifdef NDEBUG
	catch (...)
	{
		Nestopia::Application::Exception( IDS_ERR_GENERIC ).Issue();
		return EXIT_FAILURE;
	}
#endif
}
