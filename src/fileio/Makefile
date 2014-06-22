include ../../Inc.mk

COPY_OBJS = copy.o
COPY = copy

SEEK_IO_OBJS = seek_io.o
SEEK_IO = seek_io

BINS = $(COPY) $(SEEK_IO)

#CFLAGS += -Dxxx

all: $(BINS)

$(COPY): $(COPY_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(COPY) OK!"

$(SEEK_IO): $(SEEK_IO_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SEEK_IO) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(COPY_OBJS) $(SEEK_IO_OBJS) $(BINS)

