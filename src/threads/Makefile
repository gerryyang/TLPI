include ../../Inc.mk

SIMPLE_THREAD_OBJS = simple_thread.o
SIMPLE_THREAD = simple_thread 

DETACHED_ATTRIB_OBJS = detached_attrib.o
DETACHED_ATTRIB = detached_attrib

BINS = $(SIMPLE_THREAD) $(DETACHED_ATTRIB)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SIMPLE_THREAD): $(SIMPLE_THREAD_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_THREAD) OK!"

$(DETACHED_ATTRIB): $(DETACHED_ATTRIB_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(DETACHED_ATTRIB) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_THREAD_OBJS) $(DETACHED_ATTRIB_OBJS) $(BINS)

