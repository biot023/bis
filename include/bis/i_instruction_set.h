#pragma once

#include "typedefs.h"

using namespace std;

namespace bis {

  struct IInstructionSet {
    static const shared_ptr<IInstructionSet> NULL_PTR;
    static const shared_ptr<const IInstructionSet> NULL_CPTR;
    virtual ~IInstructionSet() {}
  };
  const shared_ptr<IInstructionSet> IInstructionSet::NULL_PTR =
    shared_ptr<IInstructionSet>( 0 );
  const shared_ptr<const IInstructionSet> IInstructionSet::NULL_CPTR =
    shared_ptr<const IInstructionSet>( 0 );
}
