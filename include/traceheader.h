/************************************************************************************************************/
/*****************************************TRACE HEADER CLASS*************************************************/
/***************************Create object to read Trace Headers of a SEG-Y file******************************/

class TraceHeader
{
private:
  int TRACE_SEQ_GLOBAL;
  int TRACE_SEQ_LOCAL;
  int ORI_RECORD_NUM;
  int TRACE_NUM_FIELD;
  int SOURCE_POINT;
  int ENSEMBLE_NUM;
  int ENS_TRACE_NUM;
  int DIST_CENT_RECV;
  int RECV_GRP_ELEV;
  int SURF_ELEV_SRC;
  int SOURCE_DEPTH;
  int DATUM_ELEV_RECV;
  int DATUM_ELAV_SRC;
  int WATER_DEPTH_SRC;
  int WATER_DEPTH_GRP;
  int SRC_COOR_X;
  int SRC_COOR_Y;
  int GRP_COOR_X;
  int GRP_COOR_Y;
  int ENS_COOR_X;
  int ENS_COOR_Y;
  int INLINE;
  int CROSS;
  int SHOOTPOINT;
  short int TRACE_CODE;
  short int NUM_VERT_SUM;
  short int NUM_HORZ_SUM;
  short int DATA_USE;
  short int SCALE_DEPTH;
  short int SCALE_COOR;
  short int COOR_UNIT;
  short int WEATHER_VEL;
  short int SWEATHER_VEL;
  short int UPHOLE_T_SRC;
  short int UPHOLE_T_GRP;
  short int SRC_STA_CORRC;
  short int GRP_STA_CORRC;
  short int TOTAL_STA;
  short int LAG_TIME_A;
  short int LAG_TIME_B;
  short int DELAY_T;
  short int MUTE_T_STRT;
  short int MUTE_T_END;
  short int GAIN_TYPE;
  short int GAIN_CONST;
  short int GAIN_INIT;
  short int CORRLTD;
  short int SWEEP_FREQ_START;
  short int SWEEP_FREQ_END;
  short int SWEEP_LENGTH;
  short int SWEEP_TYPE;
  short int SWEEP_TAPER_LEN_START;
  short int SWEEP_TAPER_LEN_END;
  short int TAPER_TYPE;
  short int ALIAS_FREQ;
  short int ALIAS_SLOPE;
  short int NOTCH_FREQ;
  short int NOTCH_SLOPE;
  short int LOWCUT_FREQ;
  short int HIGHCUT_FREQ;
  short int LOWCUT_SLOPE;
  short int HIGHCUT_SLOPE;
  short int YEAR;
  short int DAY;
  short int HOUR;
  short int MINUTE;
  short int SECOND;
  short int TIME_CODE;
  short int WEIGHT_FACT;
  short int GEOPHNE_ROLL;
  short int GEOPHNE_TRACE;
  short int GEOPHNE_LAST;
  short int GAP_SIZE;
  short int OVER_TRAVEL;
  short int SHOOTPOINT_SCALE;
  short int TRACE_UNIT;
  short int TRANSD_UNIT;
  short int TRACE_IDENT;
  short int SCALE_TIME;
  short int SRC_ORIENT;
  short int SRC_UNIT;
  unsigned short int NUM_OF_SAMPL;
  unsigned short int SAMPLE_INTRVL;
  char SRC_DIRECTION [6];
  char SRC_MEASUREMT [6];
  char UNNASSIGNED1 [6];
  char TRANSD_CONST [6];

public:

  void store(char* );
  void write(ofstream& );
  unsigned short int get_numsampl(void);
  friend void write(ofstream& );
  friend short int readvalue_si(char*, int);
  friend int readvalue_i(char*, int);
  friend void readvalue_c(char*, char*, int, int);
  friend ostream& operator << (ostream& , TraceHeader& );

};

/*****************************************MEMBER FUNCTIONS***************************************************/

unsigned short int TraceHeader :: get_numsampl(void)
{
  return NUM_OF_SAMPL;
}

void TraceHeader :: write(ofstream& out_)
{
  out_ << *this;
}


