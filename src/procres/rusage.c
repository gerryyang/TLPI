/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* rusage.c

   Execute a command and then print a summary of the resources (as retrieved
   by getrusage()) that it used.

   See also print_rudage.c.
   */
#include <sys/resource.h>
#include <sys/wait.h>
#include "print_rusage.h"
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	pid_t childPid;
	struct rusage ru;

	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s command arg...\n", argv[0]);

	switch (childPid = fork()) {
	case -1:
		errExit("fork");

	case 0:
		execvp(argv[1], &argv[1]);
		errExit("execvp");

	default:
		printf("Command PID: %ld\n", (long) childPid);
		if (wait(NULL) == -1)
			errExit("wait");
		if (getrusage(RUSAGE_CHILDREN, &ru) == -1)
			errExit("getrusage");

		printf("\n");
		printRusage("\t", &ru);
		exit(EXIT_SUCCESS);
	}
}
/*
output:
gerryyang@mba:procres$./rusage
Usage: ./rusage command arg...
gerryyang@mba:procres$./rusage date
Command PID: 3763
六 11 29 18:48:53 HKT 2014

	CPU time (secs):         user=0.001; system=0.001
	Max resident set size:   712704
	Integral shared memory:  0
	Integral unshared data:  0
	Integral unshared stack: 0
	Page reclaims:           280
	Page faults:             0
	Swaps:                   0
	Block I/Os:              input=0; output=0
	Signals received:        0
	IPC messages:            sent=0; received=0
	Context switches:        voluntary=0; involuntary=8
 */

