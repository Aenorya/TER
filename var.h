#ifndef VAR_H
#define VAR_H
#include"formule.h"

class var : public virtual formule{

 public:
  var(string);
  virtual ~var();

};
#endif
