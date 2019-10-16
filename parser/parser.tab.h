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
    SEMI_COLON = 258,
    COMMA = 259,
    START_BLOCK = 260,
    CLOSE_BLOCK = 261,
    OPEN_PARENTHESIS = 262,
    CLOSE_PARENTHESIS = 263,
    OPEN_SQUARE_BRACKET = 264,
    CLOSE_SQUARE_BRACKET = 265,
    NEGATION = 266,
    INT = 267,
    FLOAT = 268,
    CHAR = 269,
    BOOL = 270,
    VOID = 271,
    IF = 272,
    ELSE = 273,
    BREAK = 274,
    CONTINUE = 275,
    FOR = 276,
    WHILE = 277,
    MAIN = 278,
    CONST = 279,
    TRUE = 280,
    FALSE = 281,
    RETURN = 282,
    ENDL = 283,
    FILEP = 284,
    EOFP = 285,
    NULLP = 286,
    INT_LITERAL = 287,
    FLOAT_LITERAL = 288,
    STRING_LITERAL = 289,
    CHAR_LITERAL = 290,
    IDENTIFIER = 291,
    ARITHMATICOP = 292,
    UNARYOP = 293,
    CONDITIONALOP = 294,
    RELATIONALOP = 295,
    ASSIGNMENTOP = 296,
    ASSIGNMENT = 297,
    OP_MINUS = 298,
    OP_PLUS = 299,
    UNARY_MINUS = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "parser.y" /* glr.c:197  */

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

#line 115 "parser.tab.h" /* glr.c:197  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
