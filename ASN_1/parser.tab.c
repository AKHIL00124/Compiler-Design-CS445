/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "treeUtils.h"
#include "treeNodes.h"
#include "scanType.h"
#include "dot.h"
#include "semantics.h"
#include <cstdio>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

int numErrors;
int numWarnings;
extern int line;
extern int yylex();

TreeNode *addSibling(TreeNode *t, TreeNode *s)
{
   // make sure s is not null. If it is this s a major error. Exit the program!
   if(s == NULL && numErrors==0) {
      printf("Error(SYSTEM): never add a NULL to a sibling list.\n");
      exit(1);
   }
   // Make sure t is not null. If ti is, just return s
   if( t!= NULL){
      TreeNode *tmp;
      tmp = t;
      while (tmp->sibling!=NULL) {
         tmp = tmp->sibling;
      }
      tmp->sibling = s;
      return t;
   }
   return s;
}
// pass the static and type attribute down the sibling list
void setType(TreeNode *t, ExpType type, bool isStatic)
{
   while (t) {
   // set t->type and t->isStatic
      t->type = type;
      t->isStatic = isStatic;
      t = t->sibling;
   }  
}
// the syntax tree goes here
TreeNode *syntaxTree;

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


#line 140 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FIRSTOP = 258,
    ADDASS = 259,
    AND = 260,
    DEC = 261,
    DIVASS = 262,
    EQ = 263,
    GEQ = 264,
    INC = 265,
    LEQ = 266,
    MAX = 267,
    MIN = 268,
    MULASS = 269,
    NEQ = 270,
    NOT = 271,
    OR = 272,
    SUBASS = 273,
    CHSIGN = 274,
    SIZEOF = 275,
    PRECOMPILER = 276,
    LASTOP = 277,
    BOOL = 278,
    BREAK = 279,
    BY = 280,
    CHAR = 281,
    DO = 282,
    ELSE = 283,
    FOR = 284,
    IF = 285,
    INT = 286,
    RETURN = 287,
    STATIC = 288,
    THEN = 289,
    TO = 290,
    WHILE = 291,
    BOOLCONST = 292,
    CHARCONST = 293,
    ID = 294,
    NUMCONST = 295,
    STRINGCONST = 296,
    LASTTERM = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 76 "parser.y" /* yacc.c:355  */

   TokenData *tokenData;
   TreeNode *tree;
   ExpType type; // for passing type spec up the tree

