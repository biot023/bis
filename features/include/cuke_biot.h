#pragma once

#include "typedefs.h"

#include <vector>
#include <algorithm>

using namespace std;

namespace cuke {

  class Biot {
  public:
    Biot( const uint genome_length, const uint action_count ) :
      _action_count( action_count )
    {
      std::uniform_int_distribution<int> gene_distribution( -1000, 1000 );
      std::mt19937 gene_engine;
      std::generate_n( std::back_inserter( _genome ),
                       genome_length,
                       [ & ] { return gene_distribution( gene_engine ); } );
    }
    const uint action_count() const { return _action_count; }
    vector<int>::const_iterator genome_cbegin() const { return _genome.cbegin(); }
    vector<int>::const_iterator genome_cend()   const { return _genome.cend(); }
  private:
    uint _action_count;
    vector<int> _genome;
  };

}
