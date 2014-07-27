include ../../Inc.mk

DIRECT_READ_OBJS = direct_read.o
DIRECT_READ = direct_read

BINS = $(DIRECT_READ) 

#CFLAGS += -Dxxx

all: $(BINS)

$(DIRECT_READ): $(DIRECT_READ_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(DIRECT_READ) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(DIRECT_READ_OBJS) $(BINS)

