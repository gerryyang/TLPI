include ../../Inc.mk

OUCH_OBJS = ouch.o
OUCH = ouch 

BINS = $(OUCH) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(OUCH): $(OUCH_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(OUCH) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(OUCH_OBJS) $(BINS)

