# Inc.mk

CC = gcc
CXX = g++
RANLIB = ranlib
AR = ar
AROPT = -scurv

CFLAGS = -Werror -g -Os -pipe -D_REENTRANT

INCLUDE = -I../tlpi
LIBPATH = -L../lib

DEP_LIBS = -ltlpi
LIBS = $(DEP_LIBS)


# calc relation between files automatically
%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

