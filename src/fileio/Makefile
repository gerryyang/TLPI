include ../../Inc.mk

COPY_OBJS = copy.o
COPY = copy

BINS = $(COPY)

#CFLAGS += -Dxxx

all: $(BINS)

$(COPY): $(COPY_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(COPY) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(COPY_OBJS) $(BINS)

