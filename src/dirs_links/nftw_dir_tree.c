/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* nftw_dir_tree.c

   Demonstrate the use of nftw(3). Walk though the directory tree specified
   on the command line (or the current working directory if no directory
   is specified on the command line), displaying an indented hierarchy
   of files in the tree. For each file, display:

 * a letter indicating the file type (using the same letters
 as "ls -l"), as obtained using stat(2);
 * a string indicating the file type, as supplied by nftw(); and
 * the file's i-node number.
 */
#if defined(__sun)
#define _XOPEN_SOURCE 500       /* Solaris 8 needs it this way */
#else
#if ! defined(_XOPEN_SOURCE) || _XOPEN_SOURCE < 600
#define _XOPEN_SOURCE 600       /* Get nftw() and S_IFSOCK declarations */
#endif
#endif
#include <ftw.h>
#include "tlpi_hdr.h"

static void
usageError(const char *progName, const char *msg)
{
	if (msg != NULL)
		fprintf(stderr, "%s\n", msg);
	fprintf(stderr, "Usage: %s [-d] [-m] [-p] [directory-path]\n", progName);
	fprintf(stderr, "\t-d Use FTW_DEPTH flag\n");
	fprintf(stderr, "\t-m Use FTW_MOUNT flag\n");
	fprintf(stderr, "\t-p Use FTW_PHYS flag\n");
	exit(EXIT_FAILURE);
}

static int                      /* Function called by nftw() */
dirTree(const char *pathname, const struct stat *sbuf, int type,
		struct FTW *ftwb)
{
	switch (sbuf->st_mode & S_IFMT) {       /* Print file type */
	case S_IFREG:  printf("-"); break;
	case S_IFDIR:  printf("d"); break;
	case S_IFCHR:  printf("c"); break;
	case S_IFBLK:  printf("b"); break;
	case S_IFLNK:  printf("l"); break;
	case S_IFIFO:  printf("p"); break;
	case S_IFSOCK: printf("s"); break;
	default:       printf("?"); break;      /* Should never happen (on Linux) */
	}

	printf(" %s  ",
			(type == FTW_D)  ? "D  " : (type == FTW_DNR) ? "DNR" :
			(type == FTW_DP) ? "DP " : (type == FTW_F)   ? "F  " :
			(type == FTW_SL) ? "SL " : (type == FTW_SLN) ? "SLN" :
			(type == FTW_NS) ? "NS " : "  ");

	if (type != FTW_NS)
		printf("%7ld ", (long) sbuf->st_ino);
	else
		printf("        ");

	printf(" %*s", 4 * ftwb->level, "");        /* Indent suitably */
	printf("%s\n",  &pathname[ftwb->base]);     /* Print basename */
	return 0;                                   /* Tell nftw() to continue */
}

int
main(int argc, char *argv[])
{
	int flags, opt;

	flags = 0;
	while ((opt = getopt(argc, argv, "dmp")) != -1) {
		switch (opt) {
		case 'd': flags |= FTW_DEPTH;   break;
		case 'm': flags |= FTW_MOUNT;   break;
		case 'p': flags |= FTW_PHYS;    break;
		default:  usageError(argv[0], NULL);
		}
	}

	if (argc > optind + 1)
		usageError(argv[0], NULL);

	if (nftw((argc > optind) ? argv[optind] : ".", dirTree, 10, flags) == -1) {
		perror("nftw");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
/*
output:
gerryyang@mba:dirs_links$./nftw_dir_tree -p
d D    6540519  .
- F    6547755      .Makefile.swp
- F    6547493      .nftw_dir_tree.c.swp
d D    6547786      dir_tmp
d D    6547795          dir_tmp2
- F    6547796              test2
- F    6547794          test
- F    6547782      list_files
- F    6547252      list_files.c
- F    6547781      list_files.o
- F    6547776      Makefile
- F    6547784      nftw_dir_tree
- F    6547513      nftw_dir_tree.c
- F    6547783      nftw_dir_tree.o
l SL   6547785      nftw_dir_tree_sflk
- F    6547778      t_unlink
- F    6540904      t_unlink.c
- F    6547777      t_unlink.o
- F    6547780      view_symlink
- F    6546626      view_symlink.c
- F    6547779      view_symlink.o
gerryyang@mba:dirs_links$ls
Makefile     list_files.c    nftw_dir_tree.c      t_unlink*   view_symlink*
dir_tmp/     list_files.o    nftw_dir_tree.o      t_unlink.c  view_symlink.c
list_files*  nftw_dir_tree*  nftw_dir_tree_sflk@  t_unlink.o  view_symlink.o
 */

