/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* fork_whos_on_first.c

   Parent repeatedly creates a child, and then processes both race to be the
   first to print a message. (Each child terminates after printing its message.)
   The results of running this program give us an idea of which of the two
   processes--parent or child--is usually scheduled first after a fork().

   Whether the child or the parent is scheduled first after fork() has
   changed a number of times across different kernel versions.
   */
#include <sys/wait.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int numChildren, j;
	pid_t childPid;

	if (argc > 1 && strcmp(argv[1], "--help") == 0)
		usageErr("%s [num-children]\n", argv[0]);

	numChildren = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-children") : 1;

	setbuf(stdout, NULL);               /* Make stdout unbuffered */

	for (j = 0; j < numChildren; j++) {
		switch (childPid = fork()) {
		case -1:
			errExit("fork");

		case 0:
			printf("%d child\n", j);
			_exit(EXIT_SUCCESS);

		default:
			printf("%d parent\n", j);
			wait(NULL);                 /* Wait for child to terminate */
			break;
		}
	}

	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:proexec$./fork_whos_on_first 20
0 parent
0 child
1 parent
1 child
2 parent
2 child
3 parent
3 child
4 parent
4 child
5 parent
5 child
6 parent
6 child
7 parent
7 child
8 parent
8 child
9 parent
9 child
10 parent
10 child
11 parent
11 child
12 parent
12 child
13 parent
13 child
14 parent
14 child
15 parent
15 child
16 parent
16 child
17 parent
17 child
18 parent
18 child
19 parent
19 child
 */

