// Generated by the protocol buffer compiler , zqrpc plugin.  DO NOT EDIT!

#include "echo.zqrpc.h"
#include "echo.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/stubs/once.h>
#include <zqrpc.hpp>
namespace {
const ::google::protobuf::ServiceDescriptor* EchoService_descriptor_ = NULL;
}  // anonymous namespace

namespace echo {

void zqrpc_protobuf_AssignDesc_echo_2eproto() {
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "echo.proto");
  GOOGLE_CHECK(file != NULL);
  EchoService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &zqrpc_protobuf_AssignDesc_echo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void zqrpc_protobuf_ShutdownFile_echo_2eproto() {
}

void zqrpc_protobuf_AddDesc_echo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\necho.proto\022\004echo\"\'\n\013EchoRequest\022\030\n\007mes"
    "sage\030\001 \001(\tR\007message\"*\n\014EchoResponse\022\032\n\010r"
    "esponse\030\001 \001(\tR\010response2m\n\013EchoService\022."
    "\n\005Echo1\022\021.echo.EchoRequest\032\022.echo.EchoRe"
    "sponse\022.\n\005Echo2\022\021.echo.EchoRequest\032\022.ech"
    "o.EchoResponseb\006proto3", 222);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "echo.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&zqrpc_protobuf_ShutdownFile_echo_2eproto);
}

// ===================================================================

EchoService::~EchoService() {}

const ::google::protobuf::ServiceDescriptor* EchoService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* EchoService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoService_descriptor_;
}

void EchoService::Echo1(const ::echo::EchoRequest* request,
                         ::echo::EchoResponse* response) {
  throw ::zqrpc::ZError(::zqrpc::ZEC_METHODNOTIMPLEMENTED,
              "Method Echo1() not implemented.");
}

void EchoService::Echo2(const ::echo::EchoRequest* request,
                         ::echo::EchoResponse* response) {
  throw ::zqrpc::ZError(::zqrpc::ZEC_METHODNOTIMPLEMENTED,
              "Method Echo2() not implemented.");
}

void EchoService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response) {
  GOOGLE_DCHECK_EQ(method->service(), EchoService_descriptor_);
  switch(method->index()) {
    case 0:
      Echo1(
          ::google::protobuf::down_cast<const ::echo::EchoRequest*>(request),
          ::google::protobuf::down_cast< ::echo::EchoResponse* >(response) );
      break;
    case 1:
      Echo2(
          ::google::protobuf::down_cast<const ::echo::EchoRequest*>(request),
          ::google::protobuf::down_cast< ::echo::EchoResponse* >(response) );
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& EchoService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::echo::EchoRequest::default_instance();
    case 1:
      return ::echo::EchoRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& EchoService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::echo::EchoResponse::default_instance();
    case 1:
      return ::echo::EchoResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

EchoService_Stub::EchoService_Stub(::zqrpc::RpcChannel* channel)
  : channel_(channel) {}
EchoService_Stub::~EchoService_Stub() {}

void EchoService_Stub::Echo1(::zqrpc::ZController* controller,
                     ::echo::EchoRequest* request,
                     ::echo::EchoResponse* response,
                     long deadline_ms){
  Echo1_Send(controller,request);
  Echo1_Recv(controller,response,deadline_ms);
}
void EchoService_Stub::Echo1_Send(::zqrpc::ZController* controller,
                     ::echo::EchoRequest* request){
  channel_->ZSendMethod(EchoService::descriptor()->method(0),
                        controller,
                        request);
}
void EchoService_Stub::Echo1_Recv(::zqrpc::ZController* controller,
                     ::echo::EchoResponse* response,
                     long deadline_ms){
  channel_->ZRecvMethod(controller,
                        response,
                        deadline_ms);
}
void EchoService_Stub::Echo2(::zqrpc::ZController* controller,
                     ::echo::EchoRequest* request,
                     ::echo::EchoResponse* response,
                     long deadline_ms){
  Echo2_Send(controller,request);
  Echo2_Recv(controller,response,deadline_ms);
}
void EchoService_Stub::Echo2_Send(::zqrpc::ZController* controller,
                     ::echo::EchoRequest* request){
  channel_->ZSendMethod(EchoService::descriptor()->method(1),
                        controller,
                        request);
}
void EchoService_Stub::Echo2_Recv(::zqrpc::ZController* controller,
                     ::echo::EchoResponse* response,
                     long deadline_ms){
  channel_->ZRecvMethod(controller,
                        response,
                        deadline_ms);
}

}  // namespace echo