#include "treeNodes.h"
#include "semantics.h"
#include "treeUtils.h"
#include "parser.tab.h"
#include "symbolTable.h"

// some globals
extern int numErrors;
extern int numWarnings;
extern bool printErrors;
extern bool printWarnings;


// SPECIAL OPTIONS
static bool noDuplicateUndefs;
static bool shareCompoundSpace;

// expression types
static ExpectType expectType[LASTOP];
static ReturnType returnType[LASTOP];

// memory offsets are GLOBAL
static int goffset;                   // top of global space
static int foffset;                   // top of local space

void traverseDeclK( TreeNode *current, SymbolTable *symtab );
void traverseStmtK(TreeNode *current, SymbolTable *symtab);
void traverseExpK(TreeNode *current, SymbolTable *symtab);

// Helper function prototypes
bool insertErr(TreeNode *current);
void treeTraverse(TreeNode *current, SymbolTable *symtab);

// helper functions prototypes



void traverseExpK(TreeNode *current, SymbolTable *symtab ){

   switch(current->kind.exp){

      case AssignK:
            switch(returnType[current->attr.op]){
               case RetInt:
                    current->type = Integer;
               break;
               case RetBool:
                    current->type = Boolean;
               break;
               case RetLHS:
                    current->type = current->child[0]->type;
                    if (current->attr.op == int('=')){
                       if (current->type != current->child[1]->type && current->child[1]->type != UndefinedType){
                           printf("SEMANTIC ERROR(%d): '=' requires operands of the same type but lhs is %s and rhs is %s.\n",current->lineno, expTypeToStr(current->type), expTypeToStr(current->child[1]->type));
                           numErrors++;
                       }
                       current->isArray = current->child[0]->isArray;
                   }
              break;
            }
         break;

      case ConstantK:
         current->isConst = true;
         switch (current->type){
            case Void:
            break;
            case Integer:
            break;
            case Boolean:
            break;
            case UndefinedType:
            break;
            case Char:
                if (current->isArray){
                   current->varKind = Global;
                   current->offset = goffset - 1;
                   goffset -= current->size;
                }
            break;



         }
         break;

      case OpK:
            switch(returnType[current->attr.op]){
               case RetInt:
                    current->type = Integer;
               break;
               case RetBool:
                    current->type = Boolean;
               break;
               case RetLHS:
                    current->type = current->child[0]->type;
                    if (current->attr.op == int('=')){
                       current->isArray = current->child[0]->isArray;
                    }

              break;
            }
         break;

      case CallK:         // No break on purpose
                      
      case IdK:
         char *id = strdup(current->attr.name);
         TreeNode *temp = (TreeNode*)symtab->lookup(id);
         if (temp == NULL){        
            printf("SEMANTIC ERROR(%d): Symbol \'%s\' is not declared.\n", current->lineno, id);                      //This is an error we have to deal with it later
            numErrors++; 
         }   
         else {
            current->type = temp->type;
            current->isArray = temp->isArray;
            current->isStatic = temp->isStatic;
            current->size = temp->size;
            current->varKind = temp->varKind;
            current->offset = temp->offset;
         }
      break;

   }
}



void traverseDeclK(TreeNode *current, SymbolTable *symtab)
{
   if(current->nodekind != DeclK){
      printf("traverseDeclK of non DeclK. This should never happen!!\n");
      return;
   }
   static int varCounter = 0;
   char *id = strdup(current->attr.name);

   switch (current->kind.decl) {
      case VarK:
         //if (!symtab->insert(id, (void*)current) && current->lineno != -1) {
         //}
         //break;  // No Break on purpose
      case ParamK:
         if (!symtab->insert(id, (void*)current) && current->lineno != -1) {
         }
         if (symtab->depth()==1) {
                current->varKind = Global;
                current->offset = goffset;
                goffset -= current->size;
         }else if (current->isStatic) {
                current->varKind = LocalStatic;
                current->offset = goffset;
                goffset -= current->size;
                {
                    char *newName;

                    newName = new char [strlen(current->attr.name)+10];
                    sprintf(newName, "%s-%d", current->attr.name, ++varCounter);
                    symtab->insertGlobal(newName, current);

                    delete [] newName;
                }
         }
         else {
                current->varKind = Local;
                current->offset = foffset;
                foffset -= current->size;
         }
         if (current->kind.decl == ParamK) current->varKind = Parameter;
         else if (current->isArray) current->offset--;
         break;
      case FuncK:
         if (!symtab->insertGlobal(id, (void*)current) && current->lineno != -1) {

         }
         current->varKind = Global;
         current->size = foffset;
         break;
   }
}


