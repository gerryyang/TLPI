include ../../Inc.mk

SIMPLE_THREAD_OBJS = simple_thread.o
SIMPLE_THREAD = simple_thread 

DETACHED_ATTRIB_OBJS = detached_attrib.o
DETACHED_ATTRIB = detached_attrib

MAIN_THREAD_EXIT_OBJS = main_thread_exit.o
MAIN_THREAD_EXIT = main_thread_exit

THREAD_INCR_OBJS = thread_incr.o
THREAD_INCR = thread_incr

THREAD_INCR_MUTEX_OBJS = thread_incr_mutex.o
THREAD_INCR_MUTEX = thread_incr_mutex

THREAD_MULTIJOIN_OBJS = thread_multijoin.o
THREAD_MULTIJOIN = thread_multijoin

BINS = $(SIMPLE_THREAD) $(DETACHED_ATTRIB) $(MAIN_THREAD_EXIT) $(THREAD_INCR) $(THREAD_INCR_MUTEX) $(THREAD_MULTIJOIN)

CFLAGS += -Wno-int-to-void-pointer-cast

all: $(BINS)

$(SIMPLE_THREAD): $(SIMPLE_THREAD_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_THREAD) OK!"

$(DETACHED_ATTRIB): $(DETACHED_ATTRIB_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(DETACHED_ATTRIB) OK!"

$(MAIN_THREAD_EXIT): $(MAIN_THREAD_EXIT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MAIN_THREAD_EXIT) OK!"

$(THREAD_INCR): $(THREAD_INCR_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(THREAD_INCR) OK!"

$(THREAD_INCR_MUTEX): $(THREAD_INCR_MUTEX_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(THREAD_INCR_MUTEX) OK!"

$(THREAD_MULTIJOIN): $(THREAD_MULTIJOIN_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(THREAD_MULTIJOIN) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_THREAD_OBJS) $(DETACHED_ATTRIB_OBJS) $(MAIN_THREAD_EXIT_OBJS) $(THREAD_INCR_OBJS) $(THREAD_INCR_MUTEX_OBJS) $(THREAD_MULTIJOIN_OBJS) $(BINS)

