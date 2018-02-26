#include "op_imp.h"

op_imp::op_imp():  op_binary(IMP){
  form = "->";
}
op_imp::op_imp(formule *ga,formule *dr):
  op_binary(IMP,ga,dr){
  form="->";
}
op_imp::~op_imp(){}
