include ../../Inc.mk

PRINT_NPROC_OBJS = print_rlimit.o rlimit_nproc.o
PRINT_NPROC = rlimit_nproc

RUSAGE_WAIT_OBJS = rusage_wait.o
RUSAGE_WAIT = rusage_wait

RUSAGE_OBJS = print_rusage.o rusage.o
RUSAGE = rusage

BINS = $(PRINT_NPROC) $(RUSAGE_WAIT) $(RUSAGE)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(PRINT_NPROC): $(PRINT_NPROC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PRINT_NPROC) OK!"

$(RUSAGE_WAIT): $(RUSAGE_WAIT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(RUSAGE_WAIT) OK!"

$(RUSAGE): $(RUSAGE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(RUSAGE) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(PRINT_NPROC_OBJS) $(RUSAGE_WAIT_OBJS) $(RUSAGE_OBJS) $(BINS)

