/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* free_and_sbrk.c

   Test if free(3) actually lowers the program break.

Usage: free_and_sbrk num-allocs block-size [step [min [max]]]

Try: free_and_sbrk 1000 10240 2 1 1000
free_and_sbrk 1000 10240 1 1 999
free_and_sbrk 1000 10240 1 500 1000

(Only the last of these should see the program break lowered.)
*/
#define _BSD_SOURCE
#include "tlpi_hdr.h"

#define MAX_ALLOCS 1000000

int
main(int argc, char *argv[])
{
	char *ptr[MAX_ALLOCS];
	int freeStep, freeMin, freeMax, blockSize, numAllocs, j;

	printf("\n");

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s num-allocs block-size [step [min [max]]]\n", argv[0]);

	numAllocs = getInt(argv[1], GN_GT_0, "num-allocs");
	if (numAllocs > MAX_ALLOCS)
		cmdLineErr("num-allocs > %d\n", MAX_ALLOCS);

	blockSize = getInt(argv[2], GN_GT_0 | GN_ANY_BASE, "block-size");

	freeStep = (argc > 3) ? getInt(argv[3], GN_GT_0, "step") : 1;
	freeMin =  (argc > 4) ? getInt(argv[4], GN_GT_0, "min") : 1;
	freeMax =  (argc > 5) ? getInt(argv[5], GN_GT_0, "max") : numAllocs;

	if (freeMax > numAllocs)
		cmdLineErr("free-max > num-allocs\n");

	printf("Initial program break:          %10p\n", sbrk(0));

	printf("Allocating %d*%d bytes\n", numAllocs, blockSize);
	for (j = 0; j < numAllocs; j++) {
		ptr[j] = malloc(blockSize);
		if (ptr[j] == NULL)
			errExit("malloc");
	}

	printf("Program break is now:           %10p\n", sbrk(0));

	printf("Freeing blocks from %d to %d in steps of %d\n",
			freeMin, freeMax, freeStep);
	for (j = freeMin - 1; j < freeMax; j += freeStep)
		free(ptr[j]);

	printf("After free(), program break is: %10p\n", sbrk(0));

	exit(EXIT_SUCCESS);
}
/*
output: OS X
gerryyang@mba:memalloc$./free_and_sbrk 

Usage: ./free_and_sbrk num-allocs block-size [step [min [max]]]
gerryyang@mba:memalloc$./free_and_sbrk 1000 10240 2

Initial program break:          0x10b7dd000
Allocating 1000*10240 bytes
Program break is now:           0x10b7dd000
Freeing blocks from 1 to 1000 in steps of 2
After free(), program break is: 0x10b7dd000
gerryyang@mba:memalloc$./free_and_sbrk 1000 10240 1 1 999

Initial program break:          0x1066f7000
Allocating 1000*10240 bytes
Program break is now:           0x1066f7000
Freeing blocks from 1 to 999 in steps of 1
After free(), program break is: 0x1066f7000
gerryyang@mba:memalloc$./free_and_sbrk 1000 10240 1 500 1000

Initial program break:          0x1029ca000
Allocating 1000*10240 bytes
Program break is now:           0x1029ca000
Freeing blocks from 500 to 1000 in steps of 1
After free(), program break is: 0x1029ca000
gerryyang@mba:memalloc$uname -a
Darwin mba.local 13.2.0 Darwin Kernel Version 13.2.0: Thu Apr 17 23:03:13 PDT 2014; root:xnu-2422.100.13~1/RELEASE_X86_64 x86_64 i386 MacBookAir5,2 Darwin
 * */
