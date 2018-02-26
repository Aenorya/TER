#include "op_equ.h"

op_equ::op_equ(): op_binary(EQU){
  form = "<->";
}
op_equ::~op_equ(){}
op_equ::op_equ(formule *ga,formule *dr):
  op_binary(EQU,ga,dr){
  form="<->";
}
