include(zqrpc_functions)
find_package(ProtobufPlugin REQUIRED)
#PROTOBUF_GENERATE_CPP(ECHO_PB_SRCS ECHO_PB_HDRS echo.proto)
#PROTOBUF_GENERATE_ZQRPC(ECHO_ZQRPC_SRCS ECHO_ZQRPC_HDRS echo.proto)
#PROTOBUF_GENERATE_CPP(DQLIB_PB_SRCS DQLIB_PB_HDRS dqlib.proto)
#PROTOBUF_GENERATE_ZQRPC(DQLIB_ZQRPC_SRCS DQLIB_ZQRPC_HDRS dqlib.proto)
include_directories("/media/psf/Home/Documents/work-ubuntu/zqrpc-master/examples/")
set(ECHO_SRCS
        echo.pb.cc
        echo.pb.h
        echo.zqrpc.cc
        echo.zqrpc.h
        dqlib.pb.cc
        dqlib.pb.h
        dqlib.zqrpc.cc
        dqlib.zqrpc.h
        inirw.c
        inirw.h
        )
add_library(echo_pb ${ECHO_PB_SRCS} ${ECHO_SRCS})#${ECHO_PB_HDRS} ${ECHO_ZQRPC_SRCS} ${ECHO_ZQRPC_HDRS} ${DQLIB_PB_SRCS} ${DQLIB_PB_HDRS} ${DQLIB_ZQRPC_SRCS} ${DQLIB_ZQRPC_HDRS})#

target_link_libraries(echo_pb ${PROTOBUF_LIBRARY})
include_directories(${PROJECT_BINARY_DIR}/examples)

add_executable(EchoClient EchoClient.cc)
target_link_libraries(EchoClient zqrpc echo_pb)

add_executable(EchoServer EchoServer.cc)
target_link_libraries(EchoServer zqrpc  rt dl echo_pb)
