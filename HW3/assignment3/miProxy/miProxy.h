#ifndef mip
#define mip

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <algorithm>
#include <cassert>
#include <string>
#include <sys/time.h>
#include <iostream>
#include <netdb.h>
#include <sys/select.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "DNSProtocol.h"

using namespace std;

class miProxy{
	public:
	miProxy(char* logName,float alp,int por,char* dnsip,int dnspor,string ip="video.cs.jhu.edu");
	string recvBuffer(int ser, int &cont_length);
	int sendAll(int socket,char *buf,int *length);
	vector<int> getBitrates(const string& xml);
	int timeval_subtract (struct timeval * result, struct timeval * x, struct timeval * y);
	void run();
	void pttoLog(string filePath,float duration,float tput,float avgTput,int bitrate,string serverIp,string chunkName);
	bool wwwisProvided=false;	
	private:
	string toLog="";
	float alpha=0;
	int port=0;
	string wwwip="";
	
	string dnsIPaddress="";
	int dnsport=0;
	// Set of file descriptors to listen to
	fd_set readSet;
	// Keep track of each file descriptor accepted
	vector<int> fds;
    	vector<int> bitrates;
	int sd = 0; //listen to browser
    	int ser = 0;//connect to the server
	struct sockaddr_in self, seraddr;
};


#endif
