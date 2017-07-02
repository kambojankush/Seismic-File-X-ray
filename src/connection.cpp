#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
/* uncomment for applications that use vectors */
/*#include <vector>*/

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define DEFAULT_HOST "tcp://127.0.0.1:3306"
#define DEFAULT_USER "root"
#define DEFAULT_PASS "random2486"
#define DEFAULT_DB "segy"

using namespace std;

int main(int argc, const char **argv)
{
  string url(argc >= 2 ? argv[1] : DEFAULT_HOST);
  const string user(argc >= 3 ? argv[2] : DEFAULT_USER);
  const string pass(argc >= 4 ? argv[3] : DEFAULT_PASS);
  const string database(argc >= 5 ? argv[4] : DEFAULT_DB);


  try {

    sql::Driver* driver = get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    //Initialize Database
    stmt->execute("CREATE DATABASE IF NOT EXISTS segy;");
    con->setSchema(database); 
    stmt->execute(" CREATE TABLE IF NOT EXISTS traceheaders("
                      
                  " `TRACE_SEQ_GLOBAL`  int, " 
                  " `TRACE_SEQ_LOCAL`  int, " 
                  " `ORI_RECORD_NUM`  int, " 
                  " `TRACE_NUM_FIELD`  int, " 
                  " `SOURCE_PO`  int, " 
                  " `ENSEMBLE_NUM`  int, " 
                  " `ENS_TRACE_NUM`  int, " 
                  " `DIST_CENT_RECV`  int, " 
                  " `RECV_GRP_ELEV`  int, " 
                  " `SURF_ELEV_SRC`  int, " 
                  " `SOURCE_DEPTH`  int, " 
                  " `DATUM_ELEV_RECV`  int, " 
                  " `DATUM_ELAV_SRC`  int, " 
                  " `WATER_DEPTH_SRC`  int, " 
                  " `WATER_DEPTH_GRP`  int, " 
                  " `SRC_COOR_X`  int, " 
                  " `SRC_COOR_Y`  int, " 
                  " `GRP_COOR_X`  int, " 
                  " `GRP_COOR_Y`  int, " 
                  " `ENS_COOR_X`  int, " 
                  " `ENS_COOR_Y`  int, " 
                  " `INLINE`  int, " 
                  " `CROSS`  int, " 
                  " `SHOOTPO`  int, " 
                  " `TRACE_CODE`  smallint, " 
                  " `NUM_VERT_SUM`  smallint, " 
                  " `NUM_HORZ_SUM`  smallint, " 
                  " `DATA_USE`  smallint, " 
                  " `SCALE_DEPTH`  smallint, " 
                  " `SCALE_COOR`  smallint, " 
                  " `COOR_UNIT`  smallint, " 
                  " `WEATHER_VEL`  smallint, " 
                  " `SWEATHER_VEL`  smallint, " 
                  " `UPHOLE_T_SRC`  smallint, " 
                  " `UPHOLE_T_GRP`  smallint, " 
                  " `SRC_STA_CORRC`  smallint, " 
                  " `GRP_STA_CORRC`  smallint, " 
                  " `TOTAL_STA`  smallint, " 
                  " `LAG_TIME_A`  smallint, " 
                  " `LAG_TIME_B`  smallint, " 
                  " `DELAY_T`  smallint, " 
                  " `MUTE_T_STRT`  smallint, " 
                  " `MUTE_T_END`  smallint, " 
                  " `GAIN_TYPE`  smallint, " 
                  " `GAIN_CONST`  smallint, " 
                  " `GAIN_INIT`  smallint, " 
                  " `CORRLTD`  smallint, " 
                  " `SWEEP_FREQ_START`  smallint, " 
                  " `SWEEP_FREQ_END`  smallint, " 
                  " `SWEEP_LENGTH`  smallint, " 
                  " `SWEEP_TYPE`  smallint, " 
                  " `SWEEP_TAPER_LEN_START`  smallint, " 
                  " `SWEEP_TAPER_LEN_END`  smallint, " 
                  " `TAPER_TYPE`  smallint, " 
                  " `ALIAS_FREQ`  smallint, " 
                  " `ALIAS_SLOPE`  smallint, " 
                  " `NOTCH_FREQ`  smallint, " 
                  " `NOTCH_SLOPE`  smallint, " 
                  " `LOWCUT_FREQ`  smallint, " 
                  " `HIGHCUT_FREQ`  smallint, " 
                  " `LOWCUT_SLOPE`  smallint, " 
                  " `HIGHCUT_SLOPE`  smallint, " 
                  " `YEAR`  smallint, " 
                  " `DAY`  smallint, " 
                  " `HOUR`  smallint, " 
                  " `MINUTE`  smallint, " 
                  " `SECOND`  smallint, " 
                  " `TIME_CODE`  smallint, " 
                  " `WEIGHT_FACT`  smallint, " 
                  " `GEOPHNE_ROLL`  smallint, " 
                  " `GEOPHNE_TRACE`  smallint, " 
                  " `GEOPHNE_LAST`  smallint, " 
                  " `GAP_SIZE`  smallint, " 
                  " `OVER_TRAVEL`  smallint, " 
                  " `SHOOTPOsmallint_SCALE`  smallint, " 
                  " `TRACE_UNIT`  smallint, " 
                  " `TRANSD_UNIT`  smallint, " 
                  " `TRACE_IDENT`  smallint, " 
                  " `SCALE_TIME`  smallint, " 
                  " `SRC_ORIENT`  smallint, " 
                  " `SRC_UNIT`  smallint, "
                  " `NUM_OF_SAMPL` SMALLINT unsigned, " 
                  " `SAMPLE_INTRVL` SMALLINT unsigned, "
                  " `SRC_DIRECTION` varchar(6), "
                  " `SRC_MEASUREMT` varchar(6), "
                  " `UNNASSIGNED1` varchar(6), " 
                  " `TRANSD_CONST` varchar(6) "
                  ") ");
    

  } catch (sql::SQLException &e) {
    /*
      MySQL Connector/C++ throws three different exceptions:

      - sql::MethodNotImplementedException (derived from sql::SQLException)
      - sql::InvalidArgumentException (derived from sql::SQLException)
      - sql::SQLException (derived from std::runtime_error)
    */
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    /* what() (derived from std::runtime_error) fetches error message */
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;

    return EXIT_FAILURE;
  }

  cout << "Done." << endl;
  return EXIT_SUCCESS;
}