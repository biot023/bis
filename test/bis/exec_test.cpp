#include <boost/test/unit_test.hpp>

#include "bis/exec.h"
#include "../test/stubs.h"

using namespace std;
using namespace bis;

typedef stubs::Biot biot_t;
typedef stubs::SensoryArray sensory_array_t;
typedef Exec<biot_t, sensory_array_t> exec_t;

struct ExecTestFixture {
  shared_ptr<const biot_t> biot;
  shared_ptr<const sensory_array_t> sensory_array;
  shared_ptr<const BisConfig> bis_config;
  shared_ptr<exec_t> exec;
};

BOOST_FIXTURE_TEST_CASE( generating_exec_test, ExecTestFixture ) {
  BOOST_CHECK_MESSAGE( false, "Pending" );
}
