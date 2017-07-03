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
		cout << "Usage: [./ReadHeaders filename.sgy outputfile1.txt outputfile2.txt outputfile3.csv]";
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

    //....TODO READ EXT TEXT HEADER
    //Crrently skipped
    /*short int num_ext_head = bHeader.get_exthead();
    */
    //for testing 2
    // Calculated from text header
    int no_of_traces = 2;
    //Create TraceHeader object
	TraceHeader trcHeader;

    for(int i = 0; i < no_of_traces; i++)
    {
        //Allocate memory for TraceHeader
	    char* trcData;
	    trcData = new char[240];
	    seg.read(trcData, 240);

        
	    trcHeader.store(trcData);
	    //Write object to file
	    trcHeader.write(out_trc);
        //free memory
        delete trcData;
    
        //Sample data will be according to as def in binary header
        //using 4 for test file
        unsigned short int num_of_sampl = trcHeader.get_numsampl();
        seg.seekg(num_of_sampl * 4, ios::cur);
    }
	//close the open files
	out_txt.close();
	out_bin.close();
	out_trc.close();
	seg.close();

	//Program successfully executed
	return 0;
}
