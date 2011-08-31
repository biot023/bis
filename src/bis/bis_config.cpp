#include "bis/bis_config.h"

#include <map>

namespace bis {

  BisConfig::BisConfig() {
    _set_defaults();
  }

  BisConfig::BisConfig( const attrs &_attrs ) {
    _set_defaults();
  }

  void BisConfig::_set_defaults() {
    _action_stack_size    =  16;
    _memory_size          = 256;
    _parameter_stack_size = 128;
    _max_function_offset  =  16;
    _end_function_ratio_a =   1;
    _end_function_ratio_b =   2;
  }
  
}
