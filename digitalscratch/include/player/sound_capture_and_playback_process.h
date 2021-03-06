/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                           Digital Scratch Player                           */
/*                                                                            */
/*                                                                            */
/*-----------------------------------( sound_capture_and_playback_process.h )-*/
/*                                                                            */
/*  Copyright (C) 2003-2012                                                   */
/*                Julien Rosener <julien.rosener@digital-scratch.org>         */
/*                                                                            */
/*----------------------------------------------------------------( License )-*/
/*                                                                            */
/*  This program is free software: you can redistribute it and/or modify      */
/*  it under the terms of the GNU General Public License as published by      */ 
/*  the Free Software Foundation, either version 3 of the License, or         */
/*  (at your option) any later version.                                       */
/*                                                                            */
/*  This package is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program. If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                            */
/*------------------------------------------------------------( Description )-*/
/*                                                                            */
/* Behavior class: process called each time there are new captured data and   */
/*                 playable data are ready.                                   */
/*                                                                            */
/*============================================================================*/

#ifndef SOUND_CAPTURE_AND_PLAYBACK_PROCESS_H_
#define SOUND_CAPTURE_AND_PLAYBACK_PROCESS_H_

#include <timecode_analyzis_process.h>
#include <audio_track_playback_process.h>
#include <sound_card_access_rules.h>
#include <application_const.h>

using namespace std;

class Sound_capture_and_playback_process
{
 private:
    Timecode_analyzis_process    *tcode_analyzis;
    Audio_track_playback_process *playback;
    Sound_card_access_rules      *sound_card;

 public:
    Sound_capture_and_playback_process(Timecode_analyzis_process    *in_tcode_analyzis,
                                       Audio_track_playback_process *in_playback,
                                       Sound_card_access_rules      *in_sound_card);
    virtual ~Sound_capture_and_playback_process();

    bool run(unsigned short int in_nb_buffer_frames);
};

#endif /* SOUND_CAPTURE_AND_PLAYBACK_PROCESS_H_ */
