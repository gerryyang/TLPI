include ../../Inc.mk

MMCAT_OBJS = mmcat.o
MMCAT = mmcat 

T_MMAP_OBJS = t_mmap.o
T_MMAP = t_mmap 

BINS = $(MMCAT) $(T_MMAP)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(MMCAT): $(MMCAT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(MMCAT) OK!"

$(T_MMAP): $(T_MMAP_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_MMAP) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(MMCAT_OBJS) $(T_MMAP_OBJS) $(BINS)

