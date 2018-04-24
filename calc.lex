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
#include <string.h>


%}

blancs    [ \t]+

chiffre   [0-9]
var [A-Z]

%%

{blancs}  { /* On ignore */ }

{var}   {yylval= new var(strdup(yytext)); return(VAR);}

"!"   return(NOT);

"/\\"   return(AND);
"\\/"   return(OR);

"->"   return(IMP);
"<->"   return(EQU);

"("   return(PARENTHESE_GAUCHE);
")"   return(PARENTHESE_DROITE);

"\n"  return(FIN);
