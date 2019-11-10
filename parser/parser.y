%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
extern FILE *tokenfile;
//#define YYSTYPE struct ASTNODE *
FILE *tracerfile;
#define YYERROR_VERBOSE
#define yTRACE(x)    {fprintf(tracerfile, "%s\n", x); }

void yyerror(const char* s);    
int yylex();              
extern int line_num;        
%}
%define parse.error verbose

%union {
  int as_int;
  float as_float;
  char *as_char;
  char *as_str;
  char *as_id;
  struct ASTNODE *ast_node;
}
%glr-parser
%token <as_int> INT_C;
%token <as_float> FLOAT_C;
%token <as_char> CHAR_C;
%token <as_str> STRING_C;
%token <as_id> ID;

%token CONST BOOL INT FLOAT CHAR FILE_T NULL_T EOF_T VOID
%token IF ELSE FOR WHILE BREAK CONTINUE TRUE FALSE RETURN PRINT
%token AND OR NEQ LEQ GEQ EQ UMINUS INC DEC PEQ MEQ MULTEQ DIVEQ MODEQ


%left OR
%left AND 
%left EQ NEQ '<' LEQ '>' GEQ
%left '+' '-'
%left '/' '%' '*'
%left '^'
%left '!' UMINUS
%left '[' ']' '(' ')'
%right '?'

%type<ast_node> PROGRAM
%type<ast_node> FUNCTION_LIST
%type<ast_node> FUNCTION
%type<ast_node> ARGUMENT_LIST
%type<ast_node> ARGUMENT
%type<ast_node> STATEMENT_LIST
%type<ast_node> STATEMENT
%type<ast_node> TYPE
%type<ast_node> SCOPE
%type<ast_node> IDEN
%type<ast_node> FOR_BLOCK
%type<ast_node> WHILE_BLOCK
%type<ast_node> IF_BLOCK
%type<ast_node> DECLARATION_LIST
%type<ast_node> EXPR
%type<ast_node> PRINT_STMT
%type<ast_node> FUNC_CALL
%type<ast_node> BREAK
%type<ast_node> CONTINUE
%type<ast_node> RETURN 
%type<ast_node> OP 
%type<ast_node> INC_DEC
%type<ast_node> ID_LIST
%type<ast_node> ARRAY
%type<ast_node> START

%start START

%%
START: PROGRAM                                  {printprefix($1);}
PROGRAM: STATEMENT_LIST FUNCTION_LIST           { yTRACE("PROGRAM -> STATEMENT_LIST FUNCTION_LIST"); $$ = getprogramnode($1, $2);}
         | FUNCTION_LIST                        { yTRACE("PROGRAM -> FUNCTION_LIST"); $$ = getprogramnode(NULL, $1);}
FUNCTION_LIST: FUNCTION_LIST FUNCTION           { yTRACE("FUNCTION_LIST -> FUNCTION_LIST FUNCTION"); $$ = getfunctionlistnode($1, $2);}
               | FUNCTION                       { yTRACE("FUNCTION_LIST -> FUNCTION"); $$ = getfunctionlistnode(NULL, $1);}
FUNCTION: TYPE ID '(' ARGUMENT_LIST ')' SCOPE   { yTRACE("FUNCTION"); $$ = getfunctionnode($1, $2, $4, $6);}
ARGUMENT_LIST: ARGUMENT_LIST ',' ARGUMENT       { yTRACE("ARGUMENT_LIST -> ARGUMENT_LIST ',' ARGUMENT"); $$ = getargumentlistnode($1, $3);}
               | ARGUMENT                       { yTRACE("ARGUMENT_LIST -> ARGUMENT"); $$ = getargumentlistnode(NULL, $1);}
ARGUMENT: TYPE IDEN                             { yTRACE("ARGUMENT_LIST -> TYPE IDEN"); $$ = getargumentnode($1, $2);}
          |                                     { yTRACE("ARGUMENT_LIST -> "); $$ = getargumentnode(NULL, NULL);}
