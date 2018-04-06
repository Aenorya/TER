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

int main(int argc, char** argv){


  formule *fa = new op_equ(new op_and(new op_not(new var("S")), new var("Z")),new op_imp(new op_or(new var ("Y"),new op_not(new var("S"))),new var("Y")));
  //fa->printChildNodes();
  //cout<<endl;

  vector<formule*> ga;
  vector<formule*> dr;

  ga.push_back(fa);
  dr.push_back(new op_not(new var("Y")));
  ga.push_back(new op_or(new var ("Z"),new var("S")));
  dr.push_back(new op_imp(new var("Y"),new var("S")));
  dr.push_back(new op_equ(new op_and(new var("Q"),new var("Y")),new var ("Z"))); 
  
  sequent *s=new sequent(ga,dr);
  ArbrePreuve * a = new ArbrePreuve(s);
  vector<ArbrePreuve*> aa;
  aa.push_back(a);
  for(int i =0;i<aa.size();i++){
    cout<<" indice de l'abre :" << i<<endl;
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
      cout<<" indice de l'abre :" << i<<endl;
      aa[i]->afficher();
   }

    
  }
  
}
