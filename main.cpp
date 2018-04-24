#include "formule.h"
#include "var.h"
#include "op_not.h"
#include "op_binary.h"
#include "op_or.h"
#include "op_and.h"
#include "op_imp.h"
#include "op_equ.h"
#include "sequent.h"
#include "ArbrePreuve.h"
#include "calc.h"

int main(int argc, char** argv){

	cout<<"Entrer le nombre d'hypothese du séquent : "<<endl;
	int nbh;
	cin >> nbh;
	vector<formule*> ga;
	cout<<"Entrer les hypotheses : "<<endl;
	for(int i =0;i<nbh;i++){
		formule *fa;
		yyparse(&fa);
		ga.push_back(fa);
	}	
	cout<<"Entrer le nombre de conclusion du séquent : "<<endl;
	int nbc;
	cin >> nbc;
	vector<formule*> dr;
	cout<<"Entrer les conclusions : "<<endl;
	for(int i =0;i<nbc;i++){
		formule *fa;
		yyparse(&fa);
		dr.push_back(fa);
	}
	
	
	  sequent *s=new sequent(ga,dr);

	  ArbrePreuve * a = new ArbrePreuve(s);

	  vector<ArbrePreuve*> aa;

	  aa.push_back(a);

	  for(int i =0;i<aa.size();i++){
	    cout<<"Indice de l'abre : (" << i <<")"<<endl;
	    aa[i]->afficher();
	   }

	  while(1){
	    cout<<"Entrer l'indice de l'abre a développer :"<<endl;
	    int y;
	    cin>>y;
	    cout<<"Entrer l'indice de la formule a développer : "<< endl;
	    int x ;
	    cin >> x;
	    aa=aa[y]->developper(x);
	    cout<<"Après OP sur : "<<x<<endl;
	    for(int i =0;i<aa.size();i++){
	    	cout<<"Indice de l'arbre : (" << i <<")"<<endl;
	    	aa[i]->afficher();
			if(aa[i]->estaxiome()){ cout<<"c'est un axiome"<<endl; }	    
		}

	    
	  }
	  
	}