STATEMENT_LIST: STATEMENT_LIST STATEMENT        { yTRACE("STATEMENT_LIST -> STATEMENT_LIST STATEMENT "); $$ = getstatementlistnode($1, $2);}
                | STATEMENT                     { yTRACE("STATEMENT_LIST -> STATEMENT"); $$ = getstatementlistnode(NULL, $1);}
STATEMENT: FOR_BLOCK                            { yTRACE("STATEMENT -> FOR_BLOCK"); $$ = getstatementfornode($1);}
           | WHILE_BLOCK                        { yTRACE("STATEMENT -> WHILE_BLOCK"); $$ = getstatementwhilenode($1);}
           | IF_BLOCK                           { yTRACE("STATEMENT -> IF_BLOCK"); $$ = getstatementifnode($1);}
           | DECLARATION_LIST                   { yTRACE("STATEMENT -> DECLARATION_LIST"); $$ = getstatementdeclnode($1);}
           | BREAK                              { yTRACE("STATEMENT -> BREAK"); $$ = getbrknode();}
           | CONTINUE                           { yTRACE("STATEMENT -> CONTINUE"); $$ = getcntnode() ;}
           | RETURN EXPR                        { yTRACE("STATEMENT -> RETURN EXPR"); $$ = getreturnnode($2);}
           | IDEN OP EXPR                       { yTRACE("STATEMENT -> IDEN OP EXPR"); $$ = getassignmentopnode($1, $2, $3);}
           | ';'                                { yTRACE("STATEMENT -> ;") $$=getstmtnode(SEMI_COLON);}
           | PRINT_STMT                         { yTRACE("STATEMENT -> PRINT_STMT"); $$ = getstatementprntnode($1);}
           | INC_DEC                            { yTRACE("STATEMENT -> INC_DEC"); $$ = getstatementincdcnode($1);}
           | FUNC_CALL                          { yTRACE("STATEMENT -> FUNC_CALL"); $$ = getstatementfnnode($1);}
OP: '='                                         { yTRACE("OP: '='"); $$ = getopnode(EQU_N);}
    | PEQ                                       { yTRACE("OP: PEQ"); $$ = getopnode(PEQ_N);}
    | MEQ                                       { yTRACE("OP: MEQ"); $$ = getopnode(MEQ_N);}
    | MULTEQ                                    { yTRACE("OP: MULTEQ"); $$ = getopnode(MULTEQ_N);}
    | DIVEQ                                     { yTRACE("OP: DIVEQ"); $$ = getopnode(DIVEQ_N);}
    | MODEQ                                     { yTRACE("OP: MODEQ"); $$ = getopnode(MODEQ_N);}
INC_DEC:    IDEN INC                            { yTRACE("INC_DEC:    IDEN INC"); $$ = getincdecnode($1, INC_N,0);}
           | IDEN DEC                           { yTRACE("INC_DEC:    IDEN DEC"); $$ = getincdecnode($1, DEC_N,0);}
           | INC IDEN                           { yTRACE("INC_DEC:    INC IDEN"); $$ = getincdecnode($2, INC_N,1);}
           | DEC IDEN                           { yTRACE("INC_DEC:    DEC IDEN"); $$ = getincdecnode($2, DEC_N,1);}
DECLARATION_LIST: TYPE ID_LIST                   { yTRACE("DECLARATION_LIST: TYPE ID_LIST"); $$=getdeclarationlistnode(0,$1,$2);}
                  | CONST TYPE ID_LIST           { yTRACE("DECLARATION_LIST: CONST TYPE ID_LIST"); $$=getdeclarationlistnode(1,$2,$3);}
ID_LIST: ID_LIST ',' IDEN                        { yTRACE("ID_LIST: ID_LIST ',' IDEN"); $$ = getidlistnode($1, $3, NULL);}
         | ID_LIST ',' IDEN '=' EXPR             { yTRACE("ID_LIST: ID_LIST ',' IDEN '=' EXPR"); $$ = getidlistnode($1, $3, $5);}
         | IDEN '=' EXPR                         { yTRACE("ID_LIST: IDEN '=' EXPR"); $$ = getidlistnode(NULL, $1, $3);}
         | IDEN                                  { yTRACE("ID_LIST: IDEN"); $$ = getidlistnode(NULL, $1, NULL);}