void traverseStmtK(TreeNode *current, SymbolTable *symtab)
{
   switch (current->kind.stmt)
    {
       case CompoundK:
            current->size = foffset;
            break;
     
       case ReturnK:
            if( current->child[0]->isArray ){
               printf("SEMANTIC ERROR(%d): Cannot return an array.\n", current->lineno);    // addede to check for array error
               numErrors++;
            }           
            break;
       case IfK:
            if (current->child[0]->type != Boolean){

               printf("SEMANTIC ERROR(%d): Expecting Boolean test condition in if statement but got type int.\n", current->lineno);        //testing for boolean error

               numErrors++;
            }
            break;

    }

   return;
}



bool insertErr(TreeNode * current){}

bool isNodeCompound(TreeNode *current) {
   if(current == NULL) {return false;}
   if(current->nodekind == DeclK  && current->kind.decl == FuncK) { foffset = -2; return true;}
   if(current->nodekind == StmtK) {
      if(
            current->kind.stmt == CompoundK
         || current->kind.stmt == ForK
//         || current->kind.stmt == IfK
//         || current->kind.stmt == WhileK
      )
      {
         return true;
      }
   }
   return false;
}


void treeTraverse(TreeNode *current, SymbolTable *symtab)
{
   bool isCompound = false;
    if(current == NULL) {return;}

   isCompound = isNodeCompound(current);

   if(isCompound) {
        char *id = strdup("{");
      symtab->enter("NewScope from " + (std::string)id);
   }
   int temptoff = foffset;
   treeTraverse(current->child[0], symtab);

   if(current == NULL) return;switch(current->nodekind)
   {
      case DeclK:
          traverseDeclK(current, symtab);
     break;
      case StmtK:
          traverseStmtK(current, symtab);
          break;
      case ExpK:
          traverseExpK(current, symtab);
          break;
      default:
          printf("unknown nodekind\n");
          break;
   }if(current->nodekind == StmtK &&  current->kind.stmt == ForK) {
      foffset -= 2;
   }


   treeTraverse(current->child[1], symtab);
   treeTraverse(current->child[2], symtab);

   if(current->nodekind == StmtK &&  current->kind.stmt == CompoundK) {
      current->size = foffset;
      foffset = temptoff;
   }


   if(current->nodekind == StmtK &&  current->kind.stmt == ForK) {
      current->size = foffset;
   }


   if(isCompound) {
      symtab->leave();
   }

   treeTraverse(current->sibling, symtab);

   if(current->nodekind == StmtK &&  current->kind.stmt == ForK) {
      foffset = temptoff;
   }


   return;
}


