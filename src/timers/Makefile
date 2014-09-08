include ../../Inc.mk

REAL_TIMER_OBJS = real_timer.o
REAL_TIMER = real_timer 

TIMED_READ_OBJS = timed_read.o
TIMED_READ = timed_read 

BINS = $(REAL_TIMER) $(TIMED_READ)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(REAL_TIMER): $(REAL_TIMER_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(REAL_TIMER) OK!"

$(TIMED_READ): $(TIMED_READ_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(TIMED_READ) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(REAL_TIMER_OBJS) $(TIMED_READ_OBJS) $(BINS)

