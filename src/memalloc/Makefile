include ../../Inc.mk

FREEANDSBRK_OBJS =  free_and_sbrk.o
FREEANDSBRK      =  free_and_sbrk

MALLINFO_OBJS =  mallinfo_demo.o
MALLINFO      =  mallinfo_demo

BINS = $(FREEANDSBRK) 

CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(FREEANDSBRK): $(FREEANDSBRK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FREEANDSBRK) OK!"

$(MALLINFO): $(MALLINFO_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MALLINFO) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(FREEANDSBRK_OBJS) $(MALLINFO_OBJS) $(BINS)

