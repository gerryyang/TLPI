include ../../Inc.mk

CALENDAR_TIME_OBJS = calendar_time.o
CALENDAR_TIME = calendar_time

BINS = $(CALENDAR_TIME) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(CALENDAR_TIME): $(CALENDAR_TIME_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CALENDAR_TIME) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(CALENDAR_TIME_OBJS) $(BINS)

