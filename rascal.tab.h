/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_RASCAL_TAB_H_INCLUDED
# define YY_YY_RASCAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 25 "rascal.y"

    #include "ast.hpp"
    #include <vector>

#line 54 "rascal.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUM = 259,                     /* NUM  */
    TK_PROGRAM = 260,              /* TK_PROGRAM  */
    TK_PROCEDURE = 261,            /* TK_PROCEDURE  */
    TK_FUNCTION = 262,             /* TK_FUNCTION  */
    TK_VAR = 263,                  /* TK_VAR  */
    TK_BEGIN = 264,                /* TK_BEGIN  */
    TK_END = 265,                  /* TK_END  */
    TK_INTEGER = 266,              /* TK_INTEGER  */
    TK_BOOLEAN = 267,              /* TK_BOOLEAN  */
    TK_FALSE = 268,                /* TK_FALSE  */
    TK_TRUE = 269,                 /* TK_TRUE  */
    TK_WHILE = 270,                /* TK_WHILE  */
    TK_DO = 271,                   /* TK_DO  */
    TK_IF = 272,                   /* TK_IF  */
    TK_THEN = 273,                 /* TK_THEN  */
    TK_ELSE = 274,                 /* TK_ELSE  */
    TK_READ = 275,                 /* TK_READ  */
    TK_WRITE = 276,                /* TK_WRITE  */
    TK_AND = 277,                  /* TK_AND  */
    TK_OR = 278,                   /* TK_OR  */
    TK_NOT = 279,                  /* TK_NOT  */
    TK_DIV = 280,                  /* TK_DIV  */
    TK_ABREPAR = 281,              /* TK_ABREPAR  */
    TK_FECHAPAR = 282,             /* TK_FECHAPAR  */
    TK_PTVG = 283,                 /* TK_PTVG  */
    TK_IGUAL = 284,                /* TK_IGUAL  */
    TK_DIF = 285,                  /* TK_DIF  */
    TK_MENOR = 286,                /* TK_MENOR  */
    TK_MENOR_IG = 287,             /* TK_MENOR_IG  */
    TK_MAIOR = 288,                /* TK_MAIOR  */
    TK_MAIOR_IG = 289,             /* TK_MAIOR_IG  */
    TK_ADD = 290,                  /* TK_ADD  */
    TK_SUB = 291,                  /* TK_SUB  */
    TK_MUL = 292,                  /* TK_MUL  */
    TK_ATRIB = 293,                /* TK_ATRIB  */
    TK_DOISPT = 294,               /* TK_DOISPT  */
    TK_VG = 295,                   /* TK_VG  */
    TK_PT = 296                    /* TK_PT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "rascal.y"

    int ival;
    char *sval;

    Programa* ptr_programa;
    Bloco* ptr_bloco;
    BlocoSub* ptr_bloco_sub;
    
    DeclaracaoVar* ptr_decl_var;
    std::vector<DeclaracaoVar*>* vec_decl_var;
    
    DeclaracaoSub* ptr_decl_sub;
    std::vector<DeclaracaoSub*>* vec_decl_sub;
    
    Comando* ptr_comando;
    std::vector<Comando*>* vec_comando;
    
    Expressao* ptr_expr;
    std::vector<Expressao*>* vec_expr;
    std::vector<std::string>* vec_str;
    
    TipoVar tipo_var;
    OperadorBinario op_bin;

#line 137 "rascal.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RASCAL_TAB_H_INCLUDED  */
