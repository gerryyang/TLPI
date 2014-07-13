include ../../Inc.mk

FREEANDSBRK_OBJS = free_and_sbrk.o
FREEANDSBRK = free_and_sbrk

BINS = $(FREEANDSBRK) 

CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(FREEANDSBRK): $(FREEANDSBRK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FREEANDSBRK) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(FREEANDSBRK_OBJS) $(BINS)

