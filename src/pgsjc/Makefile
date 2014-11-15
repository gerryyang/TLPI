include ../../Inc.mk

SETSID_OBJS = t_setsid.o
SETSID = t_setsid

BINS = $(SETSID) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SETSID): $(SETSID_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SETSID) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SETSID_OBJS) $(BINS)

