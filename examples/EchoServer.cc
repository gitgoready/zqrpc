/**
 * @project zqrpc
 * @file examples/EchoServer.cc
 * @author  S Roychowdhury <sroycode @ gmail DOT com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * Copyright (c) 2014 S Roychowdhury
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 *  EchoServer.cc : Echo Server Demo
 *
 */
//#include <unistd.h>
#include <signal.h>
#include <boost/bind.hpp>
#include <stdio.h>
#include <iostream>
#include "zqrpc.hpp"
#include "echo.pb.h"
#include "echo.zqrpc.h"
#include "dqlib.pb.h"
#include "dqlib.zqrpc.h"
#include "EchoEndpoint.hh"

#include <dlfcn.h>
#include "inirw.h"
#ifdef WIN32
#include <Windows.h>
#endif

class EchoServiceImpl : public echo::EchoService {
public:
	EchoServiceImpl() {};

	virtual void Echo1(const ::echo::EchoRequest* request,
	                   ::echo::EchoResponse* response) {
		std::cerr << " Received1 " << request->DebugString() << std::endl;
		response->set_response(std::string("You sent1: ") + request->message());
	}
	virtual void Echo2(const ::echo::EchoRequest* request,
	                   ::echo::EchoResponse* response) {
		std::cerr << " Received2 " << request->DebugString() << std::endl;
		//sleep(3);
		response->set_response(std::string("You sent2: ") + request->message());
	}
};

using namespace std;
void* handle=NULL;
typedef void (*FPTR)(char* req_type, unsigned char* req_arg_msg, int length, unsigned char* out, int* out_length, char** err);
FPTR fptr = NULL;
char err_buf[256] = "\0";
int out_len = 5120;
unsigned char* out = new unsigned char[out_len];
unsigned char* in = new unsigned char[out_len];
char* host = new char[64];

void init()
{
    iniFileLoad("testConfig.ini");
    iniGetString("test","server_host",host,128,"");

    if (handle == NULL){
        handle = dlopen("./libdqlibgo.so.1.2", RTLD_LAZY);// RTLD_GLOBALRTLD_NOW
        printf("dll init loaded\n");
    }
    if (handle != NULL){
        fptr = (FPTR)dlsym(handle, "ProcessRequest");
        printf("function init loaded\n");
    }
}


void PRequest(char* req_type, unsigned char* req_arg_msg,int length, unsigned char* out, int* out_length, char** error)
{
    if (handle == NULL) {
        handle = dlopen("./libdqlibgo.so.1.2", RTLD_LAZY);// RTLD_GLOBALRTLD_NOW
        printf("dll reloaded\n");
        if (handle == NULL) {
            strcpy(err_buf,"dlopen ");
            strcat(err_buf,(char*)dlerror());
            *error = err_buf;
            return;
        }
    }

    if (fptr == NULL) {
        fptr = (FPTR)dlsym(handle, "ProcessRequest");
        printf("function reloaded\n");
        if (fptr == NULL) {
            strcpy(err_buf,"dlsym  ");
            strcat(err_buf,(char*)dlerror());
            *error = err_buf;
            return;
        }
    }

    (*fptr)(req_type,req_arg_msg,length,out,out_length,error);
    return;

}

class DQServiceImpl : public echo::DQService {
public:
	DQServiceImpl() {};

	virtual void CLAService(const ::echo::MvoAssetAllocationInput* request,
		::echo::MvoAssetAllocationOutput* response)
	{
		int in_len = request->ByteSize();
		request->SerializeToArray(in, in_len);
		//cout << "loadlibrary start. " <<  endl;
        try
        {
            if (fptr != NULL)
            {
                char* error=NULL;
                //cout << "ProcessRequest start. " << endl;
                PRequest("MVOASSETALLOCATION", in, in_len, out, &out_len,&error);
                if(error!=NULL)
                {
                    cout << "error occurs:" << error;
                    return;
                }

                response->ParseFromArray(out, out_len);
            }
            else{
                init();
                cout << "Reload library";
            }
        }
        catch (const std::exception& e)
        {
            cout << e.what();
        }
		catch (...)
		{
			cout << "Unknown exception: " << endl;
		}
	}
};

void OnExit(int sig)
{
	std::cerr << "Exiting on ^C " << sig << std::endl;
}

int main(int argc, char *argv[])
{
    init();

	google::InitGoogleLogging(argv[0]);
	zmq::context_t* context = 0;
	try {
		context = new zmq::context_t(4);
		zqrpc::RpcServer rpc_server(context);
		rpc_server.EndPoint(host);//ECHO_ENDPOINT_PORT

		zqrpc::ServiceBase *service = new EchoServiceImpl();
		rpc_server.RegisterService(service);
		zqrpc::ServiceBase *servicedq = new DQServiceImpl();
		rpc_server.RegisterService(servicedq);

        cout << "Serving requests on "<< host << endl;
		rpc_server.Start(20);

	} catch (zmq::error_t& e) {
		std::cerr << "ZMQ EXCEPTION : " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "STD EXCEPTION : " << e.what() << std::endl;
	} catch (...) {
		std::cerr << " UNTRAPPED EXCEPTION " << std::endl;
	}
	if (context) delete context;

	return 0;
}
