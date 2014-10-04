/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* make_zombie.c

   Demonstrate how a child process becomes a zombie in the interval between
   the time it exits, and the time its parent performs a wait (or exits, at
   which time it is adopted by init(8), which does a wait, thus releasing
   the zombie).
   */
#include <signal.h>
#include <libgen.h>             /* For basename() declaration */
#include "tlpi_hdr.h"

#define CMD_SIZE 200

int
main(int argc, char *argv[])
{
	char cmd[CMD_SIZE];
	pid_t childPid;

	setbuf(stdout, NULL);       /* Disable buffering of stdout */

	printf("Parent PID=%ld\n", (long) getpid());

	switch (childPid = fork()) {
	case -1:
		errExit("fork");

	case 0:     /* Child: immediately exits to become zombie */
		printf("Child (PID=%ld) exiting\n", (long) getpid());
		_exit(EXIT_SUCCESS);

	default:    /* Parent */
		sleep(3);               /* Give child a chance to start and exit */
		printf("basename[%s]=%s\n", argv[0], basename(argv[0]));
		snprintf(cmd, CMD_SIZE, "ps aux | grep %s", basename(argv[0]));
		system(cmd);            /* View zombie child */

		/* Now send the "sure kill" signal to the zombie */

		if (kill(childPid, SIGKILL) == -1)
			errMsg("kill");
		sleep(3);               /* Give child a chance to react to signal */
		printf("After sending SIGKILL to zombie (PID=%ld):\n", (long) childPid);
		system(cmd);            /* View zombie child again */

		exit(EXIT_SUCCESS);
	}
}
/*
output:
gerryyang@mba:procexec$./make_zombie 
Parent PID=1503
Child (PID=1504) exiting
basename[./make_zombie]=make_zombie
gerryyang        1507   0.0  0.0  2432784    620 s000  S+    6:07下午   0:00.00 grep make_zombie
gerryyang        1504   0.0  0.0        0      0 s000  Z+    6:07下午   0:00.00 (make_zombie)
gerryyang        1505   0.0  0.0  2433364    900 s000  S+    6:07下午   0:00.00 sh -c ps aux | grep make_zombie
gerryyang        1503   0.0  0.0  2432764    500 s000  S+    6:07下午   0:00.00 ./make_zombie
After sending SIGKILL to zombie (PID=1504):
gerryyang        1510   0.0  0.0  2432784    620 s000  S+    6:07下午   0:00.00 grep make_zombie
gerryyang        1504   0.0  0.0        0      0 s000  Z+    6:07下午   0:00.00 (make_zombie)
gerryyang        1508   0.0  0.0  2433364    908 s000  S+    6:07下午   0:00.00 sh -c ps aux | grep make_zombie
gerryyang        1503   0.0  0.0  2432764    500 s000  S+    6:07下午   0:00.00 ./make_zombie
gerryyang@mba:procexec$ps aux | grep make_zombie
gerryyang        1512   0.0  0.0  2432784    616 s000  S+    6:08下午   0:00.00 grep --color make_zombie
gerryyang@mba:procexec$
 */
