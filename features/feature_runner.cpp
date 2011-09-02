#include <iostream>
#include <sstream>
#include <string>
#include <boost/algorithm/string.hpp>

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
    sptr<BisConfig>::t mutable_bis_config( new BisConfig() );
    for ( int i = 1 ; i < argc ; i += 2 ) {
      const string key( argv[i] );
      if ( key == "--output-dir" ) {
        output_dir = argv[i + 1];
      } else if ( key == "--sense-index-counts" ) {
        sense_index_counts.clear();
        vector<string> count_strings;
        boost::split( count_strings, argv[i + 1], boost::is_any_of( "," ) );
        for ( const auto &count_string : count_strings ) {
          sense_index_counts.push_back( atoi( count_string.c_str() ) );
        } // next count_string
      } else {
        uint val = atoi( argv[i + 1] );
        if ( key == "--genome-size" ) {
          genome_size = val;
        } else if ( key == "--action-count" ) {
          action_count = val;
        } else if ( key == "--action-stack-size" ) {
          mutable_bis_config->set_action_stack_size( val );
        } else if ( key == "--memory-size" ) {
          mutable_bis_config->set_memory_size( val );
        } else if ( key == "--parameter-stack-size" ) {
          mutable_bis_config->set_parameter_stack_size( val );
        } else if ( key == "--max-function-offset" ) {
          mutable_bis_config->set_max_function_offset( val );
        } else if ( key == "--end-function-ratio-a" ) {
          mutable_bis_config->set_end_function_ratio_a( val );
        } else if ( key == "--end-function-ratio-b" ) {
          mutable_bis_config->set_end_function_ratio_b( val );
        } else {
          stringstream buf;
          buf << "Unknown argument: " << key << " " << argv[i + 1];
          throw bad_args_error( buf.str() );
        } // fi
      } // fi
    } // next i
    sptr<const cuke::Biot>::t biot
      ( new cuke::Biot( genome_size, action_count ) );
    sptr<const cuke::SensoryArray>::t sensory_array
      ( new cuke::SensoryArray( sense_index_counts ) );
    sptr<const BisConfig>::t bis_config
      ( dynamic_pointer_cast<const BisConfig>( mutable_bis_config ) );
    
    // ----------------------------------------
    cout << "Done." << endl;
    return 0;
  } catch( bad_args_error &err ) {
    cout << "*** Bad arguments error:" << err.message << endl
         << "The feature runner is meant to be run with the following arguments:" << endl
         << "  --output-dir           <dirname> *" << endl
         << "  --genome-size          <size_t>" << endl
         << "  --action-count         <size_t>" << endl
         << "  --sense-index-counts   <size_t,size_t,...>" << endl
         << "  --action-stack-size    <size_t>" << endl
         << "  --memory-size          <size_t>" << endl
         << "  --parameter-stack-size <size_t>" << endl
         << "  --max-function-offset  <size_t>" << endl
         << "  --end-function-ratio-a <size_t>" << endl
         << "  --end-function-ratio-b <size_t>" << endl
         << endl
         << "Starred (*) args are required." << endl
         << endl;
    return -1;
  } catch( ... ) {
    cout << "*** Unhandled error." << endl;
    throw;
  };
}
