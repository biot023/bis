#pragma once

#include <vector>
#include <algorithm>

namespace stubs {

  class Biot {
  public:
    Biot( const uint action_count=8 )
      : _action_count( _action_count ) {
      _construct_genome( 1000 );
    }
    Biot( const uint action_count, const uint genome_length )
      : _action_count( action_count )
    {
      _construct_genome( genome_length );
    }
    
    const uint action_count() const { return _action_count; }
    vector<int>::const_iterator genome_cbegin() const { return _genome.cbegin(); }
    vector<int>::const_iterator genome_cend()   const { return _genome.cend(); }
    
  private:
    uint _action_count;
    vector<int> _genome;
    
    void _construct_genome( const uint length ) {
      std::uniform_int_distribution<int> gene_distribution( -1000, 1000 );
      std::mt19937 gene_engine;
      std::generate_n( std::back_inserter( _genome ),
                       length,
                       [ & ] { return gene_distribution( gene_engine ); } );
    }
  };


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
