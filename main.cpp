#include "formule.h"
#include "var.h"
#include "op_not.h"
#include "op_binary.h"
#include "op_or.h"
#include "op_and.h"
#include "op_imp.h"
#include "op_equ.h"
int main(int argc, char** argv){


  formule *fa = new op_equ(new op_and(new op_not(new var("S")), new var("Z")),new op_imp(new op_or(new var ("Y"),new op_not(new var("S"))),new var("Y")));
  fa->printChildNodes();

  
}
