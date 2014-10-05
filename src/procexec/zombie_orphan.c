/* zombie_orphan.c
   26-2
   */
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	setbuf(stdout, NULL);       /* Disable buffering of stdout */

	switch (fork()) {
	case -1:
		errExit("fork");

	case 0:             /* child */
		switch (fork()) {
		case -1:
			errExit("fork");
		case 0:
			while (1) {  
				printf("grand child running (parent PID=%ld grand child PID=%ld)\n", 
						(long) getppid(), (long) getpid());
				sleep(1);
			}
		default: /* parent */
			printf("parent (PID=%ld) sleeping\n", (long) getpid());
			sleep(10);                           /* Give child a chance to start */
			printf("parent exiting\n");
			_exit(EXIT_SUCCESS);
		}

	default:            /* grand father */
		printf("grand father (PID=%ld) no wait, and use ctrl-c to stop\n", (long) getpid());
		while (1);
	}
}
/*
output:
gerryyang@mba:procexec$./zombie_orphan 
grand father (PID=3058) no wait, and use ctrl-c to stop
parent (PID=3059) sleeping
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
grand child running (parent PID=3059 grand child PID=3060)
parent exiting
grand child running (parent PID=1 grand child PID=3060)
grand child running (parent PID=1 grand child PID=3060)
grand child running (parent PID=1 grand child PID=3060)
^C
gerryyang@mba:procexec$
 */

