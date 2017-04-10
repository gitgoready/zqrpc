/**
 * @project zqrpc
 * @file examples/EchoClient.cc
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
 *  EchoClient.cc : Echo Client
 *
 */

#include <iostream>
#include <vector>
#include "zqrpc.hpp"
#include "echo.pb.h"
#include "echo.zqrpc.h"
#include "dqlib.pb.h"
#include "dqlib.zqrpc.h"
#include "EchoEndpoint.hh"
#include <thread>
//#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>
#include "inirw.h"
#include <fstream>

using namespace std;

struct Basket {
	zqrpc::ZController controller;
	echo::EchoRequest request;
	echo::EchoResponse response;
	bool use_one;
	long waitfor;
	Basket(const char* message,bool use_echo_one, long wait_time)
		: use_one(use_echo_one),waitfor(wait_time) {
		request.set_message(message);
	}
	virtual ~Basket() {}
};

struct DQBasket {
	zqrpc::ZController controller;
	echo::MvoAssetAllocationInput request;
	echo::MvoAssetAllocationOutput response;

	long waitfor;
	DQBasket(echo::MvoAssetAllocationInput input,  long wait_time)
		: waitfor(wait_time) {
		request = input;
	}
	virtual ~DQBasket() {}
};

std::vector<bool> result_list;
std::vector<int64_t> time_list;

char* host = new char[128];
int thread_cnt = 50;
int cycle_cnt = 10;
mutex mt;
//double cla(zqrpc::RpcChannel& rpc_channel,int ncycle)
//{
//	//echo::EchoService::Stub stub(&rpc_channel);
//	echo::DQService::Stub stub(&rpc_channel);
//	echo::MvoAssetAllocationInput request;
//	request.set_strategy("MVOSTRANDARD");
//	request.set_target_type("MINVAR");
//
//	::echo::Matrix* ar = new ::echo::Matrix();
//	ar->set_cols(2);
//	ar->set_rows(2);
//	ar->add_data(0.00215);
//	ar->add_data(-0.00062);
//	ar->add_data(-0.00062);
//	ar->add_data(0.00069);
//
//	request.set_allocated_asset_return(ar);
//
//	::echo::Vector* lvec = new ::echo::Vector();
//	lvec->add_data(0);
//	lvec->add_data(0);
//	request.set_allocated_lower_bound(lvec);
//	::echo::Vector* uvec = new ::echo::Vector();
//	uvec->add_data(1);
//	uvec->add_data(1);
//	request.set_allocated_upper_bound(uvec);
//
//	request.set_target_value(0);
//	request.set_num_returns_for_mean(2);
//	request.set_annualization_scale(2);
//	request.set_num_ef_points(10);
//
//	DQBasket ket(request, 10000);
//	stub.CLAService_Send(&ket.controller, &ket.request);
//	stub.CLAService_Recv(&ket.controller, &ket.response, ket.waitfor);
//
//	bool ret = std::abs(ket.response.target_value() - 0.00277) < 0.00001;
//	mt.lock();
//	result_list.push_back(ret);
//	mt.unlock();
////	return ket.response.target_value();
//
//}

bool cla_test(zqrpc::RpcChannel& rpc_channel,  echo::MvoAssetAllocationInput& request, int ncycle)
{
	for (int j = 0; j < ncycle; j++)
	{
        auto start_time = chrono::high_resolution_clock::now();
		echo::DQService::Stub stub(&rpc_channel);
		DQBasket ket(request, 10000);
		try {
			stub.CLAService_Send(&ket.controller, &ket.request);
			stub.CLAService_Recv(&ket.controller, &ket.response, ket.waitfor);
			auto end_time = chrono::high_resolution_clock::now();
			int64_t cnt = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() ;
			bool ret = std::abs(ket.response.target_value() - 0.00277) < 0.00001;

			mt.lock();
			result_list.push_back(ret);
			time_list.push_back(cnt);
			mt.unlock();
		} catch (zmq::error_t& e) {
			std::cerr << "ZMQ EXCEPTION : " << e.what() << std::endl;
		} catch (std::exception& e) {
			std::cerr << "STD EXCEPTION : " << e.what() << std::endl;
		} catch (...) {
			std::cerr << " UNTRAPPED EXCEPTION " << std::endl;
		}
	}
	return true;
}

