#ifndef ARBREPREUVE_H
#define ARBREPREUVE_H

#include "sequent.h"

class ArbrePreuve {
 protected:
  sequent* s;
  vector<ArbrePreuve*> a;
 public:
  ArbrePreuve();
  ArbrePreuve(sequent *);
  virtual ~ArbrePreuve();
  void afficher();
  vector<ArbrePreuve *> developper(int);
};

#endif
