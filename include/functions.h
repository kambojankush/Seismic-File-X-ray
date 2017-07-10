using namespace std;


/************************************************************************************************************/
/**************************************************FOR TEXT HEADER*******************************************/
/************************************************************************************************************/

//Convert the character array from EBCDIC format to ASCII
void convertASCII(char* arr, int size)
{
  for(int i = 0; i < size; i++)
    arr[i] = EBCDICtoASCII(arr[i]);
}

//Write TextHeader to text file
void write_text_header(ofstream &out, char* arr, int size = 3200)
{
  for(int i = 0; i < size; i++)
  {
    if (i!= 0 && i%80 == 0)
        out.put('\n');
    out.put(arr[i]);
  }
}


/************************************************************************************************************/
/***************************************************FOR FILE*************************************************/
/************************************************************************************************************/


//Print File status of given file
void printfilestatus(ifstream& f)
{
  cout << "\nFile status: [" << &f << "]" << endl;
  cout << "Error state: " << f.rdstate() << endl;
  cout << "good() " << f.good() << endl;
  cout << "bad() " << f.bad() << endl;
  cout << "fail()" << f.fail() << endl;
}

void printfilestatus(ofstream& f)
{
  cout << "\nFile status: [" << &f << "]" << endl;
  cout << "Error state: " << f.rdstate() << endl;
  cout << "good() " << f.good() << endl;
  cout << "bad() " << f.bad() << endl;
  cout << "fail()" << f.fail() << endl;
}

unsigned int csv_read(ifstream& in_, int tracenum_)
{
  string str;
  int num_of_samples;
  while(tracenum_--)
  {
    getline(in_, str);
  }
  in_ >> num_of_samples;
  return num_of_samples;
}


/************************************************************************************************************/
/******************************************FRIEND FUNCTIONS**************************************************/
/************************************************************************************************************/

//Convert the value stored at given bytes to correct form
short int readvalue_si(char* arr, int pos)
{
  short int x = (((arr[pos++] & 0xff )<<8)|(arr[pos] & 0xff));
  return x;
}


int readvalue_i(char* arr, int pos)
{
  int x = ((arr[pos++] & 0xffff)<<24 | (arr[pos++] & 0xffff)<<16 | (arr[pos++] & 0xffff)<<8 | (arr[pos] & 0xffff));
  return x;
}


void readvalue_c(char* r, char* arr, int start, int size)
{
  for(int i = 0; i < size; i++)
    r[i] = arr[start + i];
}

/************************************************************************************************************/
/********************************************END OF HEADER FILE**********************************************/
/************************************************************************************************************/