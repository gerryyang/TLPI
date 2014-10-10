/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* thread_incr_mutex.c

   This program employs two POSIX threads that increment the same global
   variable, synchronizing their access using a mutex. As a consequence,
   updates are not lost. Compare with thread_incr.c.
   */
#include <pthread.h>
#include "tlpi_hdr.h"

static volatile int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *                   /* Loop 'arg' times incrementing 'glob' */
threadFunc(void *arg)
{
	int loops = *((int *) arg);
	int loc, j, s;

	for (j = 0; j < loops; j++) {
		s = pthread_mutex_lock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_lock");

		loc = glob;
		loc++;
		glob = loc;

		s = pthread_mutex_unlock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_unlock");
	}

	return NULL;
}

int
main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int loops, s;

	loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 10000000;

	s = pthread_create(&t1, NULL, threadFunc, &loops);
	if (s != 0)
		errExitEN(s, "pthread_create");
	s = pthread_create(&t2, NULL, threadFunc, &loops);
	if (s != 0)
		errExitEN(s, "pthread_create");

	s = pthread_join(t1, NULL);
	if (s != 0)
		errExitEN(s, "pthread_join");
	s = pthread_join(t2, NULL);
	if (s != 0)
		errExitEN(s, "pthread_join");

	printf("glob = %d\n", glob);
	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:threads$time ./thread_incr_mutex 100000
glob = 200000

real	0m0.457s
user	0m0.065s
sys	0m0.397s
gerryyang@mba:threads$time ./thread_incr_mutex 1000000
glob = 2000000

real	0m4.497s
user	0m0.631s
sys	0m3.901s
gerryyang@mba:threads$time ./thread_incr_mutex 10000000
glob = 20000000

real	0m43.918s
user	0m6.247s
sys	0m37.934s
 */

