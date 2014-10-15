/*************************************************************************\
 *                  Copyright (C) Michael Kerrisk, 2014.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU Affero General Public License as published   *
 * by the Free Software Foundation, either version 3 or (at your option)   *
 * any later version. This program is distributed without any warranty.    *
 * See the file COPYING.agpl-v3 for details.                               *
 \*************************************************************************/

/* strerror.c

   An implementation of strerror() that is not thread-safe.
   */
#define _GNU_SOURCE                 /* Get 'sys_nerr' and 'sys_errlist'
									   declarations from <stdio.h> */
#include <stdio.h>
#include <string.h>                 /* Get declaration of strerror() */

#define MAX_ERROR_LEN 256           /* Maximum length of string
									   returned by strerror() */

static char buf[MAX_ERROR_LEN];     /* Statically allocated return buffer */

char *
strerror(int err)
{
	if (err < 0 || err >= sys_nerr || sys_errlist[err] == NULL) {
		snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
	} else {
		strncpy(buf, sys_errlist[err], MAX_ERROR_LEN - 1);
		buf[MAX_ERROR_LEN - 1] = '\0';          /* Ensure null termination */
	}

	return buf;
}

/*
sys_errlist, sys_nerr
global variables for mapping errno to error messages 

#include <stdio.h>
extern char **sys_errlist;
extern int sys_nerr; 

http://www.mkssoftware.com/docs/man5/sys_errlist.5.asp
 */
