include ../../Inc.mk

LONGJUMP_OBJS = longjump.o
LONGJUMP = longjump

BINS = setjmp_vars setjmp_vars_optimized $(LONGJUMP) 
#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

setjmp_vars: setjmp_vars.c
	gcc -g -Wall -o $@ $^

setjmp_vars_optimized: setjmp_vars.c
	gcc -O -g -Wall -o $@ $^

$(LONGJUMP): $(LONGJUMP_OBJS)
	$(CXX) -O -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(LONGJUMP) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SETJMP_VARS_OBJS) $(LONGJUMP_OBJS) \
		$(BINS)


