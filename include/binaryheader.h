/************************************************************************************************************/
/****************************************BINARY HEADER CLASS*************************************************/
/***************************Create object to read Binary Header of a SEG-Y file******************************/

//Class to create object to read Binary Header of SEG-Y file
class BinaryHeader
{
private:

    int JOB_ID;
    int LINE_NUM;
    int REEL_NUM;
    short int NUM_OF_TRACE;
    short int NUM_OF_AUX;
    short int INTERVAL_MS;
    short int INTERVAL_MS_ORI;
    unsigned short int NUM_OF_SAMPLES;
    unsigned short int NUM_OF_SAMPLES_ORI;
    short int SAMPLE_FORMAT;
    short int ENSEMBLE;
    short int TRACE_SORT;
    short int VERT_SUM;
    short int SWEEP_FREQ_START;
    short int SWEEP_FREQ_END;
    short int SWEEP_LENGTH;
    short int SWEEP_TYPE;
    short int SWEEP_NUM_CHANNEL;
    short int SWEEP_TAPER_LEN_START;
    short int SWEEP_TAPER_LEN_END;
    short int TAPER_TYPE;
    short int CORRELATED;
    short int BINARY_GAIN;
    short int AMP_RECOR;
    short int MEASURE_SYSTEM;
    short int IMPULSE_POLAR;
    short int POLAR_CODE;
    //char UNNASSIGNED1 [240];
    short int SEGY_REV_NUM;
    short int FIXED_LEN;
    short int NUM_EXT_HEAD;
    //char UNNASSIGNED2 [94];

public:

  void store(char* arr);
  void write(ofstream& out);
  friend short int readvalue(char a, char b);
  friend int readvalue(char a, char b, char c, char d);
  friend ostream& operator << (ostream& s, BinaryHeader& b);
};

/* MEMBER FUNCTIONS */

//Write Object to text file
void BinaryHeader :: write(ofstream& out)
{
  out << *this;
}

//Store the values read to corresponding attribute of object
void BinaryHeader :: store(char* arr)
{
  JOB_ID = readvalue_i(arr, 0);
  LINE_NUM = readvalue_i(arr, 4);
  REEL_NUM = readvalue_i(arr, 8);
  NUM_OF_TRACE = readvalue_si(arr, 12);
  NUM_OF_AUX = readvalue_si(arr, 14);
  INTERVAL_MS = readvalue_si(arr, 16);
  INTERVAL_MS_ORI = readvalue_si(arr, 18);
  NUM_OF_SAMPLES = readvalue_si(arr, 20);
  NUM_OF_SAMPLES_ORI = readvalue_si(arr, 22);
  SAMPLE_FORMAT = readvalue_si(arr, 24);
  ENSEMBLE = readvalue_si(arr, 26);
  TRACE_SORT = readvalue_si(arr, 28);
  VERT_SUM = readvalue_si(arr, 30);
  SWEEP_FREQ_START = readvalue_si(arr, 32);
  SWEEP_FREQ_END = readvalue_si(arr, 34);
  SWEEP_LENGTH = readvalue_si(arr, 36);
  SWEEP_TYPE = readvalue_si(arr, 38);
  SWEEP_NUM_CHANNEL = readvalue_si(arr, 40);
  SWEEP_TAPER_LEN_START = readvalue_si(arr, 42);
  SWEEP_TAPER_LEN_END = readvalue_si(arr, 44);
  TAPER_TYPE = readvalue_si(arr, 46);
  CORRELATED = readvalue_si(arr, 48);
  BINARY_GAIN = readvalue_si(arr, 50);
  AMP_RECOR = readvalue_si(arr, 52);
  MEASURE_SYSTEM = readvalue_si(arr, 54);
  IMPULSE_POLAR = readvalue_si(arr, 56);
  POLAR_CODE = readvalue_si(arr, 58);
  SEGY_REV_NUM = readvalue_si(arr, 300);
  FIXED_LEN = readvalue_si(arr, 302);
  NUM_EXT_HEAD = readvalue_si(arr, 304);     
}

//Overload the stream << operator to write BINARY HEADER objects directly to file
ostream& operator << (ostream& s, BinaryHeader& b)
{
  s << "JOB_ID                :" << b.JOB_ID<< endl ;
  s << "LINE_NUM              :" << b.LINE_NUM<< endl ;
  s << "REEL_NUM              :" << b.REEL_NUM<< endl ;
  s << "NUM_OF_TRACE          :" << b.NUM_OF_TRACE<< endl ;
  s << "NUM_OF_AUX            :" << b.NUM_OF_AUX<< endl ;
  s << "INTERVAL_M            :" << b.INTERVAL_MS << endl ;
  s << "INTERVAL_MS_ORI       :" << b.INTERVAL_MS_ORI << endl ;
  s << "NUM_OF_SAMPLES_ORI    :" << b.NUM_OF_SAMPLES_ORI<< endl ;
  s << "SAMPLE_FORMAT         :" << b.SAMPLE_FORMAT << endl ;
  s << "ENSEMBLE              :" << b.ENSEMBLE<< endl ;
  s << "TRACE_SORT            :" << b.TRACE_SORT<< endl ;
  s << "VERT_SUM              :" << b.VERT_SUM<< endl ;
  s << "SWEEP_FREQ_START      :" << b.SWEEP_FREQ_START<< endl ;
  s << "SWEEP_FREQ_END        :" << b.SWEEP_FREQ_END<< endl ;
  s << "SWEEP_LENGTH          :" << b.SWEEP_LENGTH<< endl ;
  s << "SWEEP_TYPE            :" << b.SWEEP_TYPE<< endl ;
  s << "SWEEP_NUM_CHANNEL     :" << b.SWEEP_NUM_CHANNEL << endl ;
  s << "SWEEP_TAPER_LEN_START :" << b.SWEEP_TAPER_LEN_START << endl ;
  s << "SWEEP_TAPER_LEN_END   :" << b.SWEEP_TAPER_LEN_END << endl ;
  s << "TAPER_TYPE            :" << b.TAPER_TYPE<< endl ;
  s << "CORRELATED            :" << b.CORRELATED<< endl ;
  s << "BINARY_GAIN           :" << b.BINARY_GAIN << endl ;
  s << "AMP_RECOR             :" << b.AMP_RECOR << endl ;
  s << "MEASURE_SYSTEM        :" << b.MEASURE_SYSTEM<< endl ;
  s << "IMPULSE_POLAR         :" << b.IMPULSE_POLAR << endl ;
  s << "POLAR_CODE            :" << b.POLAR_CODE<< endl ;
  s << "SEGY_REV_NUM          :" << b.SEGY_REV_NUM<< endl ;
  s << "FIXED_LEN             :" << b.FIXED_LEN << endl ;
  s << "NUM_EXT_HEAD          :" << b.NUM_EXT_HEAD<< endl ;
  return s;
}