include ../../Inc.mk

T_SYSCONF_OBJS = t_sysconf.o
T_SYSCONF = t_sysconf

BINS = $(T_SYSCONF) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_SYSCONF): $(T_SYSCONF_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SYSCONF) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_SYSCONF_OBJS) $(BINS)

