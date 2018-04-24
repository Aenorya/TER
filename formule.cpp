#include"formule.h"
#include "op_binary.h"

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

string formule::getform(){
	return form;
}

bool formule::equal(formule *f){
	
	if(this->getType()!=f->getType()){
		return false;
	}else{
//cout<< this->getform() << " =? "<< f->getform() << " : " <<(this->getform() == f->getform())<<endl;
		if(this->getType()==formule::VAR){
				
			return (this->getform() == f->getform());
		}else if(this->getType()==formule::NOT){
			return ((this->getSuiv())->equal(f->getSuiv()));
		}else{
			if(((op_binary*)this)->getOptype() == ((op_binary*)f)->getOptype()){
				return ((this->getG())->equal(f->getG())) && ((this->getD())->equal(f->getD()));
			}else{
				return false;
			}		
		}
	}
}
