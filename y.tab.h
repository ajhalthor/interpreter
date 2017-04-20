/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    COMMA = 258,
    SINGLE_QUOTES = 259,
    SEMI_COLON = 260,
    EQUALS = 261,
    BRACKET_OPEN = 262,
    BRACKET_CLOSE = 263,
    CURLY_BRACE_OPEN = 264,
    CURLY_BRACE_CLOSE = 265,
    BIG_BRACKET_OPEN = 266,
    BIG_BRACKET_CLOSE = 267,
    CHARACTER_VALUE = 268,
    INTEGER_VALUE = 269,
    FLOAT_VALUE = 270,
    STRING_VALUE = 271,
    INT = 272,
    FLOAT = 273,
    STRING = 274,
    DATA_TYPE = 275,
    IDENTIFIER = 276,
    ARRAY_IDENTIFIER = 277,
    STRUCT = 278
  };
#endif
/* Tokens.  */
#define COMMA 258
#define SINGLE_QUOTES 259
#define SEMI_COLON 260
#define EQUALS 261
#define BRACKET_OPEN 262
#define BRACKET_CLOSE 263
#define CURLY_BRACE_OPEN 264
#define CURLY_BRACE_CLOSE 265
#define BIG_BRACKET_OPEN 266
#define BIG_BRACKET_CLOSE 267
#define CHARACTER_VALUE 268
#define INTEGER_VALUE 269
#define FLOAT_VALUE 270
#define STRING_VALUE 271
#define INT 272
#define FLOAT 273
#define STRING 274
#define DATA_TYPE 275
#define IDENTIFIER 276
#define ARRAY_IDENTIFIER 277
#define STRUCT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "syntax2.y" /* yacc.c:1909  */

	int intVal;
	char* dataType;
	char* strVal;
	float floatVal;
	char charVal;

#line 108 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
