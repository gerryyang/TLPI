include ../../Inc.mk

T_SELECT_OBJS = t_select.o
T_SELECT = t_select

BINS = $(T_SELECT)

#CFLAGS += -Dxxx

all: $(BINS)

$(T_SELECT): $(T_SELECT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SELECT) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(T_SELECT_OBJS) $(BINS)