IDEN: ID                                         { yTRACE("IDEN: ID"); $$ = getidennode($1, NULL, NULL);}
      | ID ARRAY                                 { yTRACE("IDEN: ID ARRAY "); $$ = getidennode($1, $2, NULL);}
      | ID '(' ARGUMENT_LIST ')'                 { yTRACE("IDEN: ID '(' ARGUMENT_LIST ')'"); $$ = getidennode($1, NULL, $3);}
ARRAY: ARRAY '[' EXPR ']'                        { yTRACE("ARRAY: ARRAY '[' EXPR ']' "); $$ = getarraynode($1, $3);}
      | '['']'                                   { yTRACE("ARRAY: '['']'"); $$ = getarraynode(NULL, NULL);}
      | '['EXPR']'                               { yTRACE("ARRAY: '['EXPR']'"); $$ = getarraynode(NULL, $2);}
FUNC_CALL: ID '(' ID_LIST ')'                    { yTRACE("FUNC_CALL: ID '(' ID_LIST ')'"); $$ = getfunccallnode($1, $3);}
SCOPE: '{' STATEMENT_LIST '}'                    { yTRACE("SCOPE: '{' STATEMENT_LIST '}'"); $$ = getscopenode($2);}
FOR_BLOCK: FOR '(' DECLARATION_LIST ';' EXPR ';' STATEMENT ')' SCOPE { yTRACE("FOR_BLOCK: FOR '(' DECLARATION_LIST ';' EXPR ';' STATEMENT ')' SCOPE"); $$ = getforblocknode($3, $5, $7, $9);}
WHILE_BLOCK: WHILE '(' EXPR ')' SCOPE                                { yTRACE("WHILE '(' EXPR ')' SCOPE"); $$ = getwhileblocknode($3, $5);}
IF_BLOCK: IF '(' EXPR ')' SCOPE ELSE SCOPE                           { yTRACE("IF '(' EXPR ')' SCOPE ELSE SCOPE"); $$ = getifblocknode($3, $5, $7, NULL);}
          | IF '(' EXPR ')' SCOPE                                    { yTRACE("IF '(' EXPR ')' SCOPE"); $$ = getifblocknode($3, $5, NULL, NULL);}
          | IF '(' EXPR ')' SCOPE ELSE  IF_BLOCK                     { yTRACE("IF '(' EXPR ')' SCOPE ELSE  IF_BLOCK"); $$ = getifblocknode($3, $5, NULL, $7);}
