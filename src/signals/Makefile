include ../../Inc.mk

OUCH_OBJS = ouch.o
OUCH = ouch 

INTQUIT_OBJS = intquit.o
INTQUIT = intquit 

T_KILL_OBJS = t_kill.o
T_KILL = t_kill 

IPS_OBJS = ignore_pending_sig.o
IPS = ignore_pending_sig 

SF = signal_functions.o

BINS = $(OUCH) $(INTQUIT) $(T_KILL) $(IPS)

#CFLAGS += -Wno-deprecated-declarations
INCLUDE += -I./

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

$(IPS): $(IPS_OBJS) $(SF)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(IPS) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(OUCH_OBJS) $(INTQUIT_OBJS) $(T_KILL_OBJS) $(IPS_OBJS) $(SF) $(BINS)

