#include "formule.h"
#include "var.h"
#include "op_not.h"
#include "op_binary.h"
#include "op_or.h"
#include "op_and.h"
#include "op_imp.h"
#include "op_equ.h"
int main(int argc, char** argv){

  op_not *fn = new op_not();
  var *fv = new var("s");
  var *fv2 = new var("z");
  op_or *fa = new op_or();
  cout<<"ajout fv a fn"<<endl;
  fn->addform(*fv);
  cout<<"ajout fn a fa "<< fa->getType()<<endl;
  fa->addform(*fn);
  cout<<"ajout fv2 a fa"<<endl;

  fa->addform(*fv2);

  fa->printChildNodes();
  
  
}
