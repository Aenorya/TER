#include "op_not.h"

op_not::op_not():
  formule(NOT){
  form = "!";
}
op_not::op_not(formule *s):
  formule(NOT){
  suiv=s;
  form="!";
}
op_not::~op_not(){}

formule* op_not::getSuiv(){
  return suiv;
}
void op_not::printChildNodes(){
  cout<<"(";
    this->print();
    suiv->printChildNodes();
    cout<<")";
}
