#include <boost/test/unit_test.hpp>

#include "typedefs.h"
#include "bis/bis_config.h"

using namespace std;
using namespace bis;

struct BisConfigTestFixture {
  sptr<const BisConfig>::t bis_config;

  sptr<const BisConfig>::t do_call() {
    bis_config = sptr<const BisConfig>::t( new BisConfig() );
    return bis_config;
  }

  sptr<const BisConfig>::t do_call( const BisConfig::attrs &_attrs ) {
    bis_config = sptr<const BisConfig>::t( new BisConfig( _attrs ) );
    return bis_config;
  }
};

BOOST_FIXTURE_TEST_CASE( bis_config_test, BisConfigTestFixture ) {

  /** It should provide defaults for each config attribute */ {
    do_call();
    BOOST_CHECK_EQUAL( static_cast<uint>(  16 ), bis_config->action_stack_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>( 256 ), bis_config->memory_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>( 128 ), bis_config->parameter_stack_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>(  16 ), bis_config->max_function_offset() );
    BOOST_CHECK_EQUAL( static_cast<uint>(   1 ), bis_config->end_function_ratio_a() );
    BOOST_CHECK_EQUAL( static_cast<uint>(   2 ), bis_config->end_function_ratio_b() );
  }

  /** It should set the action stack size attr if specified */ {
    uint val( 32 );
    do_call( BisConfig::attrs { { BisConfig::attr::ActionStackSize, val } } );
    BOOST_CHECK_EQUAL( val, bis_config->action_stack_size() );;
  }

  /** It should set the memory size attr if specified */ {
    uint val( 64 );
    do_call( BisConfig::attrs { { BisConfig::attr::MemorySize, val } } );
    BOOST_CHECK_EQUAL( val, bis_config->memory_size() );
  }

  /** It should set the parameter stack size attr if specified */ {
    uint val( 64 );
    do_call( BisConfig::attrs { { BisConfig::attr::ParameterStackSize, val } } );
    BOOST_CHECK_EQUAL( val, bis_config->parameter_stack_size() );
  }

  /** It should set the max function offset attr if specified */ {
    uint val( 8 );
    do_call( BisConfig::attrs { { BisConfig::attr::MaxFunctionOffset, val } } );
    BOOST_CHECK_EQUAL( val, bis_config->max_function_offset() );
  }

  /** It should set the end function ratio attributes if specified */ {
    uint val1( 3 ); uint val2( 7 );
    do_call( BisConfig::attrs { { BisConfig::attr::EndFunctionRatioA, val1 },
                                { BisConfig::attr::EndFunctionRatioB, val2 } } );
    BOOST_CHECK_EQUAL( val1, bis_config->end_function_ratio_a() );
    BOOST_CHECK_EQUAL( val2, bis_config->end_function_ratio_b() );
  }
  
}
