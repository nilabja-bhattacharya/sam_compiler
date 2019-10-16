%{
  #include <stdio.h>
  extern int yylex();
  #include "parser.tab.h"
  int line_num = 1;
%}
%%
[ \t]+         ;
int       {printf("%s\n", yytext); return INT;}
char      {printf("%s\n", yytext);return CHAR;}
float     {printf("%s\n", yytext);return FLOAT;}
bool      {printf("%s\n", yytext);return BOOL;}
void      {printf("%s\n", yytext);return VOID;}
if        {printf("%s\n", yytext);return IF;}
else      {printf("%s\n", yytext);return ELSE;}
break     {printf("%s\n", yytext);return BREAK;}
continue  {printf("%s\n", yytext);return CONTINUE;}
for       {printf("%s\n", yytext);return FOR;}
while     {printf("%s\n", yytext);return WHILE;}
main      {printf("%s\n", yytext);return MAIN;}
const     {printf("%s\n", yytext);return CONST;}
true      {printf("%s\n", yytext);return TRUE;}
false     {printf("%s\n", yytext);return FALSE;}
return    {printf("%s\n", yytext);return RETURN;}
FILE\*     {printf("%s\n", yytext);return FILEP;}
NULL      {printf("%s\n", yytext);return NULLP;}
EOF       {printf("%s\n", yytext);return EOFP;}
\/|\*|% {printf("%s\n", yytext);yylval.arithmaticop_val = strdup(yytext); return ARITHMATICOP;}
\>|\<|\>\=|\<\=|\!\=|\=\= {printf("%s\n", yytext);yylval.conditionalop_val = strdup(yytext); return CONDITIONALOP;}
and|or|&&|\|\| {printf("%s\n", yytext);yylval.relationalop_val = strdup(yytext); return RELATIONALOP;}
[\+\-\*\/]\= {printf("%s\n", yytext);yylval.assignop_val = strdup(yytext); return ASSIGNMENTOP;}
\= {printf("%s\n", yytext);yylval.assign_val = strdup(yytext); return ASSIGNMENT;}
\+\+|\-\- {printf("%s\n", yytext);yylval.unaryop_val = strdup(yytext); return UNARYOP;}
\!                  {printf("%s\n", yytext);return NEGATION;}
\+                  {printf("%s\n", yytext);return OP_PLUS;}
\-                  {printf("%s\n", yytext);return OP_MINUS;}
\;									{printf("%s\n", yytext);return SEMI_COLON;}
\,									{printf("%s\n", yytext);return COMMA;}
\{									{printf("%s\n", yytext);return START_BLOCK;}
\}									{printf("%s\n", yytext);return CLOSE_BLOCK;}
\(									{printf("%s\n", yytext);return OPEN_PARENTHESIS;}
\)									{printf("%s\n", yytext);return CLOSE_PARENTHESIS;}
\[									{printf("%s\n", yytext);return OPEN_SQUARE_BRACKET;}
\]									{printf("%s\n", yytext);return CLOSE_SQUARE_BRACKET;}
[a-zA-Z][a-zA-Z0-9]* {printf("%s\n", yytext);yylval.identifier_val = strdup(yytext); return IDENTIFIER;}
[0-9]+ {printf("%s\n", yytext);yylval.int_literal_val = atoi(yytext); return INT_LITERAL;}
[0-9]+.[0-9]+ {printf("%s\n", yytext);yylval.float_literal_val = atof(yytext); return FLOAT_LITERAL;}
\"(\\.|[^\\"])*\" {printf("%s\n", yytext);yylval.string_literal_val = strdup(yytext); return STRING_LITERAL;}
"\'\\n\'"|"\'\\t\'"|"\'\\\\\'"|"\'\\\'\'"|"\'\\\"\'"|"\'"."\'" {printf("%s\n", yytext);yylval.char_literal_val = strdup(yytext); return CHAR_LITERAL;}
\n                  { ++line_num;}
.									  {printf("%s",yytext);}
%%
