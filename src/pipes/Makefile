include ../../Inc.mk

SIMPLE_PIPES_OBJS = simple_pipe.o
SIMPLE_PIPES = simple_pipe

BINS = $(SIMPLE_PIPES) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SIMPLE_PIPES): $(SIMPLE_PIPES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_PIPES) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_PIPES_OBJS) $(BINS)