#line 229 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      51,    52,    21,    22,    53,    23,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    54,
      25,    26,    27,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   116,   117,   118,   120,   121,   123,   124,
     126,   129,   130,   132,   133,   135,   136,   138,   139,   141,
     142,   143,   145,   146,   148,   149,   151,   152,   154,   156,
     157,   159,   160,   164,   165,   167,   168,   169,   174,   175,
     176,   177,   179,   180,   182,   183,   184,   185,   191,   192,
     194,   196,   197,   199,   200,   202,   203,   205,   207,   208,
     209,   210,   212,   213,   214,   215,   216,   218,   219,   221,
     222,   224,   225,   227,   228,   230,   231,   232,   233,   234,
     235,   237,   238,   240,   241,   243,   244,   246,   247,   249,
     250,   252,   253,   254,   256,   257,   259,   260,   261,   263,
     264,   266,   269,   275,   276,   277,   279,   282,   283,   285,
     286,   288,   293,   298,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FIRSTOP", "ADDASS", "AND", "DEC",
  "DIVASS", "EQ", "GEQ", "INC", "LEQ", "MAX", "MIN", "MULASS", "NEQ",
  "NOT", "OR", "SUBASS", "CHSIGN", "SIZEOF", "'*'", "'+'", "'-'", "'/'",
  "'<'", "'='", "'>'", "'%'", "'?'", "PRECOMPILER", "LASTOP", "BOOL",
  "BREAK", "BY", "CHAR", "DO", "ELSE", "FOR", "IF", "INT", "RETURN",
  "STATIC", "THEN", "TO", "WHILE", "BOOLCONST", "CHARCONST", "ID",
  "NUMCONST", "STRINGCONST", "'('", "')'", "','", "';'", "'['", "'{'",
  "'}'", "']'", "':'", "LASTTERM", "$accept", "program", "precomList",
  "declList", "decl", "varDecl", "scopedVarDecl", "varDeclList",
  "varDeclInit", "varDeclId", "typeSpec", "funDecl", "parms", "parmList",
  "parmTypeList", "parmIdList", "parmId", "stmt", "matched", "iterRange",
  "unmatched", "expStmt", "compoundStmt", "localDecls", "stmtList",
  "returnStmt", "breakStmt", "exp", "assignop", "simpleExp", "andExp",
  "unaryRelExp", "relExp", "relop", "minmaxExp", "minmaxop", "sumExp",
  "sumop", "mulExp", "mulop", "unaryExp", "unaryop", "factor", "mutable",
  "immutable", "call", "args", "argList", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    42,    43,    45,    47,    60,    61,    62,    37,    63,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    40,    41,    44,    59,    91,   123,   125,    93,    58,
     297
};
# endif

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,  -132,    15,    34,  -132,  -132,  -132,  -132,  -132,   -33,
      73,  -132,  -132,   -15,  -132,    67,  -132,   -31,    -1,  -132,
      -4,    10,    19,     8,  -132,    67,    18,    25,  -132,     0,
      32,    37,  -132,   110,    67,    57,    61,    69,  -132,     0,
    -132,  -132,  -132,  -132,  -132,   -10,  -132,  -132,     0,   105,
     120,  -132,  -132,   186,     5,    51,  -132,   156,  -132,  -132,
    -132,  -132,  -132,    70,    10,    75,    79,     0,   124,     0,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    76,
     105,   182,  -132,   110,  -132,  -132,     0,     0,    80,     0,
       0,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   156,
     156,  -132,  -132,   156,  -132,  -132,  -132,   156,  -132,  -132,
    -132,  -132,   109,    -8,  -132,    83,    -6,    49,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,     0,  -132,  -132,    90,
      93,    92,  -132,   120,  -132,    65,     5,    51,  -132,     0,
     110,  -132,   110,    67,  -132,    25,    47,  -132,  -132,     0,
    -132,   116,   -13,  -132,   117,  -132,  -132,    25,    58,  -132,
    -132,  -132,   110,     0,   110,    64,  -132,  -132,  -132,     2,
    -132,  -132,  -132,     0,   105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     4,     0,     0,     1,     3,    20,    21,    19,     0,
       2,     7,     8,     0,     9,    25,     6,    17,     0,    14,
      15,     0,     0,    24,    27,    25,     0,     0,    10,     0,
      31,    28,    30,     0,     0,     0,     0,    17,    13,     0,
      97,    96,    98,   114,   112,   101,   111,   113,     0,    16,
      68,    70,    72,    74,    82,    86,    90,     0,    95,   100,
      99,   104,   105,     0,     0,     0,     0,     0,     0,     0,
      49,    52,    23,    33,    34,    38,    39,    40,    41,     0,
      61,   100,    26,     0,    18,    71,   108,     0,     0,     0,
       0,    79,    78,    75,    83,    84,    80,    76,    77,     0,
       0,    87,    88,     0,    91,    92,    93,     0,    94,    32,
      29,    57,     0,     0,    55,     0,     0,    54,    48,    63,
      60,    66,    59,    65,    64,    62,     0,    22,   110,     0,
     107,     0,   103,    67,    69,    73,    81,    85,    89,     0,
       0,    56,     0,     0,    51,     0,     0,    58,   106,     0,
     102,     0,     0,    44,    33,    36,    46,     0,     0,    50,
      53,   109,     0,     0,     0,     0,    12,    37,    47,    42,
      35,    45,    11,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   152,  -132,  -132,  -131,   136,  -132,
      -2,  -132,   140,  -132,   133,  -132,   104,   -81,  -130,  -132,
    -125,  -132,  -132,  -132,  -132,  -132,  -132,   -43,  -132,   -29,
      87,   -36,  -132,  -132,    81,  -132,    82,  -132,    66,  -132,
     -51,  -132,  -132,   -26,  -132,  -132,  -132,  -132,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,   144,    18,    19,    20,
      21,    14,    22,    23,    24,    31,    32,    72,    73,   151,
      74,    75,    76,   117,   146,    77,    78,    79,   126,    80,
      50,    51,    52,    99,    53,   100,    54,   103,    55,   107,
      56,    57,    58,    59,    60,    61,   129,   130,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    13,   127,    85,    89,    88,   108,    81,    13,    89,
     154,    89,   155,     1,   158,     4,    39,   156,    15,    89,
      25,    40,    81,    41,    26,   115,   165,   101,   102,    42,
     142,   163,   167,    17,   170,   140,   173,   168,   113,   171,
     116,    86,    81,   128,   131,    87,    43,    44,    45,    46,
      47,    48,    27,    28,   134,    29,   138,    81,    30,   153,
      81,    81,    34,    39,     5,   160,     6,    36,    40,     7,
      41,    33,   104,    37,     8,   105,    42,    94,    95,   106,
      65,     6,     9,   147,     7,    66,    67,    63,    68,     8,
      64,   143,    69,    43,    44,    45,    46,    47,    48,     6,
      81,    70,     7,    71,   159,     6,   161,     8,     7,    83,
     152,    27,   166,     8,    81,   145,    81,    27,   172,    84,
      81,     9,    89,    81,    26,    90,    39,   112,   109,   111,
     118,    40,   132,    41,   169,   139,    81,   141,    81,    42,
      39,   157,   148,    65,   174,    40,   149,    41,    66,    67,
     150,    68,   162,    42,   164,    69,    43,    44,    45,    46,
      47,    48,    16,    38,    70,    35,    71,    82,   110,   137,
      43,    44,    45,    46,    47,    48,   133,    40,   114,    41,
     135,     0,   136,     0,     0,    42,   119,     0,   120,   121,
       0,     0,   122,     0,    91,    92,   123,    93,    94,    95,
     124,    96,    43,    44,    45,    46,    47,    48,   125,     0,
       0,    97,     0,    98
};

