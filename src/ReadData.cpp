#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <arpa/inet.h>
#include <cstring>


#include "../include/conv.h"
#include "../include/functions.h"

const int DEFAULT_TRACE = 0;
const int DEFAULT_SAMPLE = 0;
// 3200(text header) + 400(binary header)
const int DEFAULT_SKIP = 3600;  

using namespace std; 

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Usage ./ReadData path [trace no] [sample no] [no of ext txt headers]";
		exit(-1);
	}

	int tracenum = (argc >= 3) ? atoi(argv[2]) : DEFAULT_TRACE;
	int samplenum = (argc >= 4) ? atoi(argv[3]) : DEFAULT_SAMPLE;
    int skip = (argc >= 5) ? (atoi(argv[4])*3200 + DEFAULT_SKIP) : DEFAULT_SKIP;

    //Create file objects
    ifstream in_trc, seg;
    ofstream out_trcdata;

    //Open files
	seg.open(argv[1], ios::binary);
	in_trc.open("../output/TraceHeader.csv");
	out_trcdata.open("../output/TraceData.csv", ios::trunc);

	//Error checking
	if (!seg)
	{
		cerr << "Can't open file " << argv[1];
		printfilestatus(seg);
		exit(-2);
	}
	if (!in_trc)
	{
		cerr << "Can't open file " << "TraceHeader.csv";
		printfilestatus(in_trc);
		exit(-3);
	}
	if (!out_trcdata)
	{
		cerr << "Can't open file " << "TraceData.csv";
		printfilestatus(out_trcdata);
		exit(-4);
	}


	//Move file pointer to 1st trace header
	seg.seekg(skip, ios::beg);

	//Move file pointer to req trace header
	for(int i = 0; i < tracenum; i++)
	{
		unsigned int num_of_sample = csv_read(in_trc, i);
		//will place the pointer just before the next trace header
		int pos = 240 + num_of_sample*4;
		seg.seekg(pos, ios::cur);
	}

	//count no of sample in given trace
	unsigned int num_of_sample = csv_read(in_trc, tracenum);
	int sample_dist = num_of_sample - samplenum;

    float ieeesample;
    uint32_t ibmsample;

	//will skip the trace header and place pointer on sample to be read
	seg.seekg(240 + samplenum*4, ios::cur);

	//Wite next 20(or remaining samples) to file
	for(int i = 0; i < 20 && i <= sample_dist; i++)
	{
		//Allocate memory for trace sample
	    char* trcValue;
	    trcValue = new char[4];
		seg.read(trcValue, 4);

		//Call to conv IBM to IEEE format
		ibmsample = *reinterpret_cast<uint32_t*>(trcValue);
		ieeesample = toIeee(ibmsample);
		//Write to file
		out_trcdata << ieeesample << ",";
		//Free memory
		delete trcValue;
	}

	//close open files
	seg.close();
	in_trc.close();
	out_trcdata.close();

	return 0;
}