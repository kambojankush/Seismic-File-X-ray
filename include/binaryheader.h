/************************************************************************************************************/
/****************************************BINARY HEADER CLASS*************************************************/
/***************************Create object to read Binary Header of a SEG-Y file******************************/
struct data_int
{
  string description;
  int value;
};

struct data_short
{
  string description;
  short int value;
};

struct data_ushort
{
  string description;
  unsigned short int value;
};


class BinaryHeader
{
private:
  data_int JOB_ID;
  data_int LINE_NUM;
  data_int REEL_NUM;
  data_short NUM_OF_TRACE;
  data_short NUM_OF_AUX;
  data_short INTERVAL_MS;
  data_short INTERVAL_MS_ORI;
  data_ushort NUM_OF_SAMPLES;
  data_ushort NUM_OF_SAMPLES_ORI;
  data_short SAMPLE_FORMAT;
  data_short ENSEMBLE;
  data_short TRACE_SORT;
  data_short VERT_SUM;
  data_short SWEEP_FREQ_START;
  data_short SWEEP_FREQ_END;
  data_short SWEEP_LENGTH;
  data_short SWEEP_TYPE;
  data_short SWEEP_NUM_CHANNEL;
  data_short SWEEP_TAPER_LEN_START;
  data_short SWEEP_TAPER_LEN_END;
  data_short TAPER_TYPE;
  data_short CORRELATED;
  data_short BINARY_GAIN;
  data_short AMP_RECOR;
  data_short MEASURE_SYSTEM;
  data_short IMPULSE_POLAR;
  data_short POLAR_CODE;
  //char UNNASSIGNED1 [240];
  data_short SEGY_REV_NUM;
  data_short FIXED_LEN;
  data_short NUM_EXT_HEAD;
  //char UNNASSIGNED2 [94];

public:
  
  void set_desc(void);
  void store(char* );
  short int get_exthead(void);
  unsigned short int get_num_of_samples(void);
  void write(ofstream& );
  friend short int readvalue_si(char*, int);
  friend int readvalue_i(char*, int);
  friend void readvalue_c(char*, char*, int, int);
  friend ostream& operator << (ostream& , BinaryHeader& );
};

/*****************************************MEMBER FUNCTIONS***************************************************/

