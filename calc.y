%{

#include "global.h"
#include <iostream>
#include <stdlib.h>
#include "formule.h"
#include "op_binary.h"
#include "op_and.h"
#include "op_or.h"
#include "op_imp.h"
#include "op_equ.h"
#include "op_not.h"
#include "var.h"

extern char* yytext;
int yylex();
void yyerror(string s);
%}


%token  VAR
%token  NOT AND OR IMP EQU
%token  PARENTHESE_GAUCHE PARENTHESE_DROITE
%token  FIN

%left AND OR
%left IMP EQU
%right NEG


%start Input
%%

Input:
    /* Vide */
  | Input Ligne
  ;

Ligne:
    FIN
  | Expression FIN    { $1->printChildNodes(); }
  ;

Expression:
    VAR      { $$=$1; }
  | NOT Expression  { $$=new op_not($2); }
  | Expression AND Expression  { $$=new op_and($1,$3); }
  | Expression OR Expression { $$=new op_or($1,$3); }
  | Expression IMP Expression  { $$=new op_imp($1,$3); }
  | Expression EQU Expression  { $$=new op_equ($1,$3); }
  | PARENTHESE_GAUCHE Expression PARENTHESE_DROITE  { $$=$2; }
  ;

%%

void yyerror(string s) {
  cout << s << endl;
}

extern int yyparse();
int main(void) {
  yyparse();

}
