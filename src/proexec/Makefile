include ../../Inc.mk

T_FORK_OBJS = t_fork.o
T_FORK = t_fork 

FFS_OBJS = fork_file_sharing.o
FFS = fork_file_sharing

T_VFORK_OBJS = t_vfork.o
T_VFORK = t_vfork

FWOF_OBJS = fork_whos_on_first.o
FWOF = fork_whos_on_first

BINS = $(T_FORK) $(FFS) $(T_VFORK) $(FWOF)

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

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_FORK_OBJS) $(FFS_OBJS) $(T_VFORK_OBJS) $(FWOF_OBJS) $(BINS)

