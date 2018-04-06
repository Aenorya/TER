#include "ArbrePreuve.h"
#include "op_binary.h"
ArbrePreuve::ArbrePreuve(){}
ArbrePreuve::ArbrePreuve(sequent * se){
  s=se;
}
ArbrePreuve::~ArbrePreuve(){}
void ArbrePreuve::afficher(){
  s->affiche();
  for(int i = 0;i<a.size();i++){
    a[i]->afficher();
  }
}
vector<ArbrePreuve *> ArbrePreuve::developper(int i){
  vector<formule*> g=s->getGauche();
  vector<formule*> d=s->getDroite();
  vector<sequent *> se;
  for(int j =0;j<g.size();j++){
    if(j==i){
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
  for(int j =g.size();j<(d.size()+g.size());j++){
    
    if(j==i){
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
  
  for(int x=0;x<se.size();x++){
     a.push_back(new ArbrePreuve(se[x]));
  }
  
  
     return a;
  
  }