static const yytype_int16 yycheck[] =
{
      29,     3,    83,    39,    17,    48,    57,    33,    10,    17,
     140,    17,   142,    30,   145,     0,    16,   142,    51,    17,
      51,    21,    48,    23,    55,    68,   157,    22,    23,    29,
      36,    44,   162,    48,   164,    43,    34,   162,    67,   164,
      69,    51,    68,    86,    87,    55,    46,    47,    48,    49,
      50,    51,    53,    54,    90,    59,   107,    83,    48,   140,
      86,    87,    54,    16,    30,   146,    32,    49,    21,    35,
      23,    52,    21,    48,    40,    24,    29,    12,    13,    28,
      33,    32,    48,   126,    35,    38,    39,    55,    41,    40,
      53,    42,    45,    46,    47,    48,    49,    50,    51,    32,
     126,    54,    35,    56,    57,    32,   149,    40,    35,    52,
     139,    53,    54,    40,   140,   117,   142,    53,    54,    58,
     146,    48,    17,   149,    55,     5,    16,    48,    58,    54,
      54,    21,    52,    23,   163,    26,   162,    54,   164,    29,
      16,   143,    52,    33,   173,    21,    53,    23,    38,    39,
      58,    41,    36,    29,    37,    45,    46,    47,    48,    49,
      50,    51,    10,    27,    54,    25,    56,    34,    64,   103,
      46,    47,    48,    49,    50,    51,    89,    21,    54,    23,
      99,    -1,   100,    -1,    -1,    29,     4,    -1,     6,     7,
      -1,    -1,    10,    -1,     8,     9,    14,    11,    12,    13,
      18,    15,    46,    47,    48,    49,    50,    51,    26,    -1,
      -1,    25,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    62,    63,     0,    30,    32,    35,    40,    48,
      64,    65,    66,    71,    72,    51,    65,    48,    68,    69,
      70,    71,    73,    74,    75,    51,    55,    53,    54,    59,
      48,    76,    77,    52,    54,    73,    49,    48,    69,    16,
      21,    23,    29,    46,    47,    48,    49,    50,    51,    90,
      91,    92,    93,    95,    97,    99,   101,   102,   103,   104,
     105,   106,   109,    55,    53,    33,    38,    39,    41,    45,
      54,    56,    78,    79,    81,    82,    83,    86,    87,    88,
      90,   104,    75,    52,    58,    92,    51,    55,    88,    17,
       5,     8,     9,    11,    12,    13,    15,    25,    27,    94,
      96,    22,    23,    98,    21,    24,    28,   100,   101,    58,
      77,    54,    48,    90,    54,    88,    90,    84,    54,     4,
       6,     7,    10,    14,    18,    26,    89,    78,    88,   107,
     108,    88,    52,    91,    92,    95,    97,    99,   101,    26,
      43,    54,    36,    42,    67,    71,    85,    88,    52,    53,
      58,    80,    90,    78,    79,    79,    81,    71,    68,    57,
      78,    88,    36,    44,    37,    68,    54,    79,    81,    90,
      79,    81,    54,    34,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     2,     1,     1,     1,
       3,     4,     3,     3,     1,     1,     3,     1,     4,     1,
       1,     1,     6,     5,     1,     0,     3,     1,     2,     3,
       1,     1,     3,     1,     1,     6,     4,     6,     1,     1,
       1,     1,     3,     5,     4,     6,     4,     6,     2,     1,
       4,     2,     0,     2,     0,     2,     3,     2,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 114 "parser.y" /* yacc.c:1646  */
    {syntaxTree = (yyvsp[0].tree);}
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = NULL; printf("%s\n", yylval.tokenData->tokenstr);}
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = NULL; printf("%s\n", yylval.tokenData->tokenstr);}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-1].tree),(yyvsp[0].tree));}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree); setType( (yyvsp[-1].tree), (yyvsp[-2].type), false); yyerrok;}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree); setType( (yyvsp[-1].tree), (yyvsp[-2].type), true); yyerrok;}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree); setType( (yyvsp[-1].tree), (yyvsp[-2].type), false); yyerrok;}
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-2].tree),(yyvsp[0].tree));}
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-2].tree); if( (yyval.tree) != NULL) (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tokenData));}
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tokenData));  (yyval.tree)->isArray = true; (yyval.tree)->size = (yyvsp[-1].tokenData)->nvalue + 1;}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Integer;}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Boolean;}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = Char;}
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(FuncK, Void, (yyvsp[-4].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree);}
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); setType((yyvsp[0].tree), (yyvsp[-1].type), false);}
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree);}
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tokenData));}
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tokenData)); 
				(yyval.tree)->isArray = true;
				(yyval.tree)->size = 1;	}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData), NULL, (yyvsp[-2].tree), (yyvsp[0].tree));
                                                           (yyval.tree)->child[0] = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData));
							   (yyval.tree)->child[0]->attr.name = (yyvsp[-4].tokenData)->svalue;
							   (yyval.tree)->child[0]->isArray = false;
							   (yyval.tree)->child[0]->size = 1;   }
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData), NULL, (yyvsp[-2].tree), (yyvsp[0].tree));
						(yyval.tree)->child[0] = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData));
                                                           (yyval.tree)->child[0]->attr.name = (yyvsp[-4].tokenData)->svalue;
                                                           (yyval.tree)->child[0]->isArray = false;
                                                           (yyval.tree)->child[0]->size = 1;	}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[-1].tree)); yyerrok;}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = ((yyvsp[0].tree)==NULL ? (yyvsp[-1].tree) : addSibling((yyvsp[-1].tree), (yyvsp[0].tree)));}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));}
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData), (yyvsp[-1].tree));}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData), (yyvsp[-1].tree));}
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData), (yyvsp[-1].tree));}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree));}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 249 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree));}
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].tokenData)->tokenclass = CHSIGN; (yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].tokenData)->tokenclass=SIZEOF; (yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.tokenData) = (yyvsp[0].tokenData);}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree);}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree);}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(IdK,(yyvsp[0].tokenData));
	 	     (yyval.tree)->attr.name = (yyvsp[0].tokenData)->svalue;
		     (yyval.tree)->isArray = false; }
