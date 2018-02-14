#include"op_binary.h"

op_binary::op_binary(){}
op_binary::op_binary(OP_TYPE t){
  formule(OP_BINAIRE);
  op_type = t;
}
op_binary::~op_binary(){}
