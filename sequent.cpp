#include "sequent.h"

sequent::sequent(vector<formule*> g ,vector<formule*> d){
  this->gauche=g;
  this->droite=d;
}

sequent::sequent(){}

sequent::~sequent(){}

sequent* sequent::ETdroit(){
  return this;
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
