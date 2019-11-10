/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_C = 258,
    FLOAT_C = 259,
    CHAR_C = 260,
    STRING_C = 261,
    ID = 262,
    CONST = 263,
    BOOL = 264,
    INT = 265,
    FLOAT = 266,
    CHAR = 267,
    FILE_T = 268,
    NULL_T = 269,
    EOF_T = 270,
    VOID = 271,
    IF = 272,
    ELSE = 273,
    FOR = 274,
    WHILE = 275,
    BREAK = 276,
    CONTINUE = 277,
    TRUE = 278,
    FALSE = 279,
    RETURN = 280,
    PRINT = 281,
    AND = 282,
    OR = 283,
    NEQ = 284,
    LEQ = 285,
    GEQ = 286,
    EQ = 287,
    UMINUS = 288,
    INC = 289,
    DEC = 290,
    PEQ = 291,
    MEQ = 292,
    MULTEQ = 293,
    DIVEQ = 294,
    MODEQ = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parser.y" /* glr.c:197  */

  int as_int;
  float as_float;
  char *as_char;
  char *as_str;
  char *as_id;
  struct ASTNODE *ast_node;

#line 104 "parser.tab.h" /* glr.c:197  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
