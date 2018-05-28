
#ifndef SEQUENT_H
#define SEQUENT_H

#include "formule.h"
#include<vector>

class sequent{
 protected:
  vector<formule*> gauche;
  vector<formule*> droite;
  int hauteur;
 public:
  sequent();
  sequent(vector<formule*>,vector<formule*>);
  virtual ~sequent();
  vector<sequent*> ETgauche(int);
  vector<sequent*> ETdroit(int);
  vector<sequent*> OUgauche(int);
  vector<sequent*> OUdroit(int);
  vector<sequent*> IMPgauche(int);
  vector<sequent*> IMPdroit(int);
  vector<sequent*> EQUgauche1(int);
  vector<sequent*> EQUgauche2(int);
  vector<sequent*> EQUdroit(int);
  vector<sequent*> NOTgauche(int);
  vector<sequent*> NOTdroit(int);
  vector<formule*> getGauche();
  vector<formule*> getDroite();
	bool estaxiome();
  void affiche();
  void afficheSansIndice();
  void afficheHypotheses();
  void afficheSeparateur();
  void afficheConclusions();
  size_t longueur();
  
};
#endif
