#include <boost/test/unit_test.hpp>

#include "typedefs.h"
#include "bis/bis_config.h"

using namespace std;
using namespace bis;

struct BisConfigTestFixture {
  sptr<const BisConfig>::t bis_config;
  uint val, val2;

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
    BOOST_CHECK_EQUAL( static_cast<uint>(  16 ),bis_config->action_stack_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>( 256 ), bis_config->memory_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>( 128 ), bis_config->parameter_stack_size() );
    BOOST_CHECK_EQUAL( static_cast<uint>(  16 ),bis_config->max_function_offset() );
    BOOST_CHECK_EQUAL( static_cast<uint>(   1 ), bis_config->end_function_ratio_a() );
    BOOST_CHECK_EQUAL( static_cast<uint>(   2 ), bis_config->end_function_ratio_b() );
  }
  
}
