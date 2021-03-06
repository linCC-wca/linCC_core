/*  
 *  getTriggers.h
 *
 *  "Copyright 2014 Mauro Ghedin"
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  or any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 *
 *       @author         : Mauro Ghedin
 *       @contact        : domyno88 at gmail dot com
 *       @version        : 0.1
 *
 */

#ifndef _getTriggers_h_
#define _getTriggers_h_

#include "linCC.h"
#include "libLog.h"
#include "error.h"
#include "dbAccess.h"

/**************************************************************************************************************************
 *
 *     For ERROR codes about exit() function or value returned by the
 *     the functions, refer to linCC wiki or errors.h header in: 
 *     $linCCPATH/errors/
 * 
 *************************************************************************************************************************/ 
 
int getTriggers( TRIGGER_TIME** trgTime, unsigned long* trgTimeCount );

#endif  // _getTriggers_h_
