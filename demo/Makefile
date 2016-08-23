include ../Inc.mk

SYSCALL_SPEED_OBJS = syscall_speed.o
SYSCALL_SPEED = syscall_speed

BINS = $(SYSCALL_SPEED)

CFLAGS += -DNOSYSCALL

all: $(BINS)

$(SYSCALL_SPEED): $(SYSCALL_SPEED_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SYSCALL_SPEED) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SYSCALL_SPEED_OBJS) $(BINS)

