/*
 * main thread to pthread_exit(NULL);
 */
#include <pthread.h>
#include "tlpi_hdr.h"

static void *
threadFunc(void *arg)
{
	int sec = 1;

	for (;;)
	{
		printf("child thread[%ld] sleep %d seconds\n", (long)pthread_self(), sec);
		sleep(sec);
	}

	return (void *) 0;
}

int
main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;

	for (int i = 0; i != 6; ++i)
	{
		s = pthread_create(&t1, NULL, threadFunc, NULL);
		if (s != 0)
			errExitEN(s, "pthread_create");
	}

	sleep(9);
	printf("main thread[%ld] pthread_exit, no wait for child thread[%ld]\n", 
			(long)pthread_self(), (long)t1);

	pthread_exit(NULL);
	// compare
	//exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:threads$./main_thread_exit 
child thread[4346953728] sleep 1 seconds
child thread[4346953728] sleep 1 seconds
child thread[4346953728] sleep 1 seconds
main thread[140735258592016] pthread_exit, no wait for child thread[4346953728]
child thread[4346953728] sleep 1 seconds
child thread[4346953728] sleep 1 seconds
child thread[4346953728] sleep 1 seconds
^C
 */

