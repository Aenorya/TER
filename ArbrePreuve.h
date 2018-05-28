#ifndef ARBREPREUVE_H
#define ARBREPREUVE_H

#include "sequent.h"

class ArbrePreuve {
 protected:
  sequent* s;
  ArbrePreuve* parent;
  vector<ArbrePreuve*> a;
  bool cloture;
  int hauteur;
 public:
  ArbrePreuve();
  ArbrePreuve(sequent *);
  virtual ~ArbrePreuve();
  void afficher();
  void afficherParent();
  void afficherHypotheses();
  void afficherSeparateur();
  void afficherConclusions();
  void afficherSansIndice();
  void print();
  void printAll();
  int getHauteur();
  int getHauteurMax();
  bool estaxiome();
  bool estclos();
  size_t longueurSequent();
  vector<ArbrePreuve *> developper(size_t);
  ArbrePreuve* getParent();
};

#endif
