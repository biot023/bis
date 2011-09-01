#pragma once

#include "typedefs.h"

#include <vector>

using namespace std;

namespace cuke {

  class SensoryArray {
  public:
    SensoryArray( const vector<uint> &sensory_array_indices ) :
      _sensory_array_indices( sensory_array_indices ) {}
    const uint count_senses() const { return _sensory_array_indices.size(); }
    const uint count_sense_indices( const uint index ) { return _sensory_array_indices[index]; }
  private:
    vector<uint> _sensory_array_indices;
  };
  
}
