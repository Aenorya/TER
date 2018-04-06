#ifndef OP_BINARY_H
#define OP_BINARY_H
#include"formule.h"

class op_binary : public formule{
 public:
  enum OP_TYPE{
  AND,
  OR,
  IMP,
  EQU
  };
  protected:
  OP_TYPE op_type;
  formule *g;
  formule *d;
  void printChildNodes();
 public:
  op_binary(OP_TYPE);
  op_binary(OP_TYPE,formule*,formule*);
  virtual ~op_binary();
  formule* getG();
  formule* getD();
  OP_TYPE getOptype();
};
#endif
