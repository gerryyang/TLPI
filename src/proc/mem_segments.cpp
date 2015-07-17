/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* mem_segments.c

   A program that does nothing in particular, but the comments indicate
   which memory segments each type of variable is allocated in.
   */
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Foo
{
public:
	Foo() {
		memset(m_buf, 65, sizeof(m_buf));
		printf("Foo() m_buf[0]=%c, m_buf[%ld]=%c\n", 
				m_buf[0], sizeof(m_buf) - 1, m_buf[sizeof(m_buf) - 1]);
	}

	~Foo() {
		printf("~Foo()\n");
	}

private:
	char m_buf[1024 * 1024 * 10];// local
	static char m_s_buf[1024 * 1024 * 5];// static
};
char Foo::m_s_buf[1024 * 1024 * 5] = "a";

Foo foo_obj;// Uninitialized or initialized ?


char globBuf[65536];            /* Uninitialized data segment */
//char globBuf[65536] = "a";    /* initialized data segment */
int primes[] = { 2, 3, 5, 7 };  /* Initialized data segment */

static int
square(int x)                   /* Allocated in frame for square() */
{
	int result;                 /* Allocated in frame for square() */

	result = x * x;
	return result;              /* Return value passed via register */
}

static void
doCalc(int val)                 /* Allocated in frame for doCalc() */
{
	printf("The square of %d is %d\n", val, square(val));

	if (val < 1000) {
		int t;                  /* Allocated in frame for doCalc() */

		t = val * val * val;
		printf("The cube of %d is %d\n", val, t);
	}
}

int
main(int argc, char *argv[])    /* Allocated in frame for main() */
{
	static int key = 9973;      /* Initialized data segment */

	static char mbuf[10240000]; /* Uninitialized data segment */
	//static char mbuf_init[10240000] = "a"; /*initialized data segment */

	char *p;                    /* Allocated in frame for main() */

	p = (char *)malloc(1024);           /* Points to memory in heap segment */

	doCalc(key);

	exit(EXIT_SUCCESS);
}

