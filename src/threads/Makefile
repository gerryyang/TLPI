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

PROD_CONDVAR_OBJS = prod_condvar.o
PROD_CONDVAR = prod_condvar

PROD_NO_CONDVAR_OBJS = prod_no_condvar.o
PROD_NO_CONDVAR = prod_no_condvar

STRERROR_TEST_OBJS = strerror_test.o strerror.o
STRERROR_TEST = strerror_test

BINS = $(SIMPLE_THREAD) $(DETACHED_ATTRIB) $(MAIN_THREAD_EXIT) $(THREAD_INCR) $(THREAD_INCR_MUTEX) $(THREAD_MULTIJOIN) $(PROD_CONDVAR) $(PROD_NO_CONDVAR) $(STRERROR_TEST)

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

$(PROD_CONDVAR): $(PROD_CONDVAR_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PROD_CONDVAR) OK!"

$(PROD_NO_CONDVAR): $(PROD_NO_CONDVAR_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PROD_NO_CONDVAR) OK!"

$(STRERROR_TEST): $(STRERROR_TEST_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(STRERROR_TEST) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_THREAD_OBJS) $(DETACHED_ATTRIB_OBJS) $(MAIN_THREAD_EXIT_OBJS) $(THREAD_INCR_OBJS) $(THREAD_INCR_MUTEX_OBJS) $(THREAD_MULTIJOIN_OBJS) $(PROD_CONDVAR_OBJS) $(PROD_NO_CONDVAR_OBJS) $(STRERROR_TEST_OBJS) $(BINS)

