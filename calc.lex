%{

#include "global.h"
#include "calc.h"
#include "formule.h"
#include "op_binary.h"
#include "op_and.h"
#include "op_or.h"
#include "op_imp.h"
#include "op_equ.h"
#include "op_not.h"
#include "var.h"
#include <stdlib.h>


%}

blancs    [ \t]+

chiffre   [0-9]
var [A-Za-z]

%%

{blancs}  { /* On ignore */ }

{var}   {
          return(VAR);}

<<EOF>>     return END_OF_FILE;

"!"   return(NOT);

"/\\"   return(AND);
"\\/"   return(OR);

"->"   return(IMP);
"<->"   return(EQU);

"("   return(PARENTHESE_GAUCHE);
")"   return(PARENTHESE_DROITE);

"\n"  return(FIN);
