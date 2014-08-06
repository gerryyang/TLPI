include ../../Inc.mk

T_UNLINK_OBJS = t_unlink.o
T_UNLINK = t_unlink

VIEW_SYMLINK_OBJS = view_symlink.o
VIEW_SYMLINK = view_symlink

LIST_FILES_OBJS = list_files.o
LIST_FILES = list_files

BINS = $(T_UNLINK) $(VIEW_SYMLINK) $(LIST_FILES)

#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(T_UNLINK): $(T_UNLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_UNLINK) OK!"

$(VIEW_SYMLINK): $(VIEW_SYMLINK_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(VIEW_SYMLINK) OK!"

$(LIST_FILES): $(LIST_FILES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(LIST_FILES) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_UNLINK_OBJS) $(VIEW_SYMLINK_OBJS) $(LIST_FILES_OBJS) $(BINS)

