#pragma once

#include "typedefs.h"

using namespace std;

namespace bis {

  class IInstructionSet;

  struct IExec {
    static const shared_ptr<IExec> NULL_PTR;
    static const shared_ptr<const IExec> NULL_CPTR;
    
    virtual ~IExec() {}
    virtual shared_ptr<const IInstructionSet> instruction_set() const = 0;
  };
  const shared_ptr<IExec> IExec::NULL_PTR = shared_ptr<IExec>( 0 );
  const shared_ptr<const IExec> IExec::NULL_CPTR = shared_ptr<const IExec>( 0 );
  
}
