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
#include "string.h"

int getIntFromString(string x);
string getStringFromInt(int x);

int main(int argc, char** argv){
	int nbh, nbc =1;
	do{
		cout<<"Entrer le nombre d'hypothese du séquent : \n";
		cin >> nbh;
		cout<<"------"<<nbh<<"-----\n";
	}while(nbh<=0);
	vector<formule*> ga;
	cout<<"Entrer les hypotheses : \n";
	for(int i =0;i<nbh;i++){
		formule *fa;
		yyparse(&fa);
		ga.push_back(fa);
	}
	do{
		cout<<"Entrer le nombre de conclusion du séquent : \n";
		cin >> nbc;
		cout<<"------"<<nbc<<"-----"<<endl;

	}while(nbc<=0);
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
	  cout<<"Indice de l'arbre : "<<'\n';
	  for(size_t i =0;i<aa.size();i++){
	    cout<<"("<< i <<")"<<'\t';
          }
	cout<<'\n';

	  for(size_t i =0;i<aa.size();i++){

	    aa[i]->afficherHypotheses();
	   }
	  for(size_t i =0;i<aa.size();i++){

	    aa[i]->afficherSeparateur();
	   }
	  for(size_t i =0;i<aa.size();i++){

	    aa[i]->afficherConclusions();
	   }
	cout<<'\n'<<'\n';
		 bool b;

	  do{
			vector<ArbrePreuve*> aNext;
			string input_y;
			size_t y;
			size_t x;
			string input_x;
			do{
				cout<<"Entrer l'indice de l'arbre a développer : "<<endl;
				cin>>input_y;
				if(input_y == "print"){
					aa[0]->printAll();
					y = 20;
				}
				else{
					y = stoi(input_y);
				}
			}while(y>=aa.size());

			do{
	    	cout<<"Entrer l'indice de la formule a développer : "<< endl;
	    	cin >> input_x;
		x = getIntFromString(input_x);
			}while(x>=aa[y]->longueurSequent());

			ArbreCourant=aa[y];
	    aNext=ArbreCourant->developper(x);
			if(!aNext.empty()){
				for(size_t i = 0; i < aNext.size();i++){
					aa.push_back(aNext[i]);
				}
			}
	    cout<<"Après OP sur : "<<getStringFromInt(x)<<endl;
	    for(size_t i =0;i<aa.size();i++){
	    	cout<<"Indice de l'arbre : (" << i <<")";
				if(aa[i]->estclos()){cout<<", (clos)";}
				if(aa[i]->estaxiome()){ cout<<", (axiome)"; }
				cout<<endl;
				aa[i]->afficher();
				aa[i]->afficherParent();
				cout<<"\n\n";

		}
		b=true;
		for(size_t i=0;i<aa.size();i++){
			if(!aa[i]->estclos()){b=false;}
		}
		if(b){cout<<"Tout est clos !"<<endl;
			aa[0]->printAll();
		}
	}	while(!b);
}

int getIntFromString(string x){
int res = 0;
	if(x.length()==1){
		res = (int)x[0]-97;
	} else {
		res = (int)x[0] - 97;
		res += ((int)x[1] - 97);
	}
return res;
}
