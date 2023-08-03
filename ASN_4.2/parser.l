%{

#include "scanType.h"
#include "treeNodes.h"
#include "parser.tab.h"
#include "codegen.h"

using namespace std;

#define YY_DECL extern "C" int yylex()
#define YYSTYPE int
extern int numWarnings;
extern int numErrors;
char *lastToken = (char *)"";

int line=1;

int setValue(int linenum, int tokenClass, char *svalue) {
    yylval.tokenData = new TokenData;      //this func needs a lot of things added
    yylval.tokenData->tokenclass = tokenClass;
    yylval.tokenData->linenum = linenum;
    yylval.tokenData->tokenstr = lastToken = strdup(svalue);
    yylval.tokenData->cvalue = svalue[0];
    yylval.tokenData->nvalue = atoi(svalue);
    yylval.tokenData->svalue = strdup(svalue);
    switch(tokenClass) {
       case BOOLCONST:
          yylval.tokenData->nvalue = ((lastToken[0] == 't')? 1:0);
       break;
       case STRINGCONST:
          yylval.tokenData->nvalue = strlen(svalue)-2;
           for(int i=0; i<strlen(svalue)-1; i++){
              yylval.tokenData->svalue[i] = yylval.tokenData->svalue[i+1];
           }
           yylval.tokenData->svalue[strlen(svalue)-2] = '\0';
       case CHARCONST:
          yylval.tokenData->cvalue = svalue[1];
          if (svalue[1] == '\\'){
             if (svalue[2] == 'n'){
                yylval.tokenData->cvalue = '\n';
             }
             else if (svalue[2] == '0'){
                yylval.tokenData->cvalue = '\0';
             }
          }
    }





    return tokenClass;
}

%}

%option noyywrap

letter      [a-zA-Z]
digit    [0-9]
quote    [\']
underbar [_]
letdig      {digit}|{letter}|{underbar}
limitters   [\;\,\(\)\{\}\[\]]
op    [\-\+\*\/\%\(\)\,\/\:\;\<\=\>\?\[\]\%\{\}]
whitespace  [\ \t]
boolconst     [true|false]
id    {letter}{letdig}*
leq   "<="
min    ":<:"
max    ":>:"
neq    "!="
mulass   "*="
inc   "++"
addass   "+="
dec   "--"
subass   "-="
divass    "/="
eq    "=="
geq     ">="
numconst {digit}*
stringconst ["](\\[^\n]|[^\"\\\n])*["]
charconst ['](\\[^\n]|[^\'\\\n])*[']

%%
^"#DRBC ".*      { return setValue(line, PRECOMPILER, yytext);  }
^"#DRBCRUN ".*      { return setValue(line, PRECOMPILER, yytext);  }
"and"      { return setValue(line, AND, yytext);  }
"int"      { return setValue(line, INT, yytext);  }
"bool"      { return setValue(line, BOOL, yytext);  }
"break"      { return setValue(line, BREAK, yytext);  }
"by"      { return setValue(line, BY, yytext);  }
"char"      { return setValue(line, CHAR, yytext);  }
"do"      { return setValue(line, DO, yytext);  }
"else"      { return setValue(line, ELSE, yytext);  }
"true"      { return setValue(line, BOOLCONST, yytext);  }
"false"      { return setValue(line, BOOLCONST, yytext);  }
"for"      { return setValue(line, FOR, yytext);  }
"if"      { return setValue(line, IF, yytext);  }
"not"      { return setValue(line, NOT, yytext);  }
"or"      { return setValue(line, OR, yytext);  }
"return"      { return setValue(line, RETURN, yytext);  }
"static"      { return setValue(line, STATIC, yytext);  }
"then"      { return setValue(line, THEN, yytext);  }
"to"      { return setValue(line, TO, yytext);  }
"while"      { return setValue(line, WHILE, yytext);  }
{op}      { return setValue(line, yytext[0], yytext);  }
{leq}      { return setValue(line, LEQ, yytext);  }
{min}      { return setValue(line, MIN, yytext);  }
{max}      { return setValue(line, MAX, yytext);  }
{neq}      { return setValue(line, NEQ, yytext);  }
{mulass}      { return setValue(line, MULASS, yytext);  }
{inc}      { return setValue(line, INC, yytext);  }
{addass}      { return setValue(line, ADDASS, yytext);  }
{dec}      { return setValue(line, DEC, yytext);  }
{subass}      { return setValue(line, SUBASS, yytext);  }
{divass}      { return setValue(line, DIVASS, yytext);  }
{eq}      { return setValue(line, EQ, yytext);  }
{geq}      { return setValue(line, GEQ, yytext);  }
{numconst}  { return setValue(line, NUMCONST, yytext);  }
{stringconst}  { return setValue(line, STRINGCONST, yytext);  }
{charconst}  { return setValue(line, CHARCONST, yytext);  }
{id}      { return setValue(line, ID, yytext);  }
"//".*  ;
\n       {  line++; }
{whitespace}+  ;
.     { printf("TOKEN ERROR(%d): invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0], numErrors++);}

