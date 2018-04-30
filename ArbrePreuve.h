#ifndef ARBREPREUVE_H
#define ARBREPREUVE_H

#include "sequent.h"

class ArbrePreuve {
 protected:
  sequent* s;
  vector<ArbrePreuve*> a;
  bool cloture;
 public:
  ArbrePreuve();
  ArbrePreuve(sequent *);
  virtual ~ArbrePreuve();
  void afficher();
  bool estaxiome();
  bool estclos();
  size_t longueurSequent();
  vector<ArbrePreuve *> developper(size_t);
};

#endif
