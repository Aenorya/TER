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
formule* formule::getG(){
  return this;
}
formule* formule::getD(){
  return this;
}
formule* formule::getSuiv(){
  return this;
}
void formule::printChildNodes(){}


