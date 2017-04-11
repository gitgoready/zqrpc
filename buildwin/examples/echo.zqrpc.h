// Generated by the protocol buffer compiler , zqrpc plugin.  DO NOT EDIT!
// source: echo.proto

#ifndef ZQRPC_echo_2eproto__INCLUDED
#define ZQRPC_echo_2eproto__INCLUDED

#include <string>
#include <zqrpc.hpp>

namespace google {
namespace protobuf {
class ServiceDescriptor;
class MethodDescriptor;
}  // namespace protobuf
}  // namespace google
namespace zqrpc {
class RpcChannel;
}  //namespace zqrpc
#include "echo.pb.h"

namespace echo {
void zqrpc_protobuf_AssignDesc_echo_2eproto();
void zqrpc_protobuf_ShutdownFile_echo_2eproto();

class EchoService_Stub;

class EchoService : public zqrpc::ServiceBase {
 protected:
  // This class should be treated as an abstract interface.
  inline EchoService() {};
 public:
  virtual ~EchoService();

  typedef EchoService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Echo1(const ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response);
  virtual void Echo2(const ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService);
};

class EchoService_Stub {
 public:
  EchoService_Stub(::zqrpc::RpcChannel* channel); 
  ~EchoService_Stub();

  inline ::zqrpc::RpcChannel* channel() { return channel_; }


  void Echo1(::zqrpc::ZController* controller,
                       ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response,
                       long deadline_ms=-1);
  void Echo1_Send(::zqrpc::ZController* controller,
                       ::echo::EchoRequest* request);
  void Echo1_Recv(::zqrpc::ZController* controller,
                       ::echo::EchoResponse* response,
                       long deadline_ms=-1);
  void Echo2(::zqrpc::ZController* controller,
                       ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response,
                       long deadline_ms=-1);
  void Echo2_Send(::zqrpc::ZController* controller,
                       ::echo::EchoRequest* request);
  void Echo2_Recv(::zqrpc::ZController* controller,
                       ::echo::EchoResponse* response,
                       long deadline_ms=-1);
 private:
  ::zqrpc::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService_Stub);
};


}  // namespace echo
#endif  // ZQRPC_echo_2eproto__INCLUDED
