include ../../Inc.mk

PRINT_NPROC_OBJS = print_rlimit.o rlimit_nproc.o
PRINT_NPROC = rlimit_nproc

BINS = $(PRINT_NPROC) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(PRINT_NPROC): $(PRINT_NPROC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PRINT_NPROC) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(PRINT_NPROC_OBJS) $(BINS)

