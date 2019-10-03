%{
  #include <iostream>
  using namespace std;
  extern int yylex();
%}
%%
[ \t\n]          ;
[a-zA-Z]+_[a-zA-Z0-9]+@[a-z]+.[a-z]_[0-9] {}
[0-9]+\.[0-9]+   { cout << "Found a floating-point number:" << yytext << endl; }
[0-9]+           { cout << "Found an integer:" << yytext << endl; }
[a-zA-Z0-9]+     { cout << "Found a string: " << yytext << endl; }
.                ;
%%
int main(int, char**) {
  
  // open a file handle to a particular file:
  FILE *myfile = fopen("names.csv", "r");
  // make sure it's valid:
  if (!myfile) {
    cout << "I can't open file!" << endl;
    return -1;
  }
  // set lex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // lex through the input:
  while(yylex());
}