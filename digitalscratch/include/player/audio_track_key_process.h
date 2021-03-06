/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                           Digital Scratch Player                           */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------( audio_track_key_process.h )-*/
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
/*    Behavior class: process to compute a musical key for an audio track     */
/*                                                                            */
/*============================================================================*/

#ifndef AUDIO_TRACK_KEY_PROCESS_H_
#define AUDIO_TRACK_KEY_PROCESS_H_

#include <iostream>
#include <audio_track.h>
#include <application_const.h>
#include <keyfinder_api.h>

using namespace std;

class Audio_track_key_process
{
 private:
    Audio_track *at;

 public:
    Audio_track_key_process(Audio_track *in_at);
    virtual ~Audio_track_key_process();

    bool run();         // Compute music key of the track and set it to the Audio_track object.
};

#endif /* AUDIO_TRACK_KEY_PROCESS_H_ */
