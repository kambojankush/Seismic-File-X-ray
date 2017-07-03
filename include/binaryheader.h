/************************************************************************************************************/
/****************************************BINARY HEADER CLASS*************************************************/
/***************************Create object to read Binary Header of a SEG-Y file******************************/

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

  void store(char* );
  short int get_exthead(void);
  void write(ofstream& );
  friend short int readvalue_si(char*, int);
  friend int readvalue_i(char*, int);
  friend void readvalue_c(char*, char*, int, int);
  friend ostream& operator << (ostream& , BinaryHeader& );
};

/*****************************************MEMBER FUNCTIONS***************************************************/


short int BinaryHeader :: get_exthead(void)
{
    return NUM_EXT_HEAD;
}
//Write Object to text file
void BinaryHeader :: write(ofstream& out_)
{
  out_ << *this;
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
ostream& operator << (ostream& out_, BinaryHeader& binaryHeader_)
{
  out_ << "JOB_ID                :" << binaryHeader_.JOB_ID                << endl ;
  out_ << "LINE_NUM              :" << binaryHeader_.LINE_NUM              << endl ;
  out_ << "REEL_NUM              :" << binaryHeader_.REEL_NUM              << endl ;
  out_ << "NUM_OF_TRACE          :" << binaryHeader_.NUM_OF_TRACE          << endl ;
  out_ << "NUM_OF_AUX            :" << binaryHeader_.NUM_OF_AUX            << endl ;
  out_ << "INTERVAL_M            :" << binaryHeader_.INTERVAL_MS           << endl ;
  out_ << "INTERVAL_MS_ORI       :" << binaryHeader_.INTERVAL_MS_ORI       << endl ;
  out_ << "NUM_OF_SAMPLES_ORI    :" << binaryHeader_.NUM_OF_SAMPLES_ORI    << endl ;
  out_ << "SAMPLE_FORMAT         :" << binaryHeader_.SAMPLE_FORMAT         << endl ;
  out_ << "ENSEMBLE              :" << binaryHeader_.ENSEMBLE              << endl ;
  out_ << "TRACE_SORT            :" << binaryHeader_.TRACE_SORT            << endl ;
  out_ << "VERT_SUM              :" << binaryHeader_.VERT_SUM              << endl ;
  out_ << "SWEEP_FREQ_START      :" << binaryHeader_.SWEEP_FREQ_START      << endl ;
  out_ << "SWEEP_FREQ_END        :" << binaryHeader_.SWEEP_FREQ_END        << endl ;
  out_ << "SWEEP_LENGTH          :" << binaryHeader_.SWEEP_LENGTH          << endl ;
  out_ << "SWEEP_TYPE            :" << binaryHeader_.SWEEP_TYPE            << endl ;
  out_ << "SWEEP_NUM_CHANNEL     :" << binaryHeader_.SWEEP_NUM_CHANNEL     << endl ;
  out_ << "SWEEP_TAPER_LEN_START :" << binaryHeader_.SWEEP_TAPER_LEN_START << endl ;
  out_ << "SWEEP_TAPER_LEN_END   :" << binaryHeader_.SWEEP_TAPER_LEN_END   << endl ;
  out_ << "TAPER_TYPE            :" << binaryHeader_.TAPER_TYPE            << endl ;
  out_ << "CORRELATED            :" << binaryHeader_.CORRELATED            << endl ;
  out_ << "BINARY_GAIN           :" << binaryHeader_.BINARY_GAIN           << endl ;
  out_ << "AMP_RECOR             :" << binaryHeader_.AMP_RECOR             << endl ;
  out_ << "MEASURE_SYSTEM        :" << binaryHeader_.MEASURE_SYSTEM        << endl ;
  out_ << "IMPULSE_POLAR         :" << binaryHeader_.IMPULSE_POLAR         << endl ;
  out_ << "POLAR_CODE            :" << binaryHeader_.POLAR_CODE            << endl ;
  out_ << "SEGY_REV_NUM          :" << binaryHeader_.SEGY_REV_NUM          << endl ;
  out_ << "FIXED_LEN             :" << binaryHeader_.FIXED_LEN             << endl ;
  out_ << "NUM_EXT_HEAD          :" << binaryHeader_.NUM_EXT_HEAD          << endl ;
  
  return out_;
}