const string kResultFile = "result.txt";
int main(int argc, char *argv[])
{
//	ofstream fout(kResultFile);           //打开文件用于写,若文件不存在就创建它
//	fout << "test begin" << endl;
//	fout << fixed << setprecision(0)
//			 << 10000000000000000 << " s" << endl;
//	fout << true << endl;
//	fout.close();

	google::InitGoogleLogging(argv[0]);
	zmq::context_t* context = 0;
	std::vector<thread> cla_threads;

    std::cout << "Start testing: \n" ;
    iniFileLoad("testConfig.ini");

    iniGetString("test","host",host,64,"");
    int total = iniGetInt("test","total_cnt",0);
    thread_cnt = iniGetInt("test","thread_cnt",0);
    cycle_cnt = iniGetInt("test","total_cnt",0)/thread_cnt;

    std::cout << "Host " << host << "\ntotal_cnt: " << total << "\nthread_cnt:  " << thread_cnt << "\ncycle_cnt: " << cycle_cnt << endl ;


		context = new zmq::context_t(1);
		zqrpc::RpcChannel rpc_channel(context, host);
		result_list.clear();

		//echo::EchoService::Stub stub(&rpc_channel);
		echo::DQService::Stub stub(&rpc_channel);
		echo::MvoAssetAllocationInput request;
		request.set_strategy("MVOSTRANDARD");
		request.set_target_type("MINVAR");

		::echo::Matrix* ar = new ::echo::Matrix();
		ar->set_cols(2);
		ar->set_rows(2);
		ar->add_data(0.00215);
		ar->add_data(-0.00062);
		ar->add_data(-0.00062);
		ar->add_data(0.00069);

		request.set_allocated_asset_return(ar);

		::echo::Vector* lvec = new ::echo::Vector();
		lvec->add_data(0);
		lvec->add_data(0);
		request.set_allocated_lower_bound(lvec);
		::echo::Vector* uvec = new ::echo::Vector();
		uvec->add_data(1);
		uvec->add_data(1);
		request.set_allocated_upper_bound(uvec);

		request.set_target_value(0);
		request.set_num_returns_for_mean(2);
		request.set_annualization_scale(2);
		request.set_num_ef_points(10);
		//DQBasket ket(request, 20000);

        auto start_time = chrono::high_resolution_clock::now();
        cla_threads.clear();
		for (int j = 0; j<thread_cnt;j++)
		{
			thread t(cla_test, std::ref(rpc_channel), std::ref(request), cycle_cnt);
            cla_threads.push_back(std::move(t));
		}
        for (auto& t : cla_threads)
            t.join();

        auto end_time = chrono::high_resolution_clock::now();
        int64_t cnt = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() ;

		int succ = 0;
		int fail = 0;
		for (int i = 0; i < result_list.size(); i++)
		{
			if (result_list.at(i))
				succ++;
			else
				fail++;
		}

        std::cout << "Total tests:" << thread_cnt*cycle_cnt << " times,used time  " << fixed << setprecision(0)<< cnt/1000000000 << " s. " << endl;
        std::sort(time_list.begin(),time_list.end());
        //unsigned int sum = std::accumulate(time_list.begin(),time_list.end(),0);
        double mean = 0;
        for(auto i:time_list)
            mean+=i/1.0/succ/1000000;

        //std::cout<< time_list[succ-1] <<" " << time_list[succ-2] << " "<< time_list[succ-3] <<" " << time_list[succ-4] << endl;
        //std::cout << "Total time: " << fixed << setprecision(0) << sum/1000.0 << " ms "<<" cnt: " << time_list.size() << endl;
        if(succ<total)
            std::cout << "Fail: " << total - succ << endl ;
        std::cout<< "Throughput: " << std::round(thread_cnt*cycle_cnt/(cnt/1000000000.0))  <<"\n Mean : " << fixed << setprecision(0) << mean <<" ms\n Median: " <<time_list[succ/2]/1000000.0<< " ms\n Max:"<< time_list[succ-1]/1000000.0 <<" ms" << endl<< endl;


	if (context) delete context;
	return 0;
}

