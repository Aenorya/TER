#include "var.h"

var::var(string s):  formule(VAR){
  form = s;
}
var::~var(){}

void var::printChildNodes(){
  this->print();
}
