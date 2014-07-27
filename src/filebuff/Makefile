include ../../Inc.mk

WRITE_BYTES_OBJS = write_bytes.o
WRITE_BYTES = write_bytes

BINS = $(WRITE_BYTES) 

#CFLAGS += -Dxxx

all: $(BINS)

$(WRITE_BYTES): $(WRITE_BYTES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(WRITE_BYTES) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(WRITE_BYTES_OBJS) $(BINS)

