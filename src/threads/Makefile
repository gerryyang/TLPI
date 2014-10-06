include ../../Inc.mk

SIMPLE_THREAD_OBJS = simple_thread.o
SIMPLE_THREAD = simple_thread 

BINS = $(SIMPLE_THREAD) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SIMPLE_THREAD): $(SIMPLE_THREAD_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_THREAD) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_THREAD_OBJS) $(BINS)

