include ../../Inc.mk

T_SETPRIORITY_OBJS = t_setpriority.o
T_SETPRIORITY = t_setpriority

SCHED_SET_OBJS = sched_set.o
SCHED_SET = sched_set

SCHED_VIEW_OBJS = sched_view.o
SCHED_VIEW = sched_view

BINS = $(T_SETPRIORITY) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_SETPRIORITY): $(T_SETPRIORITY_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SETPRIORITY) OK!"

$(SCHED_SET): $(SCHED_SET_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SCHED_SET) OK!"

$(SCHED_VIEW): $(SCHED_VIEW_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SCHED_VIEW) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_SETPRIORITY_OBJS) $(SCHED_SET_OBJS) $(SCHED_VIEW_OBJS) $(BINS)

