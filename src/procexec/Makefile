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

CHILD_STATUS_OBJS = child_status.o
CHILD_STATUS = child_status

MAKE_ZOMBIE_OBJS = make_zombie.o
MAKE_ZOMBIE = make_zombie

MULTI_SIGCHID_OBJS = multi_SIGCHLD.o
MULTI_SIGCHID = multi_SIGCHLD

ORPHAN_OBJS = orphan.o
ORPHAN = orphan

ZOMBIE_ORPHAN_OBJS = zombie_orphan.o
ZOMBIE_ORPHAN = zombie_orphan

T_EXECVE_OBJS = t_execve.o
T_EXECVE = t_execve

ENVARGS_OBJS = envargs.o
ENVARGS = envargs

CLOSEONEXEC_OBJS = closeonexec.o
CLOSEONEXEC = closeonexec

T_CLONE_OBJS = t_clone.o
T_CLONE = t_clone

BINS = $(T_FORK) $(FFS) $(T_VFORK) $(FWOF) $(FSS) $(EXIT_HANDLERS) $(FORK_STDIO_BUF) $(FORK_STDIO_BUF2) $(MULTI_WAIT) $(CHILD_STATUS) $(MAKE_ZOMBIE) $(MULTI_SIGCHID) $(ORPHAN) $(ZOMBIE_ORPHAN) $(T_EXECVE) $(ENVARGS) $(CLOSEONEXEC) 

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

$(CHILD_STATUS): $(CHILD_STATUS_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CHILD_STATUS) OK!"

$(MAKE_ZOMBIE): $(MAKE_ZOMBIE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MAKE_ZOMBIE) OK!"

$(MULTI_SIGCHID): $(MULTI_SIGCHID_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MULTI_SIGCHID) OK!"

$(ORPHAN): $(ORPHAN_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(ORPHAN) OK!"

$(ZOMBIE_ORPHAN): $(ZOMBIE_ORPHAN_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(ZOMBIE_ORPHAN) OK!"

$(T_EXECVE): $(T_EXECVE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_EXECVE) OK!"

$(ENVARGS): $(ENVARGS_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(ENVARGS) OK!"

$(CLOSEONEXEC): $(CLOSEONEXEC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CLOSEONEXEC) OK!"

$(T_CLONE): $(T_CLONE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_CLONE) OK!"


install:
	@echo "nothing to install"

clean:
	-rm -f $(BINS) $(T_FORK_OBJS) $(FFS_OBJS) $(T_VFORK_OBJS) $(FWOF_OBJS) $(FSS_OBJS) $(EXIT_HANDLERS_OBJS) $(FORK_STDIO_BUF_OBJS) $(FORK_STDIO_BUF2_OBJS) $(MULTI_WAIT_OBJS) $(CHILD_STATUS_OBJS) $(MAKE_ZOMBIE_OBJS) $(MULTI_SIGCHID_OBJS) $(ORPHAN_OBJS) $(ZOMBIE_ORPHAN_OBJS) $(T_EXECVE_OBJS) $(ENVARGS_OBJS) $(CLOSEONEXEC_OBJS) $(T_CLONE_OBJS)

