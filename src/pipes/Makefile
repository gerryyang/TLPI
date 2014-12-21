include ../../Inc.mk

SIMPLE_PIPES_OBJS = simple_pipe.o
SIMPLE_PIPES = simple_pipe

PIPE_SYNC_OBJS = pipe_sync.o
PIPE_SYNC = pipe_sync

BINS = $(SIMPLE_PIPES) $(PIPE_SYNC)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SIMPLE_PIPES): $(SIMPLE_PIPES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_PIPES) OK!"

$(PIPE_SYNC): $(PIPE_SYNC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PIPE_SYNC) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_PIPES_OBJS) $(PIPE_SYNC_OBJS) $(BINS)

