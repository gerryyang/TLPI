include ../../Inc.mk

SIMPLE_PIPES_OBJS = simple_pipe.o
SIMPLE_PIPES = simple_pipe

PIPE_SYNC_OBJS = pipe_sync.o
PIPE_SYNC = pipe_sync

PIPE_LS_WC_OBJS = pipe_ls_wc.o
PIPE_LS_WC = pipe_ls_wc

FIFO_CLIENT_OBJS = fifo_client.o
FIFO_CLIENT = fifo_client 

FIFO_SERVER_OBJS = fifo_server.o
FIFO_SERVER = fifo_server 

CHANGE_CASE_OBJS = change_case.o
CHANGE_CASE = change_case 

BINS = $(SIMPLE_PIPES) $(PIPE_SYNC) $(PIPE_LS_WC) $(FIFO_CLIENT) $(FIFO_SERVER) $(CHANGE_CASE)
#CFLAGS += -Wno-deprecated-declarations

all: $(BINS)

$(SIMPLE_PIPES): $(SIMPLE_PIPES_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(SIMPLE_PIPES) OK!"

$(PIPE_SYNC): $(PIPE_SYNC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PIPE_SYNC) OK!"

$(PIPE_LS_WC): $(PIPE_LS_WC_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(PIPE_LS_WC) OK!"

$(FIFO_CLIENT): $(FIFO_CLIENT_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FIFO_CLIENT) OK!"

$(FIFO_SERVER): $(FIFO_SERVER_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(FIFO_SERVER) OK!"

$(CHANGE_CASE): $(CHANGE_CASE_OBJS)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	@echo "build $(CHANGE_CASE) OK!"

install:
	@echo "nothing to install"

clean:
	-rm -f $(SIMPLE_PIPES_OBJS) $(PIPE_SYNC_OBJS) $(PIPE_LS_WC_OBJS) \
		$(FIFO_CLIENT_OBJS) $(FIFO_SERVER_OBJS) \
		$(CHANGE_CASE_OBJS) \
		$(BINS)

