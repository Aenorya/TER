#include "op_binary.h"


op_binary::op_binary(OP_TYPE t): formule() {
  op_type = t;
  type=OP_BINAIRE;
}

op_binary::op_binary(OP_TYPE t,formule *ga,formule *dr){
  op_type = t;
  type=OP_BINAIRE;
  g=ga;
  d=dr;
}

formule* op_binary::getG(){ return g;}
formule* op_binary::getD(){ return d;}
						    
void op_binary::printChildNodes(){
    cout<<"(";
    g->printChildNodes();
    this->print();
    d->printChildNodes();
      cout<<")";
}

op_binary::~op_binary(){}
