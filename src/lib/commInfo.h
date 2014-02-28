/*
 *	commInfo.h
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

#ifndef _commInfo_h
#define _commInfo_h

#include <stdio.h>
#include <string.h>
#include "dbAccess.h"
#include "errors.h"

#define commTable        "PLCConnections"

typedef struct{
    unsigned int id;
    unsigned int rack;
    unsigned int slot;
    unsigned int port;
    char ip[16];	
} PLC_CONN_INFO;


PLC_CONN_INFO* linCCPLCgetInfo();

#endif // _commInfo_h
