#include <boost/test/unit_test.hpp>

#include "bis/exec.h"
#include "bis/instruction_set.h"
#include "../test/stubs.h"

using namespace std;
using namespace bis;

typedef stubs::Biot Biot;
typedef stubs::SensoryArray SensoryArray;
typedef Exec<Biot, SensoryArray> TExec;
typedef InstructionSet<Biot, SensoryArray> TInstructionSet;

struct ExecTestFixture {
  shared_ptr<const Biot> biot;
  shared_ptr<const SensoryArray> sensory_array;
  shared_ptr<const BisConfig> config;
  shared_ptr<TExec> exec;

  shared_ptr<TExec> generate() {
    biot = shared_ptr<const Biot>( new Biot() );
    sensory_array = shared_ptr<const SensoryArray>( new SensoryArray() );
    config = shared_ptr<const BisConfig>( new BisConfig() );
    exec = shared_ptr<TExec>( new TExec( biot, sensory_array, config ) );
    return exec;
  }
  
};

BOOST_FIXTURE_TEST_CASE( generating_exec_test, ExecTestFixture ) {
  generate();

  /** It should initialise the instruction set */ {
    BOOST_CHECK( exec->instruction_set() != IInstructionSet::NULL_CPTR );
  }
  
}
