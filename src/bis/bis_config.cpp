#include "bis/bis_config.h"

#include <map>

namespace bis {

  BisConfig::BisConfig() {
    _set_defaults();
  }

  BisConfig::BisConfig( const attrs &_attrs ) {
    _set_defaults();
    for ( const auto &kv : _attrs ) {
      switch( kv.first ) {
        case ActionStackSize : _action_stack_size = kv.second; break;
        case MemorySize : _memory_size = kv.second; break;
        case ParameterStackSize : _parameter_stack_size = kv.second; break;
        case MaxFunctionOffset : _max_function_offset = kv.second; break;
        case EndFunctionRatioA : _end_function_ratio_a = kv.second; break;
        case EndFunctionRatioB : _end_function_ratio_b = kv.second; break;
      } // esac
    } // next kv
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
