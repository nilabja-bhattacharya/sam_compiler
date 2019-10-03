%{
  #include <iostream>
  using namespace std;
  extern int yylex();
%}
%%
[ \t\n]          ;
#DEFINE {return DEFINE}
int|char|if|else|break|for|while|main|break|continue|void|bool|true|false {return KEYWORD;}
[a-zA-Z][a-zA-Z0-9]* {yylval.sval = strdup(yytext); return VARIABLE;}
[0-9]+ {return INTEGER}
"[a-zA-Z0-9]+" {return STRING}
[+-/*] {return ARITHMATICOP}
>|<|>=|<=|!=|== {return CONDITIONALOP}
= {return ASSIGNMENTOP}
[+-]= {return OPNASSIGN}
++|--|! {return UNARYOP}
.                ;
%%
int main(int, char**) {
  FILE *myfile = fopen("names.csv", "r");
  if (!myfile) {
    cout << "I can't open file!" << endl;
    return -1;
  }
  yyin = myfile;
  while(yylex());
}