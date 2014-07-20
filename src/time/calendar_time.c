/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* calendar_time.c

   Demonstrate the use of functions for working with calendar time.

   This program retrieves the current time and displays it in various forms.
   */
#include <locale.h>
#include <time.h>
#include <sys/time.h>
#include "tlpi_hdr.h"

#define SECONDS_IN_TROPICAL_YEAR (365.24219 * 24 * 60 * 60)

int
main(int argc, char *argv[])
{
	time_t t;
	struct tm *gmp, *locp;
	struct tm gm, loc;
	struct timeval tv;

	/* Retrieve time, convert and display it in various forms */

	t = time(NULL);
	printf("Seconds since the Epoch (1 Jan 1970): %ld", (long) t);
	printf(" (about %6.3f years)\n", t / SECONDS_IN_TROPICAL_YEAR);

	if (gettimeofday(&tv, NULL) == -1)
		errExit("gettimeofday");
	printf("  gettimeofday() returned %ld secs, %ld microsecs\n",
			(long) tv.tv_sec, (long) tv.tv_usec);

	gmp = gmtime(&t);
	if (gmp == NULL)
		errExit("gmtime");

	gm = *gmp;          /* Save local copy, since *gmp may be modified
						   by asctime() or gmtime() */
	printf("Broken down by gmtime():\n");
	printf("  year=%d mon=%d mday=%d hour=%d min=%d sec=%d ", gm.tm_year,
			gm.tm_mon, gm.tm_mday, gm.tm_hour, gm.tm_min, gm.tm_sec);
	printf("wday=%d yday=%d isdst=%d\n", gm.tm_wday, gm.tm_yday, gm.tm_isdst);

	/* The TZ environment variable will affect localtime().
	   Try, for example:

	   TZ=Pacific/Auckland calendar_time
	   */

	locp = localtime(&t);
	if (locp == NULL)
		errExit("localtime");

	loc = *locp;        /* Save local copy */

	printf("Broken down by localtime():\n");
	printf("  year=%d mon=%d mday=%d hour=%d min=%d sec=%d ",
			loc.tm_year, loc.tm_mon, loc.tm_mday,
			loc.tm_hour, loc.tm_min, loc.tm_sec);
	printf("wday=%d yday=%d isdst=%d\n\n",
			loc.tm_wday, loc.tm_yday, loc.tm_isdst);

	printf("asctime() formats the gmtime() value as: %s", asctime(&gm));
	printf("ctime() formats the time() value as:     %s", ctime(&t));

	printf("mktime() of gmtime() value:    %ld secs\n", (long) mktime(&gm));
	printf("mktime() of localtime() value: %ld secs\n", (long) mktime(&loc));

	exit(EXIT_SUCCESS);
}
/*
output:

gerryyang@mba:time$./calendar_time
Seconds since the Epoch (1 Jan 1970): 1405830842 (about 44.549 years)
  gettimeofday() returned 1405830842 secs, 544590 microsecs
Broken down by gmtime():
  year=114 mon=6 mday=20 hour=4 min=34 sec=2 wday=0 yday=200 isdst=0
Broken down by localtime():
  year=114 mon=6 mday=20 hour=12 min=34 sec=2 wday=0 yday=200 isdst=0

asctime() formats the gmtime() value as: Sun Jul 20 04:34:02 2014
ctime() formats the time() value as:     Sun Jul 20 12:34:02 2014
mktime() of gmtime() value:    1405802042 secs
mktime() of localtime() value: 1405830842 secs

gerryyang@mba:time$TZ=Pacific/Auckland ./calendar_time
Seconds since the Epoch (1 Jan 1970): 1405831025 (about 44.549 years)
  gettimeofday() returned 1405831025 secs, 440967 microsecs
Broken down by gmtime():
  year=114 mon=6 mday=20 hour=4 min=37 sec=5 wday=0 yday=200 isdst=0
Broken down by localtime():
  year=114 mon=6 mday=20 hour=16 min=37 sec=5 wday=0 yday=200 isdst=0

asctime() formats the gmtime() value as: Sun Jul 20 04:37:05 2014
ctime() formats the time() value as:     Sun Jul 20 16:37:05 2014
mktime() of gmtime() value:    1405787825 secs
mktime() of localtime() value: 1405831025 secs
 * */
