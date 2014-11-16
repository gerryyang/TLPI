include ../../Inc.mk

SETSID_OBJS = t_setsid.o
SETSID = t_setsid

CATCH_SIGHUP_OBJS = catch_SIGHUP.o
CATCH_SIGHUP = catch_SIGHUP

DISCONNECT_SIGHUP_OBJS = disconnect_SIGHUP.o
DISCONNECT_SIGHUP = disconnect_SIGHUP

BINS = $(SETSID) $(CATCH_SIGHUP) $(DISCONNECT_SIGHUP)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SETSID): $(SETSID_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SETSID) OK!"

$(CATCH_SIGHUP): $(CATCH_SIGHUP_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CATCH_SIGHUP) OK!"

$(DISCONNECT_SIGHUP): $(DISCONNECT_SIGHUP_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(DISCONNECT_SIGHUP) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SETSID_OBJS) $(CATCH_SIGHUP_OBJS) $(DISCONNECT_SIGHUP_OBJS) $(BINS)

