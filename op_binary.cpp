#include "op_binary.h"


op_binary::op_binary(OP_TYPE t): formule() {
  op_type = t;
  type=OP_BINAIRE;
}


op_binary::~op_binary(){}
