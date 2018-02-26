#ifndef OP_AND_H
#define OP_AND_H
#include"op_binary.h"

class op_and : public virtual op_binary{

  

 public:
  op_and();
  op_and(formule*,formule*);
  virtual ~op_and();

};
#endif