void TraceHeader :: store(char* arr)
{
  TRACE_SEQ_GLOBAL = readvalue_i(arr,0);
  TRACE_SEQ_LOCAL = readvalue_i(arr,4);
  ORI_RECORD_NUM = readvalue_i(arr,8);
  TRACE_NUM_FIELD = readvalue_i(arr,12);
  SOURCE_POINT = readvalue_i(arr,16);
  ENSEMBLE_NUM = readvalue_i(arr,20);
  ENS_TRACE_NUM = readvalue_i(arr,24);
  DIST_CENT_RECV = readvalue_i(arr,36);
  RECV_GRP_ELEV = readvalue_i(arr,40);
  SURF_ELEV_SRC = readvalue_i(arr,44);
  SOURCE_DEPTH = readvalue_i(arr,48);
  DATUM_ELEV_RECV = readvalue_i(arr,52);
  DATUM_ELAV_SRC = readvalue_i(arr,56);
  WATER_DEPTH_SRC = readvalue_i(arr,60);
  WATER_DEPTH_GRP = readvalue_i(arr,64);
  SRC_COOR_X = readvalue_i(arr,72);
  SRC_COOR_Y = readvalue_i(arr,76);
  GRP_COOR_X = readvalue_i(arr,80);
  GRP_COOR_Y = readvalue_i(arr,84);
  ENS_COOR_X = readvalue_i(arr,180);
  ENS_COOR_Y = readvalue_i(arr,184);
  INLINE = readvalue_i(arr,188);
  CROSS = readvalue_i(arr,192);
  SHOOTPOINT = readvalue_i(arr,196);
  TRACE_CODE= readvalue_si(arr,28);
  NUM_VERT_SUM= readvalue_si(arr,30);
  NUM_HORZ_SUM= readvalue_si(arr,32);
  DATA_USE= readvalue_si(arr,34);
  SCALE_DEPTH= readvalue_si(arr,68);
  SCALE_COOR= readvalue_si(arr,70);
  COOR_UNIT= readvalue_si(arr,88);
  WEATHER_VEL= readvalue_si(arr,90);
  SWEATHER_VEL= readvalue_si(arr,92);
  UPHOLE_T_SRC= readvalue_si(arr,94);
  UPHOLE_T_GRP= readvalue_si(arr,96);
  SRC_STA_CORRC= readvalue_si(arr,98);
  GRP_STA_CORRC= readvalue_si(arr,100);
  TOTAL_STA= readvalue_si(arr,102);
  LAG_TIME_A= readvalue_si(arr,104);
  LAG_TIME_B= readvalue_si(arr,106);
  DELAY_T= readvalue_si(arr,108);
  MUTE_T_STRT= readvalue_si(arr,110);
  MUTE_T_END= readvalue_si(arr,112);
  GAIN_TYPE= readvalue_si(arr,118);
  GAIN_CONST= readvalue_si(arr,120);
  GAIN_INIT= readvalue_si(arr,122);
  CORRLTD= readvalue_si(arr,124);
  SWEEP_FREQ_START= readvalue_si(arr,126);
  SWEEP_FREQ_END= readvalue_si(arr,128);
  SWEEP_LENGTH= readvalue_si(arr,130);
  SWEEP_TYPE= readvalue_si(arr,132);
  SWEEP_TAPER_LEN_START= readvalue_si(arr,134);
  SWEEP_TAPER_LEN_END= readvalue_si(arr,136);
  TAPER_TYPE= readvalue_si(arr,138);
  ALIAS_FREQ= readvalue_si(arr,140);
  ALIAS_SLOPE= readvalue_si(arr,142);
  NOTCH_FREQ= readvalue_si(arr,144);
  NOTCH_SLOPE= readvalue_si(arr,146);
  LOWCUT_FREQ= readvalue_si(arr,148);
  HIGHCUT_FREQ= readvalue_si(arr,150);
  LOWCUT_SLOPE= readvalue_si(arr,152);
  HIGHCUT_SLOPE= readvalue_si(arr,154);
  YEAR= readvalue_si(arr,156);
  DAY= readvalue_si(arr,158);
  HOUR= readvalue_si(arr,160);
  MINUTE= readvalue_si(arr,162);
  SECOND= readvalue_si(arr,164);
  TIME_CODE= readvalue_si(arr,166);
  WEIGHT_FACT= readvalue_si(arr,168);
  GEOPHNE_ROLL= readvalue_si(arr,170);
  GEOPHNE_TRACE= readvalue_si(arr,172);
  GEOPHNE_LAST= readvalue_si(arr,174);
  GAP_SIZE= readvalue_si(arr,176);
  OVER_TRAVEL= readvalue_si(arr,178);
  SHOOTPOINT_SCALE= readvalue_si(arr,200);
  TRACE_UNIT= readvalue_si(arr,202);
  TRANSD_UNIT= readvalue_si(arr,210);
  TRACE_IDENT= readvalue_si(arr,212);
  SCALE_TIME= readvalue_si(arr,214);
  SRC_ORIENT= readvalue_si(arr,216);
  SRC_UNIT= readvalue_si(arr,230);
  NUM_OF_SAMPL= readvalue_si(arr,114);
  SAMPLE_INTRVL= readvalue_si(arr,116); 
  readvalue_c(SRC_DIRECTION, arr, 218, 6);
  readvalue_c(SRC_MEASUREMT, arr, 224, 6);
  readvalue_c(UNNASSIGNED1, arr, 232, 6);
  readvalue_c(TRANSD_CONST, arr, 204, 6);
}

