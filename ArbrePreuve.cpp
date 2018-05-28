#include "ArbrePreuve.h"
#include "op_binary.h"
ArbrePreuve::ArbrePreuve(){}
ArbrePreuve::ArbrePreuve(sequent * se){
  s=se;
  cloture=false;
}
ArbrePreuve::~ArbrePreuve(){}

size_t ArbrePreuve::longueurSequent(){
  return s->longueur();
}
bool ArbrePreuve::estaxiome(){
	return s->estaxiome();
}
bool ArbrePreuve::estclos(){
	return cloture;
}
void ArbrePreuve::afficher(){
  s->affiche();
}

int ArbrePreuve::getHauteur(){
	if(parent == NULL){
		return 0;
	}
	return parent->getHauteur() +1;
}

int ArbrePreuve::getHauteurMax(){
	for(int i = 0; i < a.size(); i++){
		if(a.size() == 0){
			return 1;
		}
		else {
			return 1 + a[i]->getHauteurMax();
		}
	}

}

void ArbrePreuve::afficherParent(){
  if(parent != NULL){
    cout<<"\n-----------------------------------------"<<'\n';
    parent->afficherSansIndice();
  }
}

void ArbrePreuve::afficherSansIndice(){
	s->afficheSansIndice();
}
void ArbrePreuve::afficherHypotheses(){
  s->afficheHypotheses();
}
void ArbrePreuve::afficherSeparateur(){
  s->afficheSeparateur();
}
void ArbrePreuve::afficherConclusions(){
  s->afficheConclusions();
}

void ArbrePreuve::print(){
	for(int i = 0; i < a.size(); i++) {
		a[i]->print();
	}

	if(a.size() == 0) {
		for(int i = 0; i < longueurSequent(); i++){
			cout<<"\t";
		}
	}
	if(a.size() > 0)cout<<endl;
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j<a[i]->longueurSequent(); j++){
			cout<<"-------";
		}
		cout<<"\t\t";
	}

	if(a.size() == 0) {
		for(int i = 0; i < longueurSequent(); i++){
			cout<<"\t";
		}
	}
	if(a.size()!=0)cout<<endl;
	for(int i = 0; i < a.size(); i++) {
		a[i]->s->afficheSansIndice();
		cout<<"\t\t";
	}

}

void ArbrePreuve::printAll(){
	print();
	cout<<"\n----------------------------------------------------------------------\n";
	afficherSansIndice();
	cout<<"\n\n";

}

vector<ArbrePreuve *> ArbrePreuve::developper(size_t i){
  if(cloture){
    return a;
  }
  vector<formule*> g=s->getGauche();
  vector<formule*> d=s->getDroite();
  vector<sequent *> se;
  for(size_t j =0;j<g.size();j++){
    if(j==i){
      if(this->estaxiome()){
        cloture=true;
        return a;
      }else{
        if(g[i]->getType()==formule::NOT){
  	       se=s->NOTgauche(i);
        }
        if(g[i]->getType()==formule::OP_BINAIRE){
  	       if(((op_binary*)g[i])->getOptype()==op_binary::AND){
      	      se=s->ETgauche(i);
           }else if(((op_binary*)g[i])->getOptype()==op_binary::OR){
  	          se=s->OUgauche(i);
           }else if(((op_binary*)g[i])->getOptype()==op_binary::IMP){
             se=s->IMPgauche(i);
           }else if(((op_binary*)g[i])->getOptype()==op_binary::EQU){
  	         se=s->EQUgauche1(i);
  	       }
         }
      }
    }
  }
  for(size_t j =g.size();j<(d.size()+g.size());j++){

    if(j==i){
      if(this->estaxiome()){
        cloture=true;
        return a;
      }else{
        if(d[(j-g.size())]->getType()==formule::NOT){
  	       se=s->NOTdroit((j-g.size()));
        }
        if(d[(j-g.size())]->getType()==formule::OP_BINAIRE){
  	       if(((op_binary*)d[(j-g.size())])->getOptype()==op_binary::AND){
  	          se=s->ETdroit((j-g.size()));
  	       }else if(((op_binary*)d[(j-g.size())])->getOptype()==op_binary::OR){
  	          se=s->OUdroit((j-g.size()));
  	       }else if(((op_binary*)d[(j-g.size())])->getOptype()==op_binary::IMP){
  	          se=s->IMPdroit((j-g.size()));
  	       }else if(((op_binary*)d[(j-g.size())])->getOptype()==op_binary::EQU){
  	          se=s->EQUdroit((j-g.size()));
  	       }
        }
      }
    }
  }
  for(size_t x=0;x<se.size();x++){
     a.push_back(new ArbrePreuve(se[x]));
  }

  for(int i=0; i<a.size();i++){
     a[i]->parent = this;
}

      if(!a.empty()){cloture=true;}
     return a;

  }

ArbrePreuve* ArbrePreuve::getParent(){
	return this->parent;
}
