include ../../Inc.mk

OUCH_OBJS = ouch.o
OUCH = ouch 

INTQUIT_OBJS = intquit.o
INTQUIT = intquit 

T_KILL_OBJS = t_kill.o
T_KILL = t_kill 

BINS = $(OUCH) $(INTQUIT) $(T_KILL)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(OUCH): $(OUCH_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(OUCH) OK!"

$(INTQUIT): $(INTQUIT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(INTQUIT) OK!"

$(T_KILL): $(T_KILL_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_KILL) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(OUCH_OBJS) $(INTQUIT_OBJS) $(T_KILL_OBJS) $(BINS)

