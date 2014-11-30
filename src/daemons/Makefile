include ../../Inc.mk

TEST_BECOME_DAEMON_OBJS = test_become_daemon.o become_daemon.o
TEST_BECOME_DAEMON = test_become_daemon

DAEMON_SIGHUP_OBJS = daemon_SIGHUP.o become_daemon.o
DAEMON_SIGHUP = daemon_SIGHUP

BINS = $(TEST_BECOME_DAEMON) $(DAEMON_SIGHUP)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(TEST_BECOME_DAEMON): $(TEST_BECOME_DAEMON_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(TEST_BECOME_DAEMON) OK!"

$(DAEMON_SIGHUP): $(DAEMON_SIGHUP_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(DAEMON_SIGHUP) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(TEST_BECOME_DAEMON_OBJS) $(DAEMON_SIGHUP_OBJS) $(BINS)

