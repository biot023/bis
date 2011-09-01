#pragma once

#include "typedefs.h"

#include <map>

using namespace std;

namespace bis {

  class BisConfig {
  public:
    enum class attr : uint {
        ActionStackSize,    // The size of the stack of actions
        MemorySize,         // The size of the memory array
        ParameterStackSize, // The size of the stack of parameters
        MaxFunctionOffset,  // The maximum value for an offset when calling a function
        EndFunctionRatioA,  // Used to build a ratio that defines whether an end function
        EndFunctionRatioB   //   is discarded or actually ends a sequence of instructions
    };
    typedef map<attr, uint> attrs;

    /**
     * There are a number of config parameters that have to come from the actor
     * that requires the instruction set and exec (the Biot):
     *   - Count of possible actions
     *   - Number of senses to go in the sensory array
     *   - The maximum indices for each sense in the sensory array
     */

    BisConfig();
    BisConfig( const attrs &_attrs );
    ~BisConfig() {}

    const uint action_stack_size()    const { return _action_stack_size; }
    const uint memory_size()          const { return _memory_size; }
    const uint parameter_stack_size() const { return _parameter_stack_size; }
    const uint max_function_offset()  const { return _max_function_offset; }
    const uint end_function_ratio_a() const { return _end_function_ratio_a; }
    const uint end_function_ratio_b() const { return _end_function_ratio_b; }

    void set_action_stack_size( const uint action_stack_size ) {
      _action_stack_size = action_stack_size; }
    void set_memory_size( const uint memory_size ) {
      _memory_size = memory_size; }
    void set_parameter_stack_size( const uint parameter_stack_size ) {
      _parameter_stack_size = parameter_stack_size; }
    void set_max_function_offset( const uint max_function_offset ) {
      _max_function_offset = max_function_offset; }
    void set_end_function_ratio_a( const uint end_function_ratio_a ) {
      _end_function_ratio_a = end_function_ratio_a; }
    void set_end_function_ratio_b( const uint end_function_ratio_b ) {
      _end_function_ratio_b = end_function_ratio_b; }
      
  private:
    uint
      _action_stack_size,
      _memory_size,
      _parameter_stack_size,
      _max_function_offset,
      _end_function_ratio_a,
      _end_function_ratio_b;
    void _set_defaults();
  };
  
}
