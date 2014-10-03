/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* fork_stdio_buf.c

   Experiment with fork() and stdio buffering.
   */
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	printf("Hello world\n");
	write(STDOUT_FILENO, "Ciao\n", 5);

	int iret = 0;
	if ((iret = fork()) == -1)
	{
		errExit("fork");
	}
	else if (iret == 0)
	{
		printf("child\n");

		// no flush stdio buffer
		_exit(EXIT_SUCCESS);
	}

	/* Both child and parent continue execution here */

	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:proexec$./fork_stdio_buf2 
Hello world
Ciao
child
gerryyang@mba:proexec$./fork_stdio_buf2 > tmp
gerryyang@mba:proexec$cat tmp 
Ciao
Hello world
 */
