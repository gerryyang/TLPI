include ../Inc.mk

LIB_TLPI = ../lib/libtlpi.a
OBJS_TLPI = error_functions.o get_num.o alt_functions.o curr_time.o print_wait_status.o

LIBS = $(LIB_TLPI)
OBJS = $(OBJS_TLPI)

all: $(LIBS)

$(LIB_TLPI): $(OBJS)
	$(AR) $(AROPT) $@ $?
	$(RANLIB) $@

install:
	@echo "nothing to install"

clean:
	rm -f $(OBJS)


