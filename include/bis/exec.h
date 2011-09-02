#pragma once

#include "typedefs.h"
#include "bis/i_exec.h"
#include "bis/bis_config.h"
#include "bis/i_instruction_set.h"

#include <memory>

using namespace std;

namespace bis {

  template <typename Biot, typename SensoryArray>
  class Exec : public IExec {
  public:
    Exec( shared_ptr<const Biot> biot,
          shared_ptr<const SensoryArray> sensory_array,
          shared_ptr<const BisConfig> config ) {}
    virtual ~Exec() {}

    virtual shared_ptr<const IInstructionSet> instruction_set() const {
      return dynamic_pointer_cast<const IInstructionSet>( _instruction_set ); }

  private:
    shared_ptr<IInstructionSet> _instruction_set;
  };
  
}