#line 2075 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData), NULL, (yyvsp[-1].tree));
			 (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
			 (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->svalue;
			 // $$->child[0]->isArray = false;
			 (yyval.tree)->isArray = false;	}
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData), (yyvsp[-1].tree)); 
			  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->svalue;}
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2116 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = NULL;}
#line 2122 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = ((yyvsp[0].tree)==NULL ? (yyvsp[-2].tree) : addSibling((yyvsp[-2].tree), (yyvsp[0].tree)));}
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2134 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                 (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                 (yyval.tree)->isArray = false;
                 (yyval.tree)->type = Integer;
                 (yyval.tree)->size = 1;   }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                 (yyval.tree)->attr.cvalue = (yyvsp[0].tokenData)->cvalue;
                 (yyval.tree)->type = Char;
                 (yyval.tree)->isArray = false;
                 (yyval.tree)->size = 1;   }
#line 2154 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                 (yyval.tree)->attr.string = (yyvsp[0].tokenData)->svalue;
                 (yyval.tree)->type = Char;
                 (yyval.tree)->isArray = true;
                 (yyval.tree)->size = (yyvsp[0].tokenData)->nvalue + 1;     }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
		 (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
		 (yyval.tree)->type = Boolean;
		 (yyval.tree)->isArray = false;
		 (yyval.tree)->size = 1;	}
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2178 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 312 "parser.y" /* yacc.c:1906  */

