%{
  #include <stdio.h>
  #include <stdlib.h>
  // stuff from flex that bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  extern int line_num;
  void yyerror(const char *s);
%}
%define parse.error verbose
%union{
  int int_literal_val;
  float float_literal_val;
  char *string_literal_val;
  char *char_literal_val;
  char *identifier_val;
  char *arithmaticop_val;
  char *unaryop_val;
  char *assignop_val;
  char *assign_val;
  char *conditionalop_val;
  char *relationalop_val;
  char *error;
}
%glr-parser

%token SEMI_COLON COMMA START_BLOCK CLOSE_BLOCK OPEN_PARENTHESIS CLOSE_PARENTHESIS OPEN_SQUARE_BRACKET CLOSE_SQUARE_BRACKET NEGATION INT FLOAT CHAR BOOL VOID IF ELSE BREAK CONTINUE FOR WHILE MAIN CONST TRUE FALSE RETURN ENDL FILEP EOFP NULLP
%token <int_literal_val> INT_LITERAL
%token <float_literal_val> FLOAT_LITERAL
%token <string_literal_val> STRING_LITERAL
%token <char_literal_val> CHAR_LITERAL
%token <identifier_val> IDENTIFIER
%token <arithmaticop_val> ARITHMATICOP
%token <unaryop_val> UNARYOP
%token <conditionalop_val> CONDITIONALOP
%token <relationalop_val> RELATIONALOP
%token <assignop_val> ASSIGNMENTOP
%token <assign_val> ASSIGNMENT
%left RELATIONALOP
%left OP_MINUS OP_PLUS
%left ARITHMATICOP
%left NEGATION
%left UNARY_MINUS

%%

PROGRAM:    STATEMENT_LIST  FUNCTION_LIST
          | FUNCTION_LIST  
FUNCTION_LIST: FUNCTION 
               | FUNCTION_LIST FUNCTION 
FUNCTION: TYPE IDENTIFIER OPEN_PARENTHESIS VARIABLE_LIST CLOSE_PARENTHESIS START_BLOCK STATEMENT_LIST CLOSE_BLOCK
VARIABLE_LIST: VARIABLE 
               | VARIABLE_LIST COMMA VARIABLE
               |
VARIABLE: TYPE IDENT
STATEMENT_LIST: STATEMENT_LIST STATEMENT
                | STATEMENT
STATEMENT: DECLARATION_LIST SEMI_COLON
          | RETURN VAR SEMI_COLON
          | BREAK SEMI_COLON
          | CONTINUE SEMI_COLON
          | LOOP_BLOCK 
          | IF_ELSE_BLOCK
          | EXPR_TT SEMI_COLON
          | FUNC_CALL SEMI_COLON
IF_ELSE_BLOCK: IF OPEN_PARENTHESIS EXPR_LIST CLOSE_PARENTHESIS START_BLOCK STATEMENT_LIST CLOSE_BLOCK ELSE START_BLOCK STATEMENT_LIST CLOSE_BLOCK
               | IF OPEN_PARENTHESIS EXPR_LIST CLOSE_PARENTHESIS STATEMENT ELSE STATEMENT
               | IF OPEN_PARENTHESIS EXPR_LIST CLOSE_PARENTHESIS STATEMENT
               | IF OPEN_PARENTHESIS EXPR_LIST CLOSE_PARENTHESIS START_BLOCK STATEMENT_LIST CLOSE_BLOCK
LOOP_BLOCK: FOR OPEN_PARENTHESIS DECLARATION_LIST SEMI_COLON EXPR_LIST SEMI_COLON EXPR_TT CLOSE_PARENTHESIS START_BLOCK STATEMENT_LIST CLOSE_BLOCK
           | FOR OPEN_PARENTHESIS DECLARATION_LIST SEMI_COLON EXPR_LIST SEMI_COLON EXPR_TT CLOSE_PARENTHESIS  STATEMENT
           | WHILE OPEN_PARENTHESIS EXPR_LIST CLOSE_PARENTHESIS START_BLOCK STATEMENT_LIST CLOSE_BLOCK 
FUNC_CALL: IDENTIFIER OPEN_PARENTHESIS STRING_LITERAL COMMA IDENTIFIER_LIST CLOSE_PARENTHESIS 
          | IDENTIFIER OPEN_PARENTHESIS STRING_LITERAL CLOSE_PARENTHESIS 
DECLARATION_LIST: TYPE IDENTIFIER_LIST 
IDENTIFIER_LIST: IDENTIFIER_LIST COMMA IDENT
                 | IDENTIFIER_LIST COMMA IDENT ASSIGNMENT EXPR 
                 | IDENT
                 | IDENT ASSIGNMENT EXPR
IDENT: IDENTIFIER    
      | IDENTIFIER OPEN_SQUARE_BRACKET VAR CLOSE_SQUARE_BRACKET
      | IDENTIFIER OPEN_PARENTHESIS IDENTIFIER_LIST CLOSE_PARENTHESIS
      | IDENTIFIER OPEN_SQUARE_BRACKET VAR CLOSE_SQUARE_BRACKET OPEN_SQUARE_BRACKET VAR CLOSE_SQUARE_BRACKET 
VAR: IDENT
     | LITERAL 
     |
LITERAL: INT_LITERAL    
         | FLOAT_LITERAL 
         | STRING_LITERAL
         | CHAR_LITERAL
         | NULLP
         | EOFP
         | TRUE
         | FALSE
EXPR_LIST: EXPR 
           | EXPR_LIST RELATIONALOP EXPR

EXPR: EXPR_T 
      | EXPR CONDITIONALOP EXPR_T     
EXPR_T: IDENT
      | LITERAL
      | EXPR_T ARITHMATICOP EXPR_T
      | EXPR_T OP_MINUS EXPR_T
      | EXPR_T OP_PLUS EXPR_T
      | OPEN_PARENTHESIS EXPR CLOSE_PARENTHESIS
      | IDENT UNARYOP 
      | UNARYOP IDENT
TYPE: INT
      | FLOAT
      | CHAR
      | BOOL
      | VOID
      | FILEP
EXPR_TT: IDENT ASSIGNMENTOP EXPR_LIST
         | IDENT ASSIGNMENT EXPR_LIST
         | EXPR_LIST

%%

void yyerror(const char *s) {
  printf("error:%s on line:%d\n", s, line_num);
  // might as well halt now:
  //exit(-1);
}

int main(int argc, char** argv) {
  // open a file handle to a particular file:
  FILE *myfile = fopen(argv[1], "r");
  printf("%s\n",argv[1]);
  // make sure it's valid:
  if (!myfile) {
    printf("I can't open a.snazzle.file!\n");
    return -1;
  }
  // Set flex to read from it instead of defaulting to STDIN:
  yyin = myfile;

  // Parse through the input:
  do {
    yyparse();

  } while (!feof(yyin));
}