TreeNode *loadIOLib(TreeNode *syntree) {
    TreeNode *input, *output, *param_output;
    TreeNode *inputb, *outputb, *param_outputb;
    TreeNode *inputc, *outputc, *param_outputc;
    TreeNode *outnl;

    input = newDeclNode(FuncK, Integer);
    input->lineno = -1; // all are -1
    input->attr.name = strdup("input"); //We named the variables well
    input->type = Integer;

    inputb = newDeclNode(FuncK, Boolean);
    inputb->lineno = -1; // all are -1
    inputb->attr.name = strdup("inputb"); //We named the variables well
    inputb->type = Boolean;
    
    inputc = newDeclNode(FuncK, Boolean);
    inputc->lineno = -1; // all are -1
    inputc->attr.name = strdup("inputc"); //We named the variables well
    inputc->type = Char;
    //inputc->child[0]
    
    param_output = newDeclNode(ParamK, Void);
    param_output->lineno = -1; // all are -1
    param_output->attr.name = strdup("*dummy*"); //We named the variables well
    param_output->type = Integer;
    
    output = newDeclNode(FuncK, Void);
    output->lineno = -1; // all are -1
    output->attr.name = strdup("output"); //We named the variables well
    output->type = Void;
    output->child[0] = param_output;

    param_outputb = newDeclNode(ParamK, Void);
    param_outputb->lineno = -1; // all are -1
    param_outputb->attr.name = strdup("*dummy*"); //We named the variables well
    param_outputb->type = Boolean;

    outputb = newDeclNode(FuncK, Void);
    outputb->lineno = -1; // all are -1
    outputb->attr.name = strdup("outputb"); //We named the variables well
    outputb->type = Void;
    outputb->child[0] = param_outputb;

    param_outputc = newDeclNode(ParamK, Void);
    param_outputc->lineno = -1; // all are -1
    param_outputc->attr.name = strdup("*dummy*"); //We named the variables well
    param_outputc->type = Char;

    outputc = newDeclNode(FuncK, Void);
    outputc->lineno = -1; // all are -1
    outputc->attr.name = strdup("outputc"); //We named the variables well
    outputc->type = Void;
    outputc->child[0] = param_outputc;

    outnl = newDeclNode(FuncK, Void);
    outnl->lineno = -1; // all are -1
    outnl->attr.name = strdup("outnl"); //We named the variables well
    outnl->type = Void;
    outnl->child[0] = NULL;
    //////// Stuff from next slides
    // link them and prefix the tree we are interested in traversing.
    // This will put the symbols in the symbol table.
    input->sibling = output;

    output->sibling = inputb;

    inputb->sibling = outputb;

    outputb->sibling = inputc;

    inputc->sibling = outputc;

    outputc->sibling = outnl;

    outnl->sibling = syntree; // add in the tree we were given

    return input;

} 


static bool newScope = true;
static int loopCount = 0;
static int varCounter = 0;
static bool isAssignedErrOk = true;
static bool isUsedErrOk = true;
//static int goffset = 0;

TreeNode *semanticAnalysis(TreeNode *syntree, // pass in and return an annotated syntax tree
                            bool shareCompoundSpaceIn, // SPECIAL OPTION: make compound after a function share scope
                            bool noDuplicateUndefsIn, // SPECIAL OPTION: no duplicate undefines
                            SymbolTable *symtab, // pass in and return the symbol table
                            int &globalOffset // return the offset past the globals
                            )
{
    noDuplicateUndefs = noDuplicateUndefsIn;
    shareCompoundSpace = shareCompoundSpaceIn;

    bool newScope = true;
    int loopCount = 0;
    int varCounter = 0;
    bool isAssignedErrOk = true;
    bool isUsedErrOk = true;
    int goffset = 0;

    // OPERAND TYPES
    // Binary Ops
    for (int i=0; i<LASTOP; i++) expectType[i] = IntInt; // everything is IntInt
    // except the following:
    expectType[AND] = BoolBool;
    expectType[OR] = BoolBool;
    expectType[EQ] = Equal;
    expectType[NEQ] = Equal;
    expectType[LEQ] = Equal;
    expectType[int('<')] = Equal;
    expectType[GEQ] = Equal;
    expectType[int('>')] = Equal;
    expectType[int('=')] = Equal;
    expectType[int('[')] = ArrayInt;
    // Unary Ops
    expectType[NOT] = OneBool;
    expectType[int('?')] = OneInt;
    expectType[SIZEOF] = OneArray;
    expectType[CHSIGN] = OneInt;
    expectType[DEC] = OneInt;
    expectType[INC] = OneInt;
    // OPERATOR VALUES
    // Binary Ops
    for (int i=0; i<LASTOP; i++) returnType[i] = RetInt;
    returnType[AND] = RetBool;
    returnType[OR] = RetBool;
    returnType[EQ] = RetBool;
    returnType[NEQ] = RetBool;
    returnType[LEQ] = RetBool;
    returnType[int('<')] = RetBool;
    returnType[GEQ] = RetBool;
    returnType[int('>')] = RetBool;
    returnType[int('=')] = RetLHS;
    returnType[int('[')] = RetLHS;
    // Unary Ops
    returnType[NOT] = RetBool;

    syntree = loadIOLib(syntree);

    treeTraverse(syntree, symtab);   
 
    globalOffset = goffset;

    return syntree;

}
