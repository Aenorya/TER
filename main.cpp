#include "formule.h"
#include "var.h"
#include "op_not.h"
#include "op_binary.h"
#include "op_or.h"
#include "op_and.h"
#include "op_imp.h"
#include "op_equ.h"
int main(int argc, char** argv){

  formule *fn = new op_not();
  formule *fv = new var("s");
  formule *fv2 = new var("z");
  formule *fa = new op_and();
  fn->addform(*fv);
  fa->addform(*fn);
  fa->addform(*fv2);
  fa->printChildNodes();

  
}
