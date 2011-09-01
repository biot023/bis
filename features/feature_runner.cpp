#include <iostream>
#include <sstream>
#include <string>

#include "typedefs.h"
#include "bis/bis_config.h"

#include "../features/include/cuke_biot.h"
#include "../features/include/cuke_sensory_array.h"

using namespace std;
using namespace bis;

struct bad_args_error {
  string message;
  bad_args_error( const string &_message ) : message( _message ) {}
};

int main( const int argc, const char *argv[] ) {
  try {
    if ( argc < 3 || argc % 2 == 0 )
      throw bad_args_error( "Not all required arguments were supplied" );
    string output_dir( "" );
    uint genome_size( 10000 );
    uint action_count( 8 );
    vector<uint> sense_index_counts { 128, 64, 32, 16, 8 };
    sptr<BisConfig>::t bis_config( new BisConfig() );
    
    // ----------------------------------------
    cout << "Done." << endl;
    return 0;
  } catch( bad_args_error &err ) {
    cout << "*** Bad arguments error:" << err.message << endl
         << "The feature runner is meant to be run with the following arguments:" << endl
         << "  --output-dir            <dirname> *" << endl
         << "  --genome-size           <size_t>" << endl
         << "  --action-count          <size_t>" << endl
         << "  --sense-index-counts    <size_t,size_t,...>" << endl
         << "  --action-stack-size     <size_t>" << endl
         << "  --memory-size           <size_t>" << endl
         << "  --parameter-stack-size  <size_t>" << endl
         << "  --max-function-offset-a <size_t>" << endl
         << "  --max-function-offset-b <size_t>" << endl
         << endl
         << "Starred (*) args are required." << endl
         << endl;
    return -1;
  } catch( ... ) {
    cout << "*** Unhandled error." << endl;
    throw;
  };
}
