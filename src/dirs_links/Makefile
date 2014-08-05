include ../../Inc.mk

T_UNLINK_OBJS = t_unlink.o
T_UNLINK = t_unlink

VIEW_SYMLINK_OBJS = view_symlink.o
VIEW_SYMLINK = view_symlink

BINS = $(T_UNLINK) $(VIEW_SYMLINK) 

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_UNLINK): $(T_UNLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_UNLINK) OK!"

$(VIEW_SYMLINK): $(VIEW_SYMLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(VIEW_SYMLINK) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_UNLINK_OBJS) $(VIEW_SYMLINK_OBJS) $(BINS)

