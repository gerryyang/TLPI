include ../../Inc.mk

REAL_TIMER_OBJS = real_timer.o
REAL_TIMER = real_timer 

BINS = $(REAL_TIMER) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(REAL_TIMER): $(REAL_TIMER_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(REAL_TIMER) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(REAL_TIMER_OBJS) $(BINS)

