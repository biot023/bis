#pragma once

#include "typedefs.h"

using namespace std;

namespace bis {

  class IInstructionSet;

  struct IExec {
    virtual ~IExec() {}
    virtual shared_ptr<const IInstructionSet> instruction_set() const = 0;
  };
  
}
