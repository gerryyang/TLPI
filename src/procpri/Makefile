include ../../Inc.mk

T_SETPRIORITY_OBJS = t_setpriority.o
T_SETPRIORITY = t_setpriority

BINS = $(T_SETPRIORITY) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_SETPRIORITY): $(T_SETPRIORITY_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SETPRIORITY) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_SETPRIORITY_OBJS) $(BINS)

