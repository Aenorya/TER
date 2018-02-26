#ifndef OP_BINARY_H
#define OP_BINARY_H
#include"formule.h"

class op_binary : public virtual formule{
 public:
  enum OP_TYPE{
  AND,
  OR,
  IMP,
  EQU
  };
  op_binary(OP_TYPE);
  op_binary(OP_TYPE,formule*,formule*);
  virtual ~op_binary();
  formule* getG();
  formule* getD();
 protected:
  OP_TYPE op_type;
  formule *g;
  formule *d;
  void printChildNodes();
  
};
#endif
