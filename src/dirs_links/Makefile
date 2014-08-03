include ../../Inc.mk

T_UNLINK_OBJS = t_unlink.o
T_UNLINK = t_unlink

BINS = $(T_UNLINK) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_UNLINK): $(T_UNLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_UNLINK) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_UNLINK_OBJS) $(BINS)

