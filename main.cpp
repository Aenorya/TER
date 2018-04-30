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
	int nbh;
	do{

		cout<<"Entrer le nombre d'hypothese du séquent : "<<endl;
		cin >> nbh;
		cout<<"------"<<nbh<<"-----"<<endl;
	}while(nbh<=0);
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

	  ArbrePreuve * ArbreCourant = new ArbrePreuve(s);

	  vector<ArbrePreuve*> aa;
	  aa.push_back(ArbreCourant);

	  for(size_t i =0;i<aa.size();i++){
	    cout<<"Indice de l'arbre : (" << i <<")"<<endl;
	    aa[i]->afficher();
	   }
		 bool b;

	  do{
			vector<ArbrePreuve*> aNext;

			size_t y;
			size_t x;
			do{
				cout<<"Entrer l'indice de l'arbre a développer : "<<endl;
				cin>>y;
			}while(y>=aa.size());

			do{
	    	cout<<"Entrer l'indice de la formule a développer : "<< endl;
	    	cin >> x;
			}while(x>=aa[y]->longueurSequent());

			ArbreCourant=aa[y];
	    aNext=ArbreCourant->developper(x);
			if(!aNext.empty()){
				for(size_t i = 0; i < aNext.size();i++){
					aa.push_back(aNext[i]);
				}
			}
	    cout<<"Après OP sur : "<<x<<endl;
	    for(size_t i =0;i<aa.size();i++){
	    	cout<<"Indice de l'arbre : (" << i <<")";
				if(aa[i]->estclos()){cout<<", (clos)";}
				if(aa[i]->estaxiome()){ cout<<", (axiome)"; }
				cout<<endl;
				aa[i]->afficher();

		}
		b=true;
		for(size_t i=0;i<aa.size();i++){
			if(!aa[i]->estclos()){b=false;}
		}
		if(b){cout<<"Tout est clos !"<<endl;}
	}	while(!b);
}
