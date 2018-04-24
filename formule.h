
#ifndef FORMULE_H
#define FORMULE_H
#include<string>
#include<iostream>
using namespace std;

class formule{
 public:
  enum FORMULE_TYPE{
  NOT,
  OP_BINAIRE,
  VAR
  };
 protected:
    FORMULE_TYPE type;
    string form;
 public:
    formule();
    formule(FORMULE_TYPE);
    virtual ~formule();
    virtual formule* getD();
    virtual formule* getG();
    virtual formule* getSuiv();
	string getform();
    FORMULE_TYPE getType();
    void print();
    virtual void printChildNodes();
	bool equal(formule*);
    
};

#endif
