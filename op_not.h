
#ifndef OP_NOT_H
#define OP_NOT_H
#include"formule.h"
class op_not : public virtual formule{
 public:
  op_not();
  op_not(formule*);
  virtual ~op_not();
  formule *getSuiv();
  void printChildNodes();
 protected:
  formule *suiv;
};
#endif
