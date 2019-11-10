%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <float.h>
    #include <math.h>
    #include <string.h>
    #include "parser.tab.h"
    FILE *tokenfile;
    //#define YY_USER_INIT { yyin = inputFile; }
    //#define yyinput      input
    #define yTRACE(x)    { fprintf(tokenfile, "TOKEN: %s\n", yytext); }
    #define yERROR(x)    { printf("\nLEXICAL ERROR, LINE %d: %s\n", line_num, x); }
    #define yOUT(x)      { yTRACE(x); return x; }

    extern int yylex();
    int line_num = 1;

    int CheckInt();
  
%}
%option noyywrap
DIGIT                         [0-9]
Id                            [A-Za-z_][A-Za-z0-9_]*
Qstring                       \"(\"\"|[^\"\n])*[\"]
%%

[ \t]                         {}
[\n]                          { line_num++;}
\+\+                          { yOUT(INC); }
\-\-                          { yOUT(DEC); }
[\+\-\*\/%]                   { yOUT(yytext[0]);}
[()[\]{}]                     { yOUT(yytext[0]);}
[<>=!]                        { yOUT(yytext[0]); }
";"                           { yOUT(yytext[0]); }
","                           { yOUT(yytext[0]); }
"&&"|and|AND                          { yOUT(AND); }
"||"|or|OR                        { yOUT(OR); }
"!="                          { yOUT(NEQ); }
"<="                          { yOUT(LEQ); }
">="                          { yOUT(GEQ); }
"=="                          { yOUT(EQ); }
"+="                          { yOUT(PEQ); }
"-="                          { yOUT(MEQ); }
"*="                          { yOUT(MULTEQ);}
"/="                          { yOUT(DIVEQ);}
"%="                          { yOUT(MODEQ)}

const                         { yOUT(CONST); }
bool                          { yOUT(BOOL); }
int                           { yOUT(INT); }
float                         { yOUT(FLOAT); }
char                          { yOUT(CHAR);}
void                          { yOUT(VOID);}
FILE\*                        { yOUT(FILE_T);}
NULL                          { yOUT(NULL_T);}
EOF                           { yOUT(EOF_T);}
printf                        { yOUT(PRINT);}

if                            { yOUT(IF); }
else                          { yOUT(ELSE); }
for                           { yOUT(FOR); }
while                         { yOUT(WHILE); }
break                         { yOUT(BREAK);}
continue                      { yOUT(CONTINUE);}
return                        { yOUT(RETURN); }

true                          { yOUT(TRUE);}
false                         { yOUT(FALSE);}
               
{DIGIT}+                      { if(CheckInt()) { yylval.as_int = atoi(yytext); yOUT(INT_C); } yyterminate(); }
{DIGIT}.{DIGIT}+              { yylval.as_float = atof(yytext);  yOUT(FLOAT_C); } 
{Id}                          { yylval.as_id = strdup(yytext); yOUT(ID);}
{Qstring} {yylval.as_str = strdup(yytext); yOUT(STRING_C);}
"\'\\n\'"|"\'\\t\'"|"\'\\\\\'"|"\'\\\'\'"|"\'\\\"\'"|"\'"."\'" {yylval.as_char = strdup(yytext); yOUT(CHAR_C);}
.                             { yERROR("Unknown token");  yyterminate(); }
%%

int CheckInt(void) {
    int i;
    for (i=0; yytext[i]=='0'; i++);
    if (((yyleng - i) > 5) || (atoi(yytext) > INT_MAX)) {
        return 0;
        }
    else {
        return 1;
    }
}




