#include"formule.h"

formule::formule(){}
formule::formule(FORMULE_TYPE f){
  type=f;
  //lform=new vector<formule>();
}
formule::~formule(){
}
formule::FORMULE_TYPE formule::getType(){
  return type;
}
void formule::addform(formule f){
  if(type==NOT && lform.size()<1){
    lform.push_back(f);
  }else if (type==OP_BINAIRE && lform.size()<2){
    lform.push_back(f);
  }
}
void formule::print(){
  cout<<form;
}
void formule::printChildNodes(){
  if(type==NOT){
    cout<<"(";
    this->print();
    lform[0].printChildNodes();
    cout<<")";
  }else if (type==OP_BINAIRE){
    cout<<"(";
    lform[0].printChildNodes();
    this->print();
    lform[1].printChildNodes();
    cout<<")";
  }else if (type==VAR){
    this->print();
  }
}
string formule::toString(){}
