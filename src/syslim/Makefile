include ../../Inc.mk

T_SYSCONF_OBJS = t_sysconf.o
T_SYSCONF = t_sysconf

T_FPATHCONF_OBJS = t_fpathconf.o
T_FPATHCONF = t_fpathconf

BINS = $(T_SYSCONF) $(T_FPATHCONF)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_SYSCONF): $(T_SYSCONF_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SYSCONF) OK!"

$(T_FPATHCONF): $(T_FPATHCONF_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_FPATHCONF) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_SYSCONF_OBJS) $(T_FPATHCONF_OBJS) $(BINS)

