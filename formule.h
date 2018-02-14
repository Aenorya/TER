
#ifndef FORMULE_H
#define FORMULE_H
#include<string>
#include<vector>
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
    vector<formule> lform;
 public:
    formule();
    formule(FORMULE_TYPE);
    virtual ~formule();
    FORMULE_TYPE getType();
    void addform(formule);
    void print();
    void printChildNodes();
    string toString();
};
#endif