//Overload the stream << operator to write TRACE HEADER objects directly to file
ostream& operator << (ostream& out_, TraceHeader& traceHeader_)
{
  out_ << traceHeader_.NUM_OF_SAMPL           << "," ;
  out_ << traceHeader_.TRACE_SEQ_GLOBAL       << "," ;
  out_ << traceHeader_.TRACE_SEQ_LOCAL        << "," ;
  out_ << traceHeader_.ORI_RECORD_NUM         << "," ;
  out_ << traceHeader_.TRACE_NUM_FIELD        << "," ;
  out_ << traceHeader_.SOURCE_POINT           << "," ;
  out_ << traceHeader_.ENSEMBLE_NUM           << "," ;
  out_ << traceHeader_.ENS_TRACE_NUM          << "," ;
  out_ << traceHeader_.TRACE_CODE             << "," ;
  out_ << traceHeader_.NUM_VERT_SUM           << "," ;
  out_ << traceHeader_.NUM_HORZ_SUM           << "," ;
  out_ << traceHeader_.DATA_USE               << "," ;
  out_ << traceHeader_.DIST_CENT_RECV         << "," ;
  out_ << traceHeader_.RECV_GRP_ELEV          << "," ;
  out_ << traceHeader_.SURF_ELEV_SRC          << "," ;
  out_ << traceHeader_.SOURCE_DEPTH           << "," ;
  out_ << traceHeader_.DATUM_ELEV_RECV        << "," ;
  out_ << traceHeader_.DATUM_ELAV_SRC         << "," ;
  out_ << traceHeader_.WATER_DEPTH_SRC        << "," ;
  out_ << traceHeader_.WATER_DEPTH_GRP        << "," ;
  out_ << traceHeader_.SCALE_DEPTH            << "," ;
  out_ << traceHeader_.SCALE_COOR             << "," ;
  out_ << traceHeader_.SRC_COOR_X             << "," ;
  out_ << traceHeader_.SRC_COOR_Y             << "," ;
  out_ << traceHeader_.GRP_COOR_X             << "," ;
  out_ << traceHeader_.GRP_COOR_Y             << "," ;
  out_ << traceHeader_.COOR_UNIT              << "," ;
  out_ << traceHeader_.WEATHER_VEL            << "," ;
  out_ << traceHeader_.SWEATHER_VEL           << "," ;
  out_ << traceHeader_.UPHOLE_T_SRC           << "," ;
  out_ << traceHeader_.UPHOLE_T_GRP           << "," ;
  out_ << traceHeader_.SRC_STA_CORRC          << "," ;
  out_ << traceHeader_.GRP_STA_CORRC          << "," ;
  out_ << traceHeader_.TOTAL_STA              << "," ;
  out_ << traceHeader_.LAG_TIME_A             << "," ;
  out_ << traceHeader_.LAG_TIME_B             << "," ;
  out_ << traceHeader_.DELAY_T                << "," ;
  out_ << traceHeader_.MUTE_T_STRT            << "," ;
  out_ << traceHeader_.MUTE_T_END             << "," ;
  out_ << traceHeader_.SAMPLE_INTRVL          << "," ;
  out_ << traceHeader_.GAIN_TYPE              << "," ;
  out_ << traceHeader_.GAIN_CONST             << "," ;
  out_ << traceHeader_.GAIN_INIT              << "," ;
  out_ << traceHeader_.CORRLTD                << "," ;
  out_ << traceHeader_.SWEEP_FREQ_START       << "," ;
  out_ << traceHeader_.SWEEP_FREQ_END         << "," ;
  out_ << traceHeader_.SWEEP_LENGTH           << "," ;
  out_ << traceHeader_.SWEEP_TYPE             << "," ;
  out_ << traceHeader_.SWEEP_TAPER_LEN_START  << "," ;
  out_ << traceHeader_.SWEEP_TAPER_LEN_END    << "," ;
  out_ << traceHeader_.TAPER_TYPE             << "," ;
  out_ << traceHeader_.ALIAS_FREQ             << "," ;
  out_ << traceHeader_.ALIAS_SLOPE            << "," ;
  out_ << traceHeader_.NOTCH_FREQ             << "," ;
  out_ << traceHeader_.NOTCH_SLOPE            << "," ;
  out_ << traceHeader_.LOWCUT_FREQ            << "," ;
  out_ << traceHeader_.HIGHCUT_FREQ           << "," ;
  out_ << traceHeader_.LOWCUT_SLOPE           << "," ;
  out_ << traceHeader_.HIGHCUT_SLOPE          << "," ;
  out_ << traceHeader_.YEAR                   << "," ;
  out_ << traceHeader_.DAY                    << "," ;
  out_ << traceHeader_.HOUR                   << "," ;
  out_ << traceHeader_.MINUTE                 << "," ;
  out_ << traceHeader_.SECOND                 << "," ;
  out_ << traceHeader_.TIME_CODE              << "," ;
  out_ << traceHeader_.WEIGHT_FACT            << "," ;
  out_ << traceHeader_.GEOPHNE_ROLL           << "," ;
  out_ << traceHeader_.GEOPHNE_TRACE          << "," ;
  out_ << traceHeader_.GEOPHNE_LAST           << "," ;
  out_ << traceHeader_.GAP_SIZE               << "," ;
  out_ << traceHeader_.OVER_TRAVEL            << "," ;
  out_ << traceHeader_.ENS_COOR_X             << "," ;
  out_ << traceHeader_.ENS_COOR_Y             << "," ;
  out_ << traceHeader_.INLINE                 << "," ;
  out_ << traceHeader_.CROSS                  << "," ;
  out_ << traceHeader_.SHOOTPOINT             << "," ;
  out_ << traceHeader_.SHOOTPOINT_SCALE       << "," ;
  out_ << traceHeader_.TRACE_UNIT             << "," ;
  out_ << traceHeader_.TRANSD_CONST           << "," ;
  out_ << traceHeader_.TRANSD_UNIT            << "," ;
  out_ << traceHeader_.TRACE_IDENT            << "," ;
  out_ << traceHeader_.SCALE_TIME             << "," ;
  out_ << traceHeader_.SRC_ORIENT             << "," ;
  out_ << traceHeader_.SRC_DIRECTION          << "," ;
  out_ << traceHeader_.SRC_MEASUREMT          << "," ;
  out_ << traceHeader_.SRC_UNIT               << "," ;
  out_ << traceHeader_.UNNASSIGNED1           << "," ;

  out_ << endl;

  return out_;
}