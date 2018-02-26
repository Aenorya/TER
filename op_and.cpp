#include "op_and.h"

op_and::op_and():
  op_binary(AND) {
  form = "/\\";
}
op_and::op_and(formule *ga,formule *dr):
  op_binary(AND,ga,dr){
  form="/\\";
}
op_and::~op_and(){}
