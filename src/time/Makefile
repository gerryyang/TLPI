include ../../Inc.mk

CALENDAR_TIME_OBJS = calendar_time.o
CALENDAR_TIMR = calendar_time

BINS = $(CALENDAR_TIMR) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(CALENDAR_TIMR): $(CALENDAR_TIME_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CALENDAR_TIMR) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(CALENDAR_TIME_OBJS) $(BINS)

