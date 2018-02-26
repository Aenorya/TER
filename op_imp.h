#include"op_binary.h"
#ifndef OP_IMP_H
#define OP_IMP_H

class op_imp : public virtual op_binary{
 
  

 public:
  op_imp();
  virtual ~op_imp();
  op_imp(formule*,formule*);

};
#endif
