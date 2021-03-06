/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* write_bytes.c

   Write bytes to a file. (A simple program for file I/O benchmarking.)

Usage: write_bytes file num-bytes buf-size

Writes 'num-bytes' bytes to 'file', using a buffer size of 'buf-size'
for each write().

If compiled with -DUSE_O_SYNC, open the file with the O_SYNC flag,
so that all data and metadata changes are flushed to the disk.

If compiled with -DUSE_FDATASYNC, perform an fdatasync() after each write,
so that data--and possibly metadata--changes are flushed to the disk.

If compiled with -DUSE_FSYNC, perform an fsync() after each write, so that
data and metadata are flushed to the disk.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	size_t bufSize, numBytes, thisWrite, totWritten;
	char *buf;
	int fd, openFlags;

	if (argc != 4 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file num-bytes buf-size\n", argv[0]);

	numBytes = getLong(argv[2], GN_GT_0, "num-bytes");
	bufSize = getLong(argv[3], GN_GT_0, "buf-size");

	buf = malloc(bufSize);
	if (buf == NULL)
		errExit("malloc");

	openFlags = O_CREAT | O_WRONLY;

#if defined(USE_O_SYNC) && defined(O_SYNC)
	openFlags |= O_SYNC;
#endif

	fd = open(argv[1], openFlags, S_IRUSR | S_IWUSR);
	if (fd == -1)
		errExit("open");

	for (totWritten = 0; totWritten < numBytes;
			totWritten += thisWrite) {
		thisWrite = min(bufSize, numBytes - totWritten);

		if (write(fd, buf, thisWrite) != thisWrite)
			fatal("partial/failed write");

#ifdef USE_FSYNC
		if (fsync(fd))
			errExit("fsync");
#endif
#ifdef USE_FDATASYNC
		if (fdatasync(fd))
			errExit("fdatasync");
#endif
	}

	if (close(fd) == -1)
		errExit("close");
	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:filebuff$time ./write_bytes file 1000000 1

real	0m0.888s
user	0m0.095s
sys	0m0.692s
gerryyang@mba:filebuff$time ./write_bytes file 1000000 100

real	0m0.014s
user	0m0.002s
sys	0m0.010s
gerryyang@mba:filebuff$time ./write_bytes file 1000000 1000

real	0m0.007s
user	0m0.001s
sys	0m0.004s
gerryyang@mba:filebuff$time ./write_bytes file 1000000 10000

real	0m0.006s
user	0m0.001s
sys	0m0.003s
 */
