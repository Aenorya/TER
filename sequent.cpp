#include "sequent.h"
#include "op_binary.h"
sequent::sequent(vector<formule*> g ,vector<formule*> d){
  this->gauche=g;
  this->droite=d;
}

sequent::sequent(){}

sequent::~sequent(){}

vector<sequent*> sequent::ETgauche(int i){
    vector<formule*> ng;
    for(int j = 0;j<gauche.size();j++){
      if(j!=i){
	ng.push_back(gauche[j]);
      }else{
	ng.push_back(gauche[i]->getG());
	ng.push_back(gauche[i]->getD());
      }
    }
    vector<sequent*> v;
    v.push_back(new sequent(ng,droite));
    return v;
}


vector<sequent*> sequent::ETdroit(int i){
    vector<formule*> nd1;
    vector<formule*> nd2;
    for(int j = 0;j<droite.size();j++){
      if(j!=i){
	nd1.push_back(droite[j]);
	nd2.push_back(droite[j]);
      }else{
	nd1.push_back(droite[i]->getG());
	nd2.push_back(droite[i]->getD());
      }
    }
    vector<sequent*> v;
    v.push_back(new sequent(gauche,nd1));
    v.push_back(new sequent(gauche,nd2));
    return v;
}

vector<sequent*> sequent::OUgauche(int i){
    vector<formule*> ng1;
    vector<formule*> ng2;
    for(int j = 0;j<gauche.size();j++){
      if(j!=i){
	ng1.push_back(gauche[j]);
	ng2.push_back(gauche[j]);
      }else{
	ng1.push_back(gauche[i]->getG());
	ng2.push_back(gauche[i]->getD());
      }
    }
    vector<sequent*> v;
    v.push_back(new sequent(ng1,droite));
    v.push_back(new sequent(ng2,droite));
    return v;
}

vector<sequent*> sequent::OUdroit(int i){
    vector<formule*> ng;
    for(int j = 0;j<droite.size();j++){
      if(j!=i){
	ng.push_back(droite[j]);
      }else{
	ng.push_back(droite[i]->getG());
	ng.push_back(droite[i]->getD());
      }
    }
    vector<sequent*> v;
    v.push_back(new sequent(gauche,ng));
    return v;
}

vector<sequent*> sequent::NOTgauche(int i){
  
    vector<formule*> ng;
    vector<formule*> nd;
    for(int j = 0;j<gauche.size();j++){
      if(i!=j){
	ng.push_back(gauche[j]);
      }
    }
    for(int j=0;j<droite.size();j++){
      nd.push_back(droite[j]);
    }
    nd.push_back(gauche[i]->getSuiv());
      vector<sequent*> v;
    v.push_back(new sequent(ng,nd));
    return v;
}


vector<sequent*> sequent::NOTdroit(int i){
    vector<formule*> ng;
    vector<formule*> nd;
    for(int j = 0;j<droite.size();j++){
      if(i!=j){
	ng.push_back(droite[j]);
      }
    }
    for(int j=0;j<gauche.size();j++){
      nd.push_back(gauche[j]);
    }
    nd.push_back(droite[i]->getSuiv());
      vector<sequent*> v;
    v.push_back(new sequent(nd,ng));
    return v;
}

vector<sequent*> sequent::IMPdroit(int i){
    vector<formule*> ng;
    vector<formule*> nd;
    for(int j = 0;j<droite.size();j++){
      if(i!=j){
	ng.push_back(droite[j]);
      }else{
	ng.push_back(droite[j]->getD());
      }
    }
    for(int j=0;j<gauche.size();j++){
      nd.push_back(gauche[j]);
    }
    nd.push_back(droite[i]->getG());
      vector<sequent*> v;
    v.push_back(new sequent(nd,ng));
    return v;
}

vector<sequent*> sequent::IMPgauche(int i){
    vector<formule*> ng;
    vector<formule*> nd;
    vector<sequent*> v;
    for(int j = 0;j<gauche.size();j++){
      if(i!=j){
	ng.push_back(gauche[j]);
      }else{
	ng.push_back(gauche[j]->getD());
      }
    }
    
    for(int j = 0;j<droite.size();j++){
      nd.push_back(droite[j]);
    }
    nd.push_back(gauche[i]->getG());

    v.push_back(new sequent(gauche,nd));
    v.push_back(new sequent(ng,droite));
    return v;
}

vector<sequent*> sequent::EQUgauche1(int i){
vector<formule*> ng;
    vector<formule*> nd;
    vector<sequent*> v;
    for(int j = 0;j<gauche.size();j++){
      if(i!=j){
	ng.push_back(gauche[j]);
      }else{
	ng.push_back(gauche[j]->getD());
      }
    }
    
    for(int j = 0;j<droite.size();j++){
      nd.push_back(droite[j]);
    }
    nd.push_back(gauche[i]->getG());

    v.push_back(new sequent(gauche,nd));
    v.push_back(new sequent(ng,droite));
    return v;
}


vector<sequent*> sequent::EQUgauche2(int i){
vector<formule*> ng;
    vector<formule*> nd;
    vector<sequent*> v;
    for(int j = 0;j<gauche.size();j++){
      if(i!=j){
	ng.push_back(gauche[j]);
      }else{
	ng.push_back(gauche[j]->getG());
      }
    }
    
    for(int j = 0;j<droite.size();j++){
      nd.push_back(droite[j]);
    }
    nd.push_back(gauche[i]->getD());

    v.push_back(new sequent(gauche,nd));
    v.push_back(new sequent(ng,droite));
    return v;
}

vector<sequent*> sequent::EQUdroit(int i){
  vector<formule*> ng;
  vector<formule*> nd;
  vector<sequent*> v;
    
  for(int j = 0;j<droite.size();j++){
    if(i!=j){
      ng.push_back(droite[j]);
    }else{
      ng.push_back(droite[j]->getD());
    }
  }
  for(int j=0;j<gauche.size();j++){
    nd.push_back(gauche[j]);
  }
  nd.push_back(droite[i]->getG());
  v.push_back(new sequent(nd,ng));

  vector<formule*> ng2;
  vector<formule*> nd2;
  for(int j = 0;j<droite.size();j++){
    if(i!=j){
      ng2.push_back(droite[j]);
    }else{
      ng2.push_back(droite[i]->getG());
    }
  }
  for(int j=0;j<gauche.size();j++){
    nd2.push_back(gauche[j]);
  }
  nd2.push_back(droite[i]->getD());
  v.push_back(new sequent(nd2,ng2));
    
  return v;
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