void yyerror (const char *msg)
{ 
   cout << "Error: " <<  msg << endl;
}

char *largerTokens[LASTTERM+1];        // used in the utils.cpp file printing routines

static char tokenBuffer[16];
char *tokenToStr(int type)
{
    if (type>LASTTERM) {
   return (char *)"UNKNOWN";
    }
    else if (type>256) {
   return largerTokens[type];
    }
    else if ((type<32) || (type>127)) {
   sprintf(tokenBuffer, "Token#%d", type);
    } else {
   tokenBuffer[0] = type;
   tokenBuffer[1] = '\0';
    }
    return tokenBuffer;
}


// create a mapping from token class enum to a printable name in a
// way that makes it easy to keep the mapping straight.
void initTokenStrings()
{
    largerTokens[ADDASS] = (char *)"+=";
    largerTokens[AND] = (char *)"and";
    largerTokens[BOOL] = (char *)"bool";
    largerTokens[BOOLCONST] = (char *)"boolconst";
    largerTokens[BREAK] = (char *)"break";
    largerTokens[BY] = (char *)"by";
    largerTokens[CHAR] = (char *)"char";
    largerTokens[CHARCONST] = (char *)"charconst";
    largerTokens[CHSIGN] = (char *)"chsign";
    largerTokens[DEC] = (char *)"--";
    largerTokens[DIVASS] = (char *)"/=";
    largerTokens[DO] = (char *)"do";
    largerTokens[ELSE] = (char *)"else";
    largerTokens[EQ] = (char *)"==";
    largerTokens[FOR] = (char *)"for";
    largerTokens[GEQ] = (char *)">=";
    largerTokens[ID] = (char *)"id";
    largerTokens[IF] = (char *)"if";
    largerTokens[INC] = (char *)"++";
    largerTokens[INT] = (char *)"int";
    largerTokens[LEQ] = (char *)"<=";
    largerTokens[MAX] = (char *)":>:";
    largerTokens[MIN] = (char *)":<:";
    largerTokens[MULASS] = (char *)"*=";
    largerTokens[NEQ] = (char *)"!=";
    largerTokens[NOT] = (char *)"not";
    largerTokens[NUMCONST] = (char *)"numconst";
    largerTokens[OR] = (char *)"or";
    largerTokens[RETURN] = (char *)"return";
    largerTokens[SIZEOF] = (char *)"sizeof";
    largerTokens[STATIC] = (char *)"static";
    largerTokens[STRINGCONST] = (char *)"stringconst";
    largerTokens[SUBASS] = (char *)"-=";
    largerTokens[THEN] = (char *)"then";
    largerTokens[TO] = (char *)"to";
    largerTokens[WHILE] = (char *)"while";
    largerTokens[LASTTERM] = (char *)"lastterm";
}

int main(int argc, char **argv) {
//yylval.tinfo.linenum = 1;
   int index;
   char *file = NULL;
   bool dotAST = false;             // make dot file of AST
   extern FILE *yyin;
   
   int ch;

   initTokenStrings();
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

      SymbolTable *symtab;
      symtab = new SymbolTable();
      symtab->debug(false);
      int globalOffset = 0;
      syntaxTree = semanticAnalysis(syntaxTree, true, false, symtab, globalOffset);

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
   printf("Number of warnings: %d\n", numWarnings);
   printf("Number of errors: %d\n", numErrors);
   return 0;
}

