/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* t_sysconf.c

   Demonstrate the use of sysconf() to retrieve system limits.
   */
#include "tlpi_hdr.h"

static void             /* Print 'msg' plus sysconf() value for 'name' */
sysconfPrint(const char *msg, int name)
{
	long lim;

	errno = 0;
	lim = sysconf(name);
	if (lim != -1) {        /* Call succeeded, limit determinate */
		printf("%s %ld\n", msg, lim);
	} else {
		if (errno == 0)     /* Call succeeded, limit indeterminate */
			printf("%s (indeterminate)\n", msg);
		else                /* Call failed */
			errExit("sysconf %s", msg);
	}
}

int
main(int argc, char *argv[])
{
	sysconfPrint("_SC_ARG_MAX:        ", _SC_ARG_MAX);
	sysconfPrint("_SC_LOGIN_NAME_MAX: ", _SC_LOGIN_NAME_MAX);
	sysconfPrint("_SC_OPEN_MAX:       ", _SC_OPEN_MAX);
	sysconfPrint("_SC_NGROUPS_MAX:    ", _SC_NGROUPS_MAX);
	sysconfPrint("_SC_PAGESIZE:       ", _SC_PAGESIZE);
	sysconfPrint("_SC_RTSIG_MAX:      ", _SC_RTSIG_MAX);
	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:syslim$./t_sysconf 
_SC_ARG_MAX:         262144
_SC_LOGIN_NAME_MAX:  255
_SC_OPEN_MAX:        256
_SC_NGROUPS_MAX:     16
_SC_PAGESIZE:        4096
_SC_RTSIG_MAX:       (indeterminate)
 * */

