# Inc.mk

CC = gcc
CXX = g++
RANLIB = ranlib
AR = ar
AROPT = -scurv

CFLAGS = -Werror -g -Os -pipe -D_REENTRANT
#CFLAGS = -Wall -g -Os -pipe -D_REENTRANT

INCLUDE = -I/Users/gerryyang/github_project/TLPI/tlpi
LIBPATH = -L/Users/gerryyang/github_project/TLPI/lib

DEP_LIBS = -ltlpi
LIBS = $(DEP_LIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

