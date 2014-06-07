include ../../Inc.mk

T_SELECT_OBJS = t_select.o
T_SELECT = t_select

POLL_PIPES_OBJS = poll_pipes.o
POLL_PIPES = poll_pipes

BINS = $(T_SELECT) $(POLL_PIPES)
OBJS = $(T_SELECT_OBJS) $(POLL_PIPES_OBJS)

#CFLAGS += -Dxxx

all: $(BINS)

$(T_SELECT): $(T_SELECT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(T_SELECT) OK!"

$(POLL_PIPES): $(POLL_PIPES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(POLL_PIPES) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(OBJS) $(BINS)

