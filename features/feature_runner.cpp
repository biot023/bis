#include <iostream>

#include "typedefs.h"
#include "bis/bis_config.h"

#include "../features/include/cuke_biot.h"

using namespace std;

struct bad_args_error {
  string message;
  bad_args_error( const string &_message ) : message( _message ) {}
};

int main( const int argc, const char *argv[] ) {
  try {
    
    cout << "Done." << endl;
    return 0;
  } catch( bad_args_error &err ) {
    cout << "*** Bad arguments error:" << err.message << endl
         << "The feature runner is meant to be run with the following arguments:" << endl
         << "  --output-dir            <dirname> *" << endl
         << "  --action-count          <size_t> *" << endl
         << "  --sense-index-counts    <size_t,size_t,...> *" << endl
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
