include ../../Inc.mk

T_FORK_OBJS = t_fork.o
T_FORK = t_fork 

FFS_OBJS = fork_file_sharing.o
FFS = fork_file_sharing

T_VFORK_OBJS = t_vfork.o
T_VFORK = t_vfork

FWOF_OBJS = fork_whos_on_first.o
FWOF = fork_whos_on_first

FSS_OBJS = fork_sig_sync.o
FSS = fork_sig_sync

EXIT_HANDLERS_OBJS = exit_handlers.o
EXIT_HANDLERS = exit_handlers

FORK_STDIO_BUF_OBJS = fork_stdio_buf.o
FORK_STDIO_BUF = fork_stdio_buf

MULTI_WAIT_OBJS = multi_wait.o
MULTI_WAIT = multi_wait


BINS = $(T_FORK) $(FFS) $(T_VFORK) $(FWOF) $(FSS) $(EXIT_HANDLERS) $(FORK_STDIO_BUF) $(FORK_STDIO_BUF2) $(MULTI_WAIT)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_FORK): $(T_FORK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_FORK) OK!"

$(FFS): $(FFS_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FFS) OK!"

$(T_VFORK): $(T_VFORK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_VFORK) OK!"

$(FWOF): $(FWOF_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FWOF) OK!"

$(FSS): $(FSS_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FSS) OK!"

$(EXIT_HANDLERS): $(EXIT_HANDLERS_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(EXIT_HANDLERS) OK!"

$(FORK_STDIO_BUF): $(FORK_STDIO_BUF_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FORK_STDIO_BUF) OK!"

$(FORK_STDIO_BUF2): $(FORK_STDIO_BUF2_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FORK_STDIO_BUF2) OK!"

$(MULTI_WAIT): $(MULTI_WAIT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MULTI_WAIT) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_FORK_OBJS) $(FFS_OBJS) $(T_VFORK_OBJS) $(FWOF_OBJS) $(FSS_OBJS) $(EXIT_HANDLERS_OBJS) $(FORK_STDIO_BUF_OBJS) $(FORK_STDIO_BUF2_OBJS) $(MULTI_WAIT_OBJS) $(BINS)

