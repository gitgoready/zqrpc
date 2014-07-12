## NanoRPC
CC = g++
CCFLAGS = -ansi -Wall -Wno-deprecated -O2 -DNDEBUG
CCFLAGS += -I/opt/local/include
CCFLAGS += -I/usr/local/include
LDFLAGS = -rdynamic
LDFLAGS += -L/opt/local/lib
LDFLAGS += -L/usr/local/lib

PROTOC = protoc
MKDIR  = mkdir -p

PROTO_INCLUDE =
PROTO_LDFLAGS = -lprotobuf

NANOMSG_INCLUDE =
NANOMSG_LDFLAGS = -lnanomsg

CITYHASH_INCLUDE =
CITYHASH_LDFLAGS = -lcityhash

USE_LDFLAGS = $(PROTO_LDFLAGS) $(CITYHASH_LDFLAGS) $(NANOMSG_LDFLAGS) 

TMPLIB = .libs

SERVER_SOURCES = $(TMPLIB)/Server.o $(TMPLIB)/echo.pb.o
CHANNEL_SOURCES = $(TMPLIB)/Channel.o $(TMPLIB)/echo.pb.o

all:	mmkdir echo_client echo_server

mmkdir:
	$(MKDIR) $(TMPLIB)

echo_client:	$(CHANNEL_SOURCES) $(TMPLIB)/EchoClient.o
	$(CC) $(CCFLAGS) $(LDFLAGS) $(USE_LDFLAGS) -o echo_client $(CHANNEL_SOURCES) $(TMPLIB)/EchoClient.o

echo_server:	$(SERVER_SOURCES) $(TMPLIB)/EchoServer.o
	$(CC) $(CCFLAGS) $(LDFLAGS) $(USE_LDFLAGS) -o echo_server $(SERVER_SOURCES) $(TMPLIB)/EchoServer.o

$(TMPLIB)/Channel.o:	RpcChannel.cc RpcChannel.hh
	$(CC) -c $(CCFLAGS) RpcChannel.cc -o  $(TMPLIB)/Channel.o

$(TMPLIB)/Server.o:	RpcServer.cc RpcServer.hh
	$(CC) -c $(CCFLAGS) RpcServer.cc -o  $(TMPLIB)/Server.o

$(TMPLIB)/EchoClient.o:	EchoClient.cc EchoEndpoint.hh
	$(CC) -c $(CCFLAGS) EchoClient.cc -o  $(TMPLIB)/EchoClient.o

$(TMPLIB)/EchoServer.o:	EchoServer.cc EchoEndpoint.hh
	$(CC) -c $(CCFLAGS) EchoServer.cc -o  $(TMPLIB)/EchoServer.o

$(TMPLIB)/echo.pb.o:	echo.pb.cc echo.pb.h
	$(CC) -c $(CCFLAGS) echo.pb.cc -o  $(TMPLIB)/echo.pb.o

echo.pb.cc echo.pb.h: echo.proto
	$(PROTOC) --cpp_out=. echo.proto

clean:
	rm -f echo_client echo_server $(TMPLIB)/*.o

distclean:
	rm -f echo.pb.* echo_client echo_server $(TMPLIB)/*.o
