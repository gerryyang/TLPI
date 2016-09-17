include ../../Inc.mk

PSHM_CREATE_OBJS = pshm_create.o
PSHM_CREATE = pshm_create

PSHM_WRITE_OBJS = pshm_write.o
PSHM_WRITE = pshm_write

PSHM_READ_OBJS = pshm_read.o
PSHM_READ = pshm_read

PSHM_UNLINK_OBJS = pshm_unlink.o
PSHM_UNLINK = pshm_unlink

BINS = $(PSHM_CREATE) $(PSHM_WRITE) $(PSHM_READ) $(PSHM_UNLINK)
#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(PSHM_CREATE): $(PSHM_CREATE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PSHM_CREATE) OK!"

$(PSHM_WRITE): $(PSHM_WRITE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PSHM_WRITE) OK!"

$(PSHM_READ): $(PSHM_READ_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PSHM_READ) OK!"

$(PSHM_UNLINK): $(PSHM_UNLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PSHM_UNLINK) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(PSHM_CREATE_OBJS) $(PSHM_WRITE_OBJS) $(PSHM_READ_OBJS) \
		$(PSHM_UNLINK_OBJS) \
		$(BINS)

