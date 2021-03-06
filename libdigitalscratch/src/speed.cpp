/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                           Digital Scratch System                           */
/*                                                                            */
/*                                                                            */
/*--------------------------------------------------------------( speed.cpp )-*/
/*                                                                            */
/*  Copyright (C) 2003-2013                                                   */
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
/*          Speed class : define the playing music speed concept              */
/*                                                                            */
/*============================================================================*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "include/dscratch_parameters.h"
#include "include/speed.h"
#include "include/utils.h"

Speed::Speed(string turntable_name) : Playing_parameter(turntable_name)
{
    Utils::trace_object_life(TRACE_PREFIX_SPEED, "+ Creating Speed object...");

    // Internal stuff.
    this->nb_no_new_speed_found     = 0;
    this->value                     = 0.0;
    this->wait_cycle_for_starting   = 0;

    // Default values used for speed calculation.
    this->set_max_nb_no_new_speed_found(DEFAULT_MAX_NB_NO_NEW_SPEED_FOUND);
    this->set_max_nb_cycle_before_starting(DEFAULT_MAX_NB_CYCLE_BEFORE_STARTING);

    Utils::trace_object_life(TRACE_PREFIX_SPEED, "+ Speed object created");
}

Speed::~Speed()
{
    Utils::trace_object_life(TRACE_PREFIX_SPEED, "- Deleting Speed object...");

    Utils::trace_object_life(TRACE_PREFIX_SPEED, "- Speed object deleted");
}

float Speed::get_value()
{
    return this->value;
}

bool Speed::set_value(float speed_value)
{
    this->old_value = this->value;

    //
    // Try to check if we can not find new signal.
    //
    if (speed_value == NO_NEW_SPEED_FOUND) // No new speed found.
    {
        /*if (this->nb_no_new_speed_found <= this->max_nb_no_new_speed_found)
        {
            this->nb_no_new_speed_found++;
        }
        */
        this->nb_no_new_speed_found++;

        // No new speed for 3 times (for example), speed = 0.
        if (this->nb_no_new_speed_found > this->max_nb_no_new_speed_found)
        {
            Utils::trace_speed(TRACE_PREFIX_SPEED,
                "No new speed found for " \
                + Utils::to_string(this->max_nb_no_new_speed_found) \
                + " times, speed = 0");

            this->value = 0.0;
            this->nb_no_new_speed_found = 0;
        }
        else
        {
            Utils::trace_speed(TRACE_PREFIX_SPEED,
                "No new speed found, don't change speed");

            this->value = NO_NEW_SPEED_FOUND;
        }
    }
    else // New speed found.
    {
        this->nb_no_new_speed_found = 0;

        this->value = speed_value;

        // Debugging message for new speed value.
        #ifdef TRACE_OBJECT_ATTRIBUTS_CHANGE
            if (this->value == NO_NEW_SPEED_FOUND)
            {
                Utils::trace_object_attributs_change(TRACE_PREFIX_SPEED,
                    "Changing speed value to NO_NEW_SPEED_FOUND");
            }
            else
            {
                Utils::trace_object_attributs_change(TRACE_PREFIX_SPEED,
                    "Changing speed value to " + Utils::to_string(this->value));
            }
        #endif
    }

    return true;
}

int Speed::get_max_nb_no_new_speed_found()
{
    return this->max_nb_no_new_speed_found;
}

bool Speed::set_max_nb_no_new_speed_found(int nb)
{
    if (nb <= 0)
    {
        Utils::trace_error(TRACE_PREFIX_SPEED,
                "max_nb_no_new_speed_found must be > 0.");
        return false;
    }

    this->max_nb_no_new_speed_found = nb;

    return true;
}

int Speed::get_max_nb_cycle_before_starting()
{
    return this->max_nb_cycle_before_starting;
}

bool Speed::set_max_nb_cycle_before_starting(int nb)
{
    if (nb <= 0)
    {
        Utils::trace_error(TRACE_PREFIX_SPEED,
                "max_nb_cycle_before_starting must be > 0.");
        return false;
    }

    this->max_nb_cycle_before_starting = nb;

    return true;
}
