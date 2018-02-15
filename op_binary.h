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
  virtual ~op_binary();
 protected:
    OP_TYPE op_type;
    
};
#endif
