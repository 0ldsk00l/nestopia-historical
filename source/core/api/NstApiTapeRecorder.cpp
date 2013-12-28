////////////////////////////////////////////////////////////////////////////////////////
//
// Nestopia - NES / Famicom emulator written in C++
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

#include "../NstCore.hpp"
#include "../NstImage.hpp"
#include "NstApiEmulator.hpp"
#include "NstApiMachine.hpp"
#include "../NstDataRecorder.hpp"
#include "NstApiTapeRecorder.hpp"

#ifdef NST_PRAGMA_OPTIMIZE
#pragma optimize("s", on)
#endif

namespace Nes
{
	namespace Api
	{
		Core::DataRecorder* TapeRecorder::Query() const
		{
			if (emulator.image && emulator.Is(Machine::ON))
			{
				if (Core::Image::ExternalDevice device = emulator.image->QueryExternalDevice( Core::Image::EXT_DATA_RECORDER ))
					return static_cast<Core::DataRecorder*>(device);
			}

			return NULL;
		}

		bool TapeRecorder::IsStopped() const
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->IsStopped();

			return true;
		}

		bool TapeRecorder::IsPlaying() const
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->IsPlaying();

			return false;
		}
	
		bool TapeRecorder::IsRecording() const
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->IsRecording();

			return false;
		}

		bool TapeRecorder::CanPlay() const
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->CanPlay();

			return false;
		}

		Result TapeRecorder::Play()
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->Play();

			return RESULT_ERR_NOT_READY;
		}
	
		Result TapeRecorder::Record()
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				return dataRecorder->Record();

			return RESULT_ERR_NOT_READY;
		}
	
		void TapeRecorder::Stop()
		{
			if (Core::DataRecorder* const dataRecorder = Query())
				dataRecorder->Stop();
		}
	}
}

#ifdef NST_PRAGMA_OPTIMIZE
#pragma optimize("", on)
#endif