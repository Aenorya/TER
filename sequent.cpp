#include "sequent.h"
#include "op_binary.h"
sequent::sequent(vector<formule*> g ,vector<formule*> d){
  this->gauche=g;
  this->droite=d;
}

sequent::sequent(){}

sequent::~sequent(){}

sequent* sequent::ETgauche(){
  int i =0;
  bool b=true;
  while(i<gauche.size() && b){
    if(gauche[i]->getType()==OP_BINAIRE){
      if((op_binary)gauche[i]->getOptype()==AND){
	b=false;
      }
    }else{
      i++;
    }
  }
  if(!b){
    vector<formule*> ng;
    for(int j = 0;j<gauche.size();j++){
      if(j!=i){
	ng.push_back(gauche[j]);
      }else{
	ng.push_back((op_binary)gauche[i]->getG());
	ng.push_back((op_binary)gauche[i]->getD());
      }
    }
    return new sequent(ng,droite);
  }else{
    return this;
  }
}

void sequent::affiche(){
  for(int i = 0;i<gauche.size();i++){
    gauche[i]->printChildNodes();
    if(i != gauche.size() - 1){
      cout<<" , ";
    }
  }
  cout << " |-- ";
  for(int i = 0;i<droite.size();i++){
    droite[i]->printChildNodes();
    if(i != droite.size() - 1){
      cout<<" , ";
    }else{
      cout<<endl;
    }
  }
}
