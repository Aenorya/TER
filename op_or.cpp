#include "op_or.h"

op_or::op_or():
  op_binary(OR){
  form = "\\/";
}
op_or::~op_or(){}
op_or::op_or(formule *ga,formule *dr):
  op_binary(OR,ga,dr){
  form="\\/";
}
