%{
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "treeUtils.h"
#include "scanType.h"
#include "dot.h"
#include <cstdio>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *msg);

void printToken(TokenData myData, string tokenName, int type = 0) {
   cout << "Line: " << myData.linenum << " Type: " << tokenName;
   if(type==0)
     cout << " Token: " << myData.tokenstr;
   if(type==1)
     cout << " Token: " << myData.nvalue;
   if(type==2)
     cout << " Token: " << myData.cvalue;

   if(type==3)
     cout << " Token: " << myData.svalue;

   cout << endl;
}

%}
%union
{
   struct   TokenData tinfo ;
}
%token   <tinfo>  INT AND BOOL
%token   <tinfo>  PRECOMPILER
%token   <tinfo>  ERROR 
%token   <tinfo>  BREAK
%token   <tinfo>  BY
%token   <tinfo>  CHAR
%token   <tinfo>  DO
%token   <tinfo>  ELSE
%token   <tinfo>  BOOLCONST
%token   <tinfo>  FOR
%token   <tinfo>  IF
%token   <tinfo>  NOT
%token   <tinfo>  OR
%token   <tinfo>  RETURN
%token   <tinfo>  STATIC
%token   <tinfo>  THEN
%token   <tinfo>  TO
%token   <tinfo>  WHILE
%token   <tinfo>  OP
%token   <tinfo>  LEQ
%token   <tinfo>  MIN
%token   <tinfo>  MAX
%token   <tinfo>  NEQ
%token   <tinfo>  MULASS
%token   <tinfo>  INC
%token   <tinfo>  ADDASS
%token   <tinfo>  DEC
%token   <tinfo>  SUBASS
%token   <tinfo>  DIVASS
%token   <tinfo>  EQ
%token   <tinfo>  GEQ
%token   <tinfo>  NUMCONST
%token   <tinfo>  STRINGCONST
%token   <tinfo>  CHARCONST
%token   <tinfo>  ID
%type <tinfo>  term program
%%
program  :  program term
   |  term  {$$=$1;}
   ;
stmt_seq :  stmt_seq SEMI stmt_seq
               {YYSTYPE t = $1;
                 if (t != NULL)
                   { while (t->sibling != NULL)
		        t = t->sibling;
                      t->sibling = $3;
                      $$ = $1; }
                      else $$ = $3;
               }
         |  stmt {$$ = $1;}
         ;
if_stmt  :   IF exp THEN stmt_seq END
               { $$ = newStmtNode(IfK);
                 $$->child[0] = $2;
                 $$->shild[1] = $4;
               }
         |    IF exp THEN stmt_seq ELSE stmt_seq END
		{ $$ = newStmtNode(IfK);
		  $$->child[0] = $2;
   		  $$->child[1] = $4;  
		  $$->child[2] = $6;
                }
	 ;
term  : 
      PRECOMPILER {printToken(yylval.tinfo, "PRECOMPILER");} 
   |  AND {printToken(yylval.tinfo, "AND");}    
   |  INT {printToken(yylval.tinfo, "INT");}   
   |  BOOL {printToken(yylval.tinfo, "BOOL");} 
   |  BREAK {printToken(yylval.tinfo, "BREAK");}  
   |  BY {printToken(yylval.tinfo, "BY");}  
   |  CHAR {printToken(yylval.tinfo, "CHAR");}  
   |  DO {printToken(yylval.tinfo, "DO");} 
   |  ELSE {printToken(yylval.tinfo, "ELSE");} 
   |  BOOLCONST {printToken(yylval.tinfo, "BOOLCONST");} 
   |  FOR {printToken(yylval.tinfo, "FOR");} 
   |  IF {printToken(yylval.tinfo, "IF");} 
   |  NOT {printToken(yylval.tinfo, "NOT");} 
   |  OR {printToken(yylval.tinfo, "OR");} 
   |  RETURN {printToken(yylval.tinfo, "RETURN");} 
   |  STATIC {printToken(yylval.tinfo, "STATIC");} 
   |  THEN {printToken(yylval.tinfo, "THEN");} 
   |  TO {printToken(yylval.tinfo, "TO");} 
   |  WHILE {printToken(yylval.tinfo, "WHILE");} 
   |  OP {printToken(yylval.tinfo, "OP", 2);} 
   |  LEQ {printToken(yylval.tinfo, "LEQ");} 
   |  MIN {printToken(yylval.tinfo, "MIN");} 
   |  MAX {printToken(yylval.tinfo, "MAX");} 
   |  NEQ {printToken(yylval.tinfo, "NEQ");} 
   |  MULASS {printToken(yylval.tinfo, "MULASS");} 
   |  INC {printToken(yylval.tinfo, "INC");} 
   |  ADDASS {printToken(yylval.tinfo, "ADDASS");} 
   |  DEC {printToken(yylval.tinfo, "DEC");} 
   |  SUBASS {printToken(yylval.tinfo, "SUBASS");} 
   |  DIVASS {printToken(yylval.tinfo, "DIVASS");} 
   |  EQ {printToken(yylval.tinfo, "EQ");} 
   |  GEQ {printToken(yylval.tinfo, "GEQ");} 
   |  NUMCONST {printToken(yylval.tinfo, "NUMCONST");}
   |  STRINGCONST {printToken(yylval.tinfo, "STRINGCONST");}
   |  CHARCONST {printToken(yylval.tinfo, "CHARCONST");}
   |  ID {printToken(yylval.tinfo, "ID");} 
   |  ERROR    {cout << "ERROR(" << yylval.tinfo.linenum << "): Invalid or misplaced input character: '" << yylval.tinfo.tokenstr <<"'. Character Ignored." << endl; }
   ;
%%
void yyerror (const char *msg)
{ 
   cout << "Error: " <<  msg << endl;
}
int main(int argc, char **argv) {
//yylval.tinfo.linenum = 1;
   int index;
   char *file = NULL;
   bool dotAST = false;             // make dot file of AST
   extern FILE *yyin;

   int ch;

   while ((ch = getopt(argc, argv, "d")) != -1) {
      switch (ch) {
         case 'd':
                 dotAST = true;
                 break;
         case '?':
         default:
                 //usage();
               ;
      }
   }

   if ( optind == argc ) yyparse();
   for (index = optind; index < argc; index++)
   {
      yyin = fopen (argv[index], "r");
      yyparse();
      fclose (yyin);
   }
   if (numErrors==0) {
      printTree(stdout, syntaxTree, true, true);
      if(dotAST) {
         printDotTree(stdout, syntaxTree, false, false);
      }
   }
   else {
      printf("-----------\n");
      printf("Errors: %d\n", numErrors);
      printf("-----------\n");
   }
   return 0;
}