void BinaryHeader :: set_desc(void)
{
  JOB_ID.description = "Job identification number";
  LINE_NUM.description = "Line number. For 3-D poststack data, this will typically contain the in-line number";
  REEL_NUM.description = "Reel number";
  NUM_OF_TRACE.description = "Number of data traces per ensemble. Mandatory for prestack data";
  NUM_OF_AUX.description = "Number of auxiliary traces per ensemble. Mandatory for prestack data.";
  INTERVAL_MS.description = "Sample interval in microseconds (μs). Mandatory for all data types.";
  INTERVAL_MS_ORI.description = "Sample interval in microseconds (μs) of original field recording.";
  NUM_OF_SAMPLES.description = "Number of samples per data trace. Mandatory for all types of data."
                               "Note: The sample interval and number of samples in the Binary File Header"
                               "should be for the primary set of seismic data traces in the file";
  NUM_OF_SAMPLES_ORI.description = "Number of samples per data trace for original field recording.";
  SAMPLE_FORMAT.description = "Data sample format code. Mandatory for all data."
                              "1 = 4-byte IBM floating-point"
                              "2 = 4-byte, two's complement integer"
                              "3 = 2-byte, two's complement integer"
                              "4 = 4-byte fixed-point with gain (obsolete)"
                              "5 = 4-byte IEEE floating-point"
                              "6 = Not currently used"
                              "7 = Not currently used"
                              "8 = 1-byte, two's complement integer";
  ENSEMBLE.description = "Ensemble fold — The expected number of data traces per trace ensemble"
                         "(e.g. the CMP fold). Highly recommended for all types of data.";
  TRACE_SORT.description = "Trace sorting code (i.e. type of ensemble) :"
                           "-1 = Other (should be explained in user Extended Textual File Header stanza"
                           "0 = Unknown"
                           "1 = As recorded (no sorting)"
                           "2 = CDP ensemble"
                           "3 = Single fold continuous profile"
                           "4 = Horizontally stacked"
                           "5 = Common source point"
                           "6 = Common receiver point"
                           "7 = Common offset point"
                           "8 = Common mid-point"
                           "9 = Common conversion point"
                           "Highly recommended for all types of data.";
  VERT_SUM.description = "Vertical sum code:"
                         "1 = no sum,"
                         "2 = two sum,"
                         "...,"
                         "N = M-1 sum (M = 2 to 32,767)";
  SWEEP_FREQ_START.description = "Sweep frequency at start (Hz).";
  SWEEP_FREQ_END.description = "Sweep frequency at end (Hz).";
  SWEEP_LENGTH.description = "Sweep length (ms).";
  SWEEP_TYPE.description = "Sweep type code:"
                           "1 = linear"
                           "2 = parabolic"
                           "3 = exponential"
                           "4 = other";
  SWEEP_NUM_CHANNEL.description = "Trace number of sweep channel.";
  SWEEP_TAPER_LEN_START.description = "Sweep trace taper length in milliseconds at start if tapered (the taper starts at"
                                      "zero time and is effective for this length).";
  SWEEP_TAPER_LEN_END.description = "Sweep trace taper length in milliseconds at end (the ending taper starts at"
                                    "sweep length minus the taper length at end).";
  TAPER_TYPE.description = "Taper type:"
                           "1 = linear"
                           "2 = cos 2"
                           "3 = other";
  CORRELATED.description = "Correlated data traces:"
                           "1 = no"
                           "2 = yes";
  BINARY_GAIN.description = "Binary gain recovered:"
                            "1 = yes"
                            "2 = no";
  AMP_RECOR.description = "Amplitude recovery method:"
                          "1 = none"
                          "2 = spherical divergence"
                          "3 = AGC"
                          "4 = other";
  MEASURE_SYSTEM.description = "Measurement system: Highly recommended for all types of data. If Location"
                               "Data stanzas are included in the file, this entry must agree with the Location"
                               "Data stanza. If there is a disagreement, the last Location Data stanza is the"
                               "controlling authority."
                               "1 = Meters"
                               "2 = Feet";
  IMPULSE_POLAR.description = "Impulse signal polarity"
                              "1 = Increase in pressure or upward geophone case movement gives negative"
                              "number on tape."
                              "2 = Increase in pressure or upward geophone case movement gives positive"
                              "number on tape.";
  POLAR_CODE.description = "Vibratory polarity code:"
                           "Seismic signal lags pilot signal by:"
                           "1 = 337.5° to 22.5°"
                           "2 = 22.5° to 67.5°"
                           "3 = 67.5° to 112.5°"
                           "4 = 112.5° to 157.5°"
                           "5 = 157.5° to 202.5°"
                           "6 = 202.5° to 247.5°"
                           "7 = 247.5° to 292.5°"
                           "8 = 292.5° to 337.5°";
  SEGY_REV_NUM.description = "SEG Y Format Revision Number. This is a 16-bit unsigned value with a Q-"
                             "point between the first and second bytes. Thus for SEG Y Revision 1.0, as"
                             "defined in this document, this will be recorded as 0100 16 . This field is"
                             "mandatory for all versions of SEG Y, although a value of zero indicates"
                             "\'traditional\' SEG Y conforming to the 1975 standard.";
  FIXED_LEN.description = "Fixed length trace flag. A value of one indicates that all traces in this SEG Y"
                          "file are guaranteed to have the same sample interval and number of samples,"
                          "as specified in Textual File Header bytes 3217-3218 and 3221-3222. A value"
                          "of zero indicates that the length of the traces in the file may vary and the"
                          "number of samples in bytes 115-116 of the Trace Header must be examined to"
                          "determine the actual length of each trace. This field is mandatory for all"
                          "versions of SEG Y, although a value of zero indicates \'traditional\' SEG Y"
                          "conforming to the 1975 standard.";
  NUM_EXT_HEAD.description = "Number of 3200-byte, Extended Textual File Header records following the"
                             "Binary Header. A value of zero indicates there are no Extended Textual File"
                             "Header records (i.e. this file has no Extended Textual File Header(s)). A value";
}

unsigned short int BinaryHeader :: get_num_of_samples(void)
{
  return NUM_OF_SAMPLES.value;
}
short int BinaryHeader :: get_exthead(void)
{
    return NUM_EXT_HEAD.value;
}
//Write Object to text file
void BinaryHeader :: write(ofstream& out_)
{
  out_ << *this;
}

//Store the values read to corresponding attribute of object
void BinaryHeader :: store(char* arr)
{
  set_desc();
  JOB_ID.value = readvalue_i(arr, 0);
  LINE_NUM.value = readvalue_i(arr, 4);
  REEL_NUM.value = readvalue_i(arr, 8);
  NUM_OF_TRACE.value = readvalue_si(arr, 12);
  NUM_OF_AUX.value = readvalue_si(arr, 14);
  INTERVAL_MS.value = readvalue_si(arr, 16);
  INTERVAL_MS_ORI.value = readvalue_si(arr, 18);
  NUM_OF_SAMPLES.value = readvalue_si(arr, 20);
  NUM_OF_SAMPLES_ORI.value = readvalue_si(arr, 22);
  SAMPLE_FORMAT.value = readvalue_si(arr, 24);
  ENSEMBLE.value = readvalue_si(arr, 26);
  TRACE_SORT.value = readvalue_si(arr, 28);
  VERT_SUM.value = readvalue_si(arr, 30);
  SWEEP_FREQ_START.value = readvalue_si(arr, 32);
  SWEEP_FREQ_END.value = readvalue_si(arr, 34);
  SWEEP_LENGTH.value = readvalue_si(arr, 36);
  SWEEP_TYPE.value = readvalue_si(arr, 38);
  SWEEP_NUM_CHANNEL.value = readvalue_si(arr, 40);
  SWEEP_TAPER_LEN_START.value = readvalue_si(arr, 42);
  SWEEP_TAPER_LEN_END.value = readvalue_si(arr, 44);
  TAPER_TYPE.value = readvalue_si(arr, 46);
  CORRELATED.value = readvalue_si(arr, 48);
  BINARY_GAIN.value = readvalue_si(arr, 50);
  AMP_RECOR.value = readvalue_si(arr, 52);
  MEASURE_SYSTEM.value = readvalue_si(arr, 54);
  IMPULSE_POLAR.value = readvalue_si(arr, 56);
  POLAR_CODE.value = readvalue_si(arr, 58);
  SEGY_REV_NUM.value = readvalue_si(arr, 300);
  FIXED_LEN.value = readvalue_si(arr, 302);
  NUM_EXT_HEAD.value = readvalue_si(arr, 304);

}

