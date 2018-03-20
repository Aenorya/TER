
#ifndef SEQUENT_H
#define SEQUENT_H

#include "formule.h"
#include<vector>

class sequent{
 protected:
  vector<formule*> gauche;
  vector<formule*> droite;
 public:
  sequent();
  sequent(vector<formule*>,vector<formule*>);
  virtual ~sequent();
  sequent* ETdroit();
  void affiche();
  
};
#endif
