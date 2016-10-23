include ../../Inc.mk

MMCAT_OBJS = mmcat.o
MMCAT = mmcat 

BINS = $(MMCAT) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(MMCAT): $(MMCAT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MMCAT) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(MMCAT_OBJS) $(BINS)

