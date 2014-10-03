/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* multi_wait.c

   Demonstrate the use of wait(2): create multiple children and then wait
   for them all.

Usage: multi_wait sleep-time...

One child process is created for each command-line argument. Each child
sleeps for the number of seconds specified in the corresponding command-line
argument before exiting. After all children have been created, the parent
loops, waiting for terminated children, and displaying their PIDs.
*/
#include <sys/wait.h>
#include <time.h>
#include "curr_time.h"              /* Declaration of currTime() */
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int numDead;       /* Number of children so far waited for */
	pid_t childPid;    /* PID of waited for child */
	int j;

	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s sleep-time...\n", argv[0]);

	setbuf(stdout, NULL);           /* Disable buffering of stdout */

	for (j = 1; j < argc; j++) {    /* Create one child for each argument */
		switch (fork()) {
		case -1:
			errExit("fork");

		case 0:                     /* Child sleeps for a while then exits */
			printf("[%s] child %d started with PID %ld, sleeping %s "
					"seconds\n", currTime("%T"), j, (long) getpid(),
					argv[j]);
			sleep(getInt(argv[j], GN_NONNEG, "sleep-time"));
			_exit(EXIT_SUCCESS);

		default:                    /* Parent just continues around loop */
			break;
		}
	}

	numDead = 0;
	for (;;) {                      /* Parent waits for each child to exit */
		childPid = wait(NULL);
		if (childPid == -1) {
			if (errno == ECHILD) {
				printf("No more children - bye!\n");
				exit(EXIT_SUCCESS);
			} else {                /* Some other (unexpected) error */
				errExit("wait");
			}
		}

		numDead++;
		printf("[%s] wait() returned child PID %ld (numDead=%d)\n",
				currTime("%T"), (long) childPid, numDead);
	}
}
/*
output:
gerryyang@mba:proexec$./multi_wait 2 4 6 8
[19:44:05] child 3 started with PID 48685, sleeping 6 seconds
[19:44:05] child 1 started with PID 48683, sleeping 2 seconds
[19:44:05] child 2 started with PID 48684, sleeping 4 seconds
[19:44:05] child 4 started with PID 48686, sleeping 8 seconds
[19:44:07] wait() returned child PID 48683 (numDead=1)
[19:44:09] wait() returned child PID 48684 (numDead=2)
[19:44:11] wait() returned child PID 48685 (numDead=3)
[19:44:13] wait() returned child PID 48686 (numDead=4)
No more children - bye!
 */

