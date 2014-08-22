include ../../Inc.mk

OUCH_OBJS = ouch.o
OUCH = ouch 

INTQUIT_OBJS = intquit.o
INTQUIT = intquit 

BINS = $(OUCH) $(INTQUIT)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(OUCH): $(OUCH_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(OUCH) OK!"

$(INTQUIT): $(INTQUIT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(INTQUIT) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(OUCH_OBJS) $(INTQUIT_OBJS) $(BINS)

