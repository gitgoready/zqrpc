#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/thread.hpp>
#include "zqrpc/ZSocket.hpp"

#ifdef WIN32
void usleep(int cnt)
{
	LARGE_INTEGER litmp;
	LONGLONG QPart1, QPart2;
	double dfMinus, dfFreq, dfTim;
	QueryPerformanceFrequency(&litmp);
	dfFreq = (double)litmp.QuadPart;// ??米???那y?¯米?那㊣?車?米?那
	QueryPerformanceCounter(&litmp);
	QPart1 = litmp.QuadPart;// ??米?3?那??米
	do {
		QueryPerformanceCounter(&litmp);
		QPart2 = litmp.QuadPart;//??米??D?1?米
		dfMinus = (double)(QPart2 - QPart1);
		dfTim = dfMinus / dfFreq;// ??米???車|米?那㊣???米㏒?米ㄓ???a??
	} while (dfTim<0.000001*cnt);
}
#endif

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	zmq::context_t context;
	zqrpc::ZSocket socket(&context,ZMQ_PUB,"PUBLISHER");
	socket.bind("tcp://127.0.0.1:9089");
	typedef std::vector<std::string> FramesT;
	FramesT frames;
	while (1) {
		try {
			frames.clear();
			frames.push_back("A");
			frames.push_back("This is to test 1");
			socket.Send<FramesT>(frames);

			usleep(100);
		} catch (zqrpc::ZError& e) {
			DLOG(INFO) << "ZError THROWN" << std::endl;
		} catch (zqrpc::RetryException& e) {
			DLOG(INFO) << "Retry Exception THROWN" << std::endl;
		} catch (zmq::error_t& e) {
			DLOG(INFO) << "ZMQ ZERROR THROWN : " << e.what() << std::endl;
		}
	}
}