EXPR: INT_C                                                          { yTRACE("EXPR: INT_C");  $$=getintnode($1);}
      | FLOAT_C                                                      { yTRACE("EXPR: FLOAT_C"); $$=getfloatnode($1);}
      | CHAR_C                                                       { yTRACE("EXPR: CHAR_C"); $$=getcharnode($1);}
      | STRING_C                                                     { yTRACE("EXPR: STRING_C"); $$=getstringnode($1);}             
      | '!' EXPR %prec '!'                                             { yTRACE("EXPR: '!' EXPR"); $$=getunaryopnode(NOT_N, $2);}
      | '-' EXPR %prec UMINUS                                          { yTRACE("EXPR: '-' EXPR"); $$=getunaryopnode(UMINUS_N, $2);}
      | EXPR '+' EXPR                                                  { yTRACE("EXPR: EXPR '+' EXPR"); $$=getbinaryopnode($1, ADD_N, $3);}
      | EXPR '-' EXPR                                                  { yTRACE("EXPR: EXPR '-' EXPR"); $$=getbinaryopnode($1, SUB_N, $3);}
      | EXPR '/' EXPR                                                  { yTRACE("EXPR: EXPR '/' EXPR"); $$=getbinaryopnode($1, DIV_N, $3);}
      | EXPR '*' EXPR                                                  { yTRACE("EXPR: EXPR '*' EXPR"); $$=getbinaryopnode($1, MUL_N, $3);}
      | EXPR '%' EXPR                                                  { yTRACE("EXPR: EXPR '%' EXPR"); $$=getbinaryopnode($1, MOD_N, $3);}
      | '(' EXPR ')'                                                   { yTRACE("EXPR: '(' EXPR ')'"); $$=$2;}
      | EXPR '^' EXPR                                                  { yTRACE("EXPR: EXPR '^' EXPR"); $$=getbinaryopnode($1, XOR_N, $3);}
      | EXPR AND EXPR                                                  { yTRACE("EXPR: EXPR AND EXPR"); $$=getbinaryopnode($1, AND_N, $3);}
      | EXPR OR EXPR                                                   { yTRACE("EXPR: EXPR OR EXPR"); $$=getbinaryopnode($1, OR_N, $3);}
      | EXPR GEQ EXPR                                                  { yTRACE("EXPR: EXPR GEQ EXPR"); $$=getbinaryopnode($1, GEQ_N, $3);}  
      | EXPR NEQ EXPR                                                  { yTRACE("EXPR: EXPR NEQ EXPR"); $$=getbinaryopnode($1, NEQ_N, $3);}
      | EXPR LEQ EXPR                                                  { yTRACE("EXPR: EXPR LEQ EXPR"); $$=getbinaryopnode($1, LEQ_N, $3);}
      | EXPR EQ EXPR                                                   { yTRACE("EXPR: EXPR EQ EXPR"); $$=getbinaryopnode($1, EQ_N, $3);}
      | EXPR '>' EXPR                                                  { yTRACE("EXPR: EXPR '>' EXPR"); $$=getbinaryopnode($1, GRT_N, $3);}
      | EXPR '<' EXPR                                                  { yTRACE("EXPR: EXPR '<' EXPR"); $$=getbinaryopnode($1, LSS_N, $3);}
      | EXPR '?' EXPR ':' EXPR %prec '?'                               { yTRACE("EXPR: EXPR '?' EXPR ':' EXPR"); $$=getternaryopnode($1, $3, $5);}
      | TRUE                                                           { yTRACE("EXPR: TRUE"); $$=getboolnode(1);}
      | FALSE                                                          { yTRACE("EXPR: FALSE"); $$=getboolnode(0);}
      | IDEN                                                           { yTRACE("EXPR: IDEN"); $$=getexpridnode($1);}
      | FUNC_CALL                                                      { yTRACE("EXPR: FUNC_CALL"); $$=getexprfnnode($1);}
      | NULL_T                                                         { yTRACE("EXPR: NULL_T"); $$=getnullnode(1);}
      | EOF_T                                                          { yTRACE("EXPR: EOF_T"); $$=geteofnode(1);}
PRINT_STMT: PRINT '(' STRING_C ')'                                     { yTRACE("PRINT_STMT: PRINT '(' STRING_C ')'"); $$=getprintstmtnode($3, NULL);}
            | PRINT '(' STRING_C ',' ID_LIST ')'                       { yTRACE("PRINT_STMT: PRINT '(' STRING_C ',' ID_LIST ')'"); $$=getprintstmtnode($3, NULL);}
            
TYPE: INT                                                              {yTRACE("TYPE: INT"); $$=gettypenode(INT_N);}
      | FLOAT                                                          {yTRACE("TYPE: FLOAT"); $$=gettypenode(FLOAT_N);}
      | CHAR                                                           {yTRACE("TYPE: CHAR"); $$=gettypenode(CHAR_N);}
      | BOOL                                                           {yTRACE("TYPE: BOOL"); $$=gettypenode(BOOL_N);}
      | FILE_T                                                         {yTRACE("TYPE: FILE_T"); $$=gettypenode(FILE_T_N);}
      | VOID                                                           {yTRACE("TYPE: VOID"); $$=(gettypenode(VOID_N));}
%%
void yyerror(const char *s) {
  printf("error:%s on line:%d\n", s, line_num);
  //exit(-1);
}

int main(int argc, char** argv) {
  FILE *myfile = fopen(argv[1], "r");
  tracerfile = fopen(argv[2], "w");
  tokenfile = fopen(argv[3], "w");
  printf("%s\n",argv[1]);

  if (!myfile) {
    printf("I can't open a.snazzle.file!\n");
    return -1;
  }
  yyin = myfile;

  do {
    yyparse();

  } while (!feof(yyin));
}