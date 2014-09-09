include ../../Inc.mk

REAL_TIMER_OBJS = real_timer.o
REAL_TIMER = real_timer 

TIMED_READ_OBJS = timed_read.o
TIMED_READ = timed_read 

TN_OBJS = t_nanosleep.o
TN = t_nanosleep 

BINS = $(REAL_TIMER) $(TIMED_READ) $(TN)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(REAL_TIMER): $(REAL_TIMER_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(REAL_TIMER) OK!"

$(TIMED_READ): $(TIMED_READ_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(TIMED_READ) OK!"

$(TN): $(TN_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(TN) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(REAL_TIMER_OBJS) $(TIMED_READ_OBJS) $(TN_OBJS) $(BINS)

