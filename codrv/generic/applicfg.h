/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): Edouard TISSERANT and Francis DUPIN
AT91 Port: Peter CHRISTEN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __APPLICFG_AVR__
#define __APPLICFG_AVR__

#include <string.h>
#include <stdio.h>
#include "stdint.h"
/// Convert an integer to a string in hexadecimal format
/// If you do not wants to use a lastCar, put lastCar = '\0' (end of string)
/// ex : value = 0XABCDEF and lastCar = '\n'
/// buf[0] = '0'
/// buf[1] = 'X'
/// buf[2] = 'A'
/// ....
/// buf[7] = 'F'
/// buf[8] = '\n'
/// buf[9] = '\0'
extern char *
hex_convert (char *buf, unsigned long value, char lastCar);

/// Print the string to the serial port sci
/// (sci takes the values SCI0 or SCI1)
extern void printSCI_str (char sci, const char * str);

/// Print the number in hexadecimal  to the serial port sci
/// (sci takes the values SCI0 or SCI1)
extern void printSCI_nbr (char sci, unsigned long nbr, char lastCar);
typedef unsigned          char UINT8;
typedef unsigned short     int UINT16;
typedef unsigned           int UINT32;
typedef unsigned       __int64 UINT64;/***********CAN1*/
typedef     char INT8;
typedef  short     int INT16;
typedef  int INT32;
typedef  __int64 INT64;/***********CAN1*/
// Integers
#define INTEGER8 signed char
#define INTEGER16 signed short
#define INTEGER24 signed long
#define INTEGER32 signed long
#define INTEGER40 signed long long
#define INTEGER48 signed long long
#define INTEGER56 signed long long
#define INTEGER64 signed long long

// Unsigned integers
#define UNS8   unsigned char
#define UNS16  unsigned short
#define UNS32  unsigned long
#define UNS24  unsigned long
#define UNS40  unsigned long long
#define UNS48  unsigned long long
#define UNS56  unsigned long long
#define UNS64  unsigned long long

// Reals
#define REAL32 float
#define REAL64 double

// Reals
#define REAL32	float
#define REAL64 double

#include "can.h"


/// Definition of MSG_ERR
// ---------------------
#ifdef DEBUG_ERR_CONSOLE_ON
#    define MSG_ERR(num, str, val)            \
          initSCI_0();                        \
          printSCI_nbr(SCI0, num, ' ');       \
          /* large printing on console  */    \
          printSCI_str(SCI0, str);            \
          printSCI_nbr(SCI0, val, '\n');
#else
#    define MSG_ERR(num, str, val)
#endif

/// Definition of MSG_WAR
// ---------------------
#ifdef DEBUG_WAR_CONSOLE_ON
#    define MSG_WAR(num, str, val)          \
        initSCI_0();                        \
        printSCI_nbr(SCI0, num, ' ');       \
        /* large printing on console  */    \
        printSCI_str(SCI0, str);            \
        printSCI_nbr(SCI0, val, '\n');
#else
#    define MSG_WAR(num, str, val)
#endif

typedef void* CAN_HANDLE;

typedef void* CAN_PORT;

#endif


