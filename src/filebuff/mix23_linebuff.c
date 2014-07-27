/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* mix23_linebuff.c

   Illustrates the impact of stdio buffering when using stdio library
   functions and I/O system calls to work on the same file. Observe the
   difference in output when running this program with output directed
   to a terminal and again with output directed to a file.
   */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	printf("If I had more time, \n");
	//printf("If I had more time, ");// if change to this, what will happen?
	
	write(STDOUT_FILENO, "I would have written you a shorter letter.\n", 43);
	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:filebuff$gcc -o mix mix23_linebuff.c 
gerryyang@mba:filebuff$./mix 
If I had more time, 
I would have written you a shorter letter.
gerryyang@mba:filebuff$./mix > out
gerryyang@mba:filebuff$cat out 
I would have written you a shorter letter.
If I had more time, 
 */
