#include <boost/test/unit_test.hpp>

#include "bis/exec.h"
#include "../test/stubs.h"

using namespace std;
using namespace bis;

typedef stubs::Biot Biot;
typedef stubs::SensoryArray SensoryArray;
typedef Exec<Biot, SensoryArray> TExec;

struct ExecTestFixture {
  shared_ptr<const Biot> biot;
  shared_ptr<const SensoryArray> sensory_array;
  shared_ptr<const BisConfig> bis_config;
  shared_ptr<TExec> exec;
};

BOOST_FIXTURE_TEST_CASE( generating_exec_test, ExecTestFixture ) {
  BOOST_CHECK_MESSAGE( false, "Pending" );
}
