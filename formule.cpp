#include"formule.h"

formule::formule(){}
formule::formule(FORMULE_TYPE f){
  type=f;
}
formule::~formule(){
}
formule::FORMULE_TYPE formule::getType(){
  return type;
}
void formule::print(){
  cout<<form;
}

void formule::printChildNodes(){}
