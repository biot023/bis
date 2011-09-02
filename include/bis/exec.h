#pragma once

#include "typedefs.h"
#include "bis/i_exec.h"
#include "bis/bis_config.h"

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

  private:
  };
  
}