//Overload the stream << operator to write BINARY HEADER objects directly to file
ostream& operator << (ostream& out_, BinaryHeader& binaryHeader_)
{
  out_ << "JOB_ID                :" << binaryHeader_.JOB_ID.value                << endl ;
  out_ << "LINE_NUM              :" << binaryHeader_.LINE_NUM.value              << endl ;
  out_ << "REEL_NUM              :" << binaryHeader_.REEL_NUM.value              << endl ;
  out_ << "NUM_OF_TRACE          :" << binaryHeader_.NUM_OF_TRACE.value          << endl ;
  out_ << "NUM_OF_AUX            :" << binaryHeader_.NUM_OF_AUX.value            << endl ;
  out_ << "INTERVAL_M            :" << binaryHeader_.INTERVAL_MS.value           << endl ;
  out_ << "INTERVAL_MS_ORI       :" << binaryHeader_.INTERVAL_MS_ORI.value       << endl ;
  out_ << "NUM_OF_SAMPLES        :" << binaryHeader_.NUM_OF_SAMPLES.value        << endl ;
  out_ << "NUM_OF_SAMPLES_ORI    :" << binaryHeader_.NUM_OF_SAMPLES_ORI.value    << endl ;
  out_ << "SAMPLE_FORMAT         :" << binaryHeader_.SAMPLE_FORMAT.value         << endl ;
  out_ << "ENSEMBLE              :" << binaryHeader_.ENSEMBLE.value              << endl ;
  out_ << "TRACE_SORT            :" << binaryHeader_.TRACE_SORT.value            << endl ;
  out_ << "VERT_SUM              :" << binaryHeader_.VERT_SUM.value              << endl ;
  out_ << "SWEEP_FREQ_START      :" << binaryHeader_.SWEEP_FREQ_START.value      << endl ;
  out_ << "SWEEP_FREQ_END        :" << binaryHeader_.SWEEP_FREQ_END.value        << endl ;
  out_ << "SWEEP_LENGTH          :" << binaryHeader_.SWEEP_LENGTH.value          << endl ;
  out_ << "SWEEP_TYPE            :" << binaryHeader_.SWEEP_TYPE.value            << endl ;
  out_ << "SWEEP_NUM_CHANNEL     :" << binaryHeader_.SWEEP_NUM_CHANNEL.value     << endl ;
  out_ << "SWEEP_TAPER_LEN_START :" << binaryHeader_.SWEEP_TAPER_LEN_START.value << endl ;
  out_ << "SWEEP_TAPER_LEN_END   :" << binaryHeader_.SWEEP_TAPER_LEN_END.value   << endl ;
  out_ << "TAPER_TYPE            :" << binaryHeader_.TAPER_TYPE.value            << endl ;
  out_ << "CORRELATED            :" << binaryHeader_.CORRELATED.value            << endl ;
  out_ << "BINARY_GAIN           :" << binaryHeader_.BINARY_GAIN.value           << endl ;
  out_ << "AMP_RECOR             :" << binaryHeader_.AMP_RECOR.value             << endl ;
  out_ << "MEASURE_SYSTEM        :" << binaryHeader_.MEASURE_SYSTEM.value        << endl ;
  out_ << "IMPULSE_POLAR         :" << binaryHeader_.IMPULSE_POLAR.value         << endl ;
  out_ << "POLAR_CODE            :" << binaryHeader_.POLAR_CODE.value            << endl ;
  out_ << "SEGY_REV_NUM          :" << binaryHeader_.SEGY_REV_NUM.value          << endl ;
  out_ << "FIXED_LEN             :" << binaryHeader_.FIXED_LEN.value             << endl ;
  out_ << "NUM_EXT_HEAD          :" << binaryHeader_.NUM_EXT_HEAD.value          << endl ;
  return out_;
}