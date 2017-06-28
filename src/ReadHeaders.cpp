#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../include/convEBCDIC.h"
#include "../include/functions.h"
#include "../include/binaryheader.h"
#include "../include/traceheader.h"

using namespace std;

int main(int argc, char* argv[])
{
	//ensure proper usage
	if (argc != 5)
	{
		cout << "Usage: [./ReadHeaders filename.sgy outputfile1.txt outputfile2.txt outputfile3.txt]";
		exit(-1);
	}

	//create ifstream object
	ifstream seg;
	//create ofstream objects
	ofstream out_txt, out_bin, out_trc;

	//open files
	seg.open(argv[1], ios::binary);
	out_txt.open(argv[2], ios::trunc);
	out_bin.open(argv[3], ios::trunc);
	out_trc.open(argv[4], ios::trunc);

	//error checking
	if (!seg)
	{
		cerr << "Can't open file " << argv[1];
		exit(-2);
	}
	if (!out_txt)
	{
		cerr << "Can't open file " << argv[2];
		exit(-3);
	}
	if (!out_bin)
	{
		cerr << "Can't open file " << argv[3];
		exit(-4);
	}
	if (!out_trc)
	{
		cerr << "Can't open file " << argv[4];
		exit(-5);
	}
	//Display file status
	printfilestatus(seg);
	printfilestatus(out_txt);
	printfilestatus(out_bin);
	printfilestatus(out_trc);
	//Allocate memory for TextHeader
	char* txtHeader = NULL;
	txtHeader = new char[3200];

	//Read, covert and write Text Header
	seg.read(txtHeader,3200);
	convertASCII(txtHeader,3200);
	write_text_header(out_txt,txtHeader);
	// free memory
	delete txtHeader;

	//Allocate memory for BinaryHeader
	char* binData = NULL;
	binData = new char[400];
	seg.read(binData, 400);

	//Create BinaryHeader object
	BinaryHeader bHeader;
	bHeader.store(binData);
	//Write object to file
	bHeader.write(out_bin);
	//free memory
	delete binData;

	char* trcData;
	trcData = new char[240];
	seg.read(trcData, 240);

	TraceHeader trcHeader;
	trcHeader.store(trcData);
	trcHeader.write(out_trc);

	//close the open files
	out_txt.close();
	out_bin.close();
	seg.close();

	//Program successfully executed
	return 0;
}
