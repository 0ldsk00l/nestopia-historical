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

#ifndef NST_DIALOG_SOUND_H
#define NST_DIALOG_SOUND_H

#pragma once

#include "NstCollectionBitSet.hpp"
#include "NstWindowDialog.hpp"
#include "NstDirectSound.hpp"

namespace Nestopia
{
	namespace Window
	{
		class Sound
		{
			typedef DirectX::DirectSound::Adapter Adapter;
			typedef DirectX::DirectSound::Adapters Adapters;

		public:

			Sound(Managers::Emulator&,const Adapters&,const Managers::Paths&,const Configuration&);
			~Sound();

			void Save(Configuration&) const;
			uint GetVolume(uint) const;

		private:

			enum
			{
				DEFAULT_BITS = 16,
				DEFAULT_RATE = 44100,
				LATENCY_MAX = DirectX::DirectSound::LATENCY_MAX,
				DEFAULT_LATENCY = 2,
				VOLUME_MAX = 100,
				DEFAULT_VOLUME = Nes::Sound::DEFAULT_VOLUME,
				DEFAULT_MONO = 0,
				NUM_CHANNELS = 12
			};

			struct Handlers;

			struct Settings
			{
				uint adapter;
				uint latency;
				u8 volumes[NUM_CHANNELS];
			};

			uint GetDefaultAdapter() const;
			void Enable(ibool) const;
			void ResetVolumeSliders() const;
			void UpdateVolumeReset() const;

			ibool OnInitDialog      (Param&);
			ibool OnVScroll         (Param&);
			ibool OnCmdDevice       (Param&);
			ibool OnCmdResetSliders (Param&);
			ibool OnCmdDefault      (Param&);
			ibool OnCmdOk           (Param&);
			ibool OnCmdCancel       (Param&);

			const Adapters& adapters;
			Nes::Sound nes;
			Settings settings;
			Dialog dialog;

			struct ChannelLut
			{
				cstring cfg;
				ushort ctrlSlider;
				ushort ctrlValue;
				ushort channel;
			};

			static const ChannelLut channelLut[NUM_CHANNELS];

		public:

			class Recorder
			{
			public:

				explicit Recorder(const Managers::Paths&);

			private:

				struct Handlers;

				ibool OnInitDialog (Param&);
				ibool OnCmdBrowse  (Param&);
				ibool OnCmdClear   (Param&);
				ibool OnCmdOk      (Param&);
				ibool OnCmdCancel  (Param&);

				Dialog dialog;
				const Managers::Paths& paths;
				Path waveFile;

			public:

				void Open()
				{
					dialog.Open();
				}

				const Path& WaveFile() const
				{
					return waveFile;
				}
			};

		private:

			Recorder recorder;

		public:

			void Open()
			{
				dialog.Open();
			}

			Recorder& GetRecorder()
			{
				return recorder;
			}

			ibool IsSoundEnabled() const
			{
				return settings.adapter != UINT_MAX && nes.IsAudible();
			}

			uint GetAdapter() const
			{
				return settings.adapter;
			}

			uint GetLatency() const
			{
				return settings.latency;
			}
		};
	}
}

#endif
