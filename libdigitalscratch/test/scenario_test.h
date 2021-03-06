/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                           Digital Scratch System                           */
/*                                 Scenario tests                             */
/*                                                                            */
/*                                                                            */
/*--------------------------------------------------------[ scenario_test.h ]-*/
/*                                                                            */
/*  Copyright (C) 2003-2007                                                   */
/*                Julien Rosener <julien.rosener@digital-scratch.org>         */
/*                                                                            */
/*----------------------------------------------------------------( License )-*/
/*                                                                            */
/*  This program is free software; you can redistribute it and/or modify      */
/*  it under the terms of the GNU General Public License as published by      */
/*  the Free Software Foundation; either version 2 of the License, or         */
/*  (at your option) any later version.                                       */
/*                                                                            */
/*  This program is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program; if not, write to the Free Software               */
/*  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA */
/*                                                                            */
/*------------------------------------------------------------( Description )-*/
/*                                                                            */
/*                               Scenario tests                               */
/*                                                                            */
/*============================================================================*/

/**
 * Scenario tested: normal behaviour (create, run, stop and delete turntable).
 *
 * Steps:
 *    - dscratch_create_turntable_from_config_file()
 *    - dscratch_register_change_playback_properties_callback_function()
 *    - dscratch_start()
 *    - dscratch_stop()
 *    - dscratch_delete_turntable()
 *
 * Result expected:
 *    - every steps should return 0.
 */
int scenario_test_01();
