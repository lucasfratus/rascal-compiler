/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "rascal.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include "ast.hpp"
#include "semantico.hpp"
#include "gerador.hpp"
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

int yylex(void);

Programa* raiz = NULL;


#line 95 "rascal.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "rascal.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_TK_PROGRAM = 5,                 /* TK_PROGRAM  */
  YYSYMBOL_TK_PROCEDURE = 6,               /* TK_PROCEDURE  */
  YYSYMBOL_TK_FUNCTION = 7,                /* TK_FUNCTION  */
  YYSYMBOL_TK_VAR = 8,                     /* TK_VAR  */
  YYSYMBOL_TK_BEGIN = 9,                   /* TK_BEGIN  */
  YYSYMBOL_TK_END = 10,                    /* TK_END  */
  YYSYMBOL_TK_INTEGER = 11,                /* TK_INTEGER  */
  YYSYMBOL_TK_BOOLEAN = 12,                /* TK_BOOLEAN  */
  YYSYMBOL_TK_FALSE = 13,                  /* TK_FALSE  */
  YYSYMBOL_TK_TRUE = 14,                   /* TK_TRUE  */
  YYSYMBOL_TK_WHILE = 15,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 16,                     /* TK_DO  */
  YYSYMBOL_TK_IF = 17,                     /* TK_IF  */
  YYSYMBOL_TK_THEN = 18,                   /* TK_THEN  */
  YYSYMBOL_TK_ELSE = 19,                   /* TK_ELSE  */
  YYSYMBOL_TK_READ = 20,                   /* TK_READ  */
  YYSYMBOL_TK_WRITE = 21,                  /* TK_WRITE  */
  YYSYMBOL_TK_AND = 22,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 23,                     /* TK_OR  */
  YYSYMBOL_TK_NOT = 24,                    /* TK_NOT  */
  YYSYMBOL_TK_DIV = 25,                    /* TK_DIV  */
  YYSYMBOL_TK_ABREPAR = 26,                /* TK_ABREPAR  */
  YYSYMBOL_TK_FECHAPAR = 27,               /* TK_FECHAPAR  */
  YYSYMBOL_TK_PTVG = 28,                   /* TK_PTVG  */
  YYSYMBOL_TK_IGUAL = 29,                  /* TK_IGUAL  */
  YYSYMBOL_TK_DIF = 30,                    /* TK_DIF  */
  YYSYMBOL_TK_MENOR = 31,                  /* TK_MENOR  */
  YYSYMBOL_TK_MENOR_IG = 32,               /* TK_MENOR_IG  */
  YYSYMBOL_TK_MAIOR = 33,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MAIOR_IG = 34,               /* TK_MAIOR_IG  */
  YYSYMBOL_TK_ADD = 35,                    /* TK_ADD  */
  YYSYMBOL_TK_SUB = 36,                    /* TK_SUB  */
  YYSYMBOL_TK_MUL = 37,                    /* TK_MUL  */
  YYSYMBOL_TK_ATRIB = 38,                  /* TK_ATRIB  */
  YYSYMBOL_TK_DOISPT = 39,                 /* TK_DOISPT  */
  YYSYMBOL_TK_VG = 40,                     /* TK_VG  */
  YYSYMBOL_TK_PT = 41,                     /* TK_PT  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_bloco = 44,                     /* bloco  */
  YYSYMBOL_possivel_secao_variaveis = 45,  /* possivel_secao_variaveis  */
  YYSYMBOL_secao_declaracao_variaveis = 46, /* secao_declaracao_variaveis  */
  YYSYMBOL_declaracao_tipada = 47,         /* declaracao_tipada  */
  YYSYMBOL_lista_declaracao_variaveis = 48, /* lista_declaracao_variaveis  */
  YYSYMBOL_lista_identificadores = 49,     /* lista_identificadores  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_possivel_secao_subrotinas = 51, /* possivel_secao_subrotinas  */
  YYSYMBOL_secao_declaracao_subrotinas = 52, /* secao_declaracao_subrotinas  */
  YYSYMBOL_lista_declaracao_subrotinas = 53, /* lista_declaracao_subrotinas  */
  YYSYMBOL_declaracao_subrotina = 54,      /* declaracao_subrotina  */
  YYSYMBOL_declaracao_procedimento = 55,   /* declaracao_procedimento  */
  YYSYMBOL_possivel_parametros_formais = 56, /* possivel_parametros_formais  */
  YYSYMBOL_parametros_formais = 57,        /* parametros_formais  */
  YYSYMBOL_lista_declaracao_parametros = 58, /* lista_declaracao_parametros  */
  YYSYMBOL_declaracao_funcao = 59,         /* declaracao_funcao  */
  YYSYMBOL_bloco_subrotina = 60,           /* bloco_subrotina  */
  YYSYMBOL_comando_composto = 61,          /* comando_composto  */
  YYSYMBOL_lista_comandos = 62,            /* lista_comandos  */
  YYSYMBOL_comando = 63,                   /* comando  */
  YYSYMBOL_atribuicao = 64,                /* atribuicao  */
  YYSYMBOL_condicional = 65,               /* condicional  */
  YYSYMBOL_repeticao = 66,                 /* repeticao  */
  YYSYMBOL_leitura = 67,                   /* leitura  */
  YYSYMBOL_escrita = 68,                   /* escrita  */
  YYSYMBOL_lista_expressoes_nao_vazia = 69, /* lista_expressoes_nao_vazia  */
  YYSYMBOL_lista_expressoes = 70,          /* lista_expressoes  */
  YYSYMBOL_expressao = 71,                 /* expressao  */
  YYSYMBOL_relacao = 72,                   /* relacao  */
  YYSYMBOL_expressao_simples = 73,         /* expressao_simples  */
  YYSYMBOL_termo = 74,                     /* termo  */
  YYSYMBOL_fator = 75,                     /* fator  */
  YYSYMBOL_variavel = 76,                  /* variavel  */
  YYSYMBOL_logico = 77,                    /* logico  */
  YYSYMBOL_chamada_geral = 78              /* chamada_geral  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,   101,   114,   117,   124,   131,   139,   144,
     152,   157,   165,   166,   171,   174,   181,   185,   190,   198,
     199,   203,   211,   212,   216,   221,   226,   235,   243,   253,
     257,   262,   270,   271,   279,   280,   281,   282,   283,   291,
     299,   303,   310,   317,   325,   334,   339,   347,   348,   352,
     353,   360,   361,   362,   363,   364,   365,   369,   370,   371,
     375,   379,   383,   390,   391,   395,   399,   406,   407,   408,
     409,   410,   414,   418,   422,   423,   427
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM",
  "TK_PROGRAM", "TK_PROCEDURE", "TK_FUNCTION", "TK_VAR", "TK_BEGIN",
  "TK_END", "TK_INTEGER", "TK_BOOLEAN", "TK_FALSE", "TK_TRUE", "TK_WHILE",
  "TK_DO", "TK_IF", "TK_THEN", "TK_ELSE", "TK_READ", "TK_WRITE", "TK_AND",
  "TK_OR", "TK_NOT", "TK_DIV", "TK_ABREPAR", "TK_FECHAPAR", "TK_PTVG",
  "TK_IGUAL", "TK_DIF", "TK_MENOR", "TK_MENOR_IG", "TK_MAIOR",
  "TK_MAIOR_IG", "TK_ADD", "TK_SUB", "TK_MUL", "TK_ATRIB", "TK_DOISPT",
  "TK_VG", "TK_PT", "$accept", "programa", "bloco",
  "possivel_secao_variaveis", "secao_declaracao_variaveis",
  "declaracao_tipada", "lista_declaracao_variaveis",
  "lista_identificadores", "tipo", "possivel_secao_subrotinas",
  "secao_declaracao_subrotinas", "lista_declaracao_subrotinas",
  "declaracao_subrotina", "declaracao_procedimento",
  "possivel_parametros_formais", "parametros_formais",
  "lista_declaracao_parametros", "declaracao_funcao", "bloco_subrotina",
  "comando_composto", "lista_comandos", "comando", "atribuicao",
  "condicional", "repeticao", "leitura", "escrita",
  "lista_expressoes_nao_vazia", "lista_expressoes", "expressao", "relacao",
  "expressao_simples", "termo", "fator", "variavel", "logico",
  "chamada_geral", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,    22,    39,    13,   -78,    36,    51,    31,    59,   -78,
     -78,    45,    51,   -25,   -78,    71,    75,    70,   -78,    59,
      52,   -78,   -78,   -78,    63,    49,    79,    66,    66,    42,
     -78,    65,   -78,   -78,   -78,   -78,   -78,   -78,    51,    67,
     -78,    55,    26,    14,    14,    72,    73,   -78,     3,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,    41,    36,
      49,    14,    14,    74,   -78,   -78,   -78,     8,    14,     8,
       8,    80,    54,    33,   -78,   -78,   -78,   -78,    83,    51,
      14,   -78,    42,   -78,    51,    70,   -78,    69,    62,    76,
     -78,   -78,   -78,    78,    33,    33,    42,     8,   -78,   -78,
     -78,   -78,   -78,   -78,     8,     8,    14,     8,     8,     8,
      42,   -17,   -11,   -78,   -78,   -78,    36,    14,   -78,   -78,
     -78,    33,    33,    33,     1,   -78,   -78,   -78,    87,   -78,
     -78,   -78,   -78,    42,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,    14,     5,
      10,     0,     6,     0,     2,     0,     0,     0,    15,    16,
       0,    19,    20,     8,     0,     0,     0,    22,    22,     0,
       3,     0,    17,     9,    13,    12,     7,    11,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    38,     0,    30,
      32,    34,    35,    36,    37,    33,    18,    25,     0,     4,
       0,    47,     0,    73,    68,    74,    75,     0,     0,     0,
       0,     0,    49,    57,    63,    67,    69,    70,     0,     0,
       0,    29,     0,    24,     0,     0,    21,     0,    48,     0,
      45,    39,    71,     0,    58,    59,     0,     0,    51,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    26,    28,     4,     0,    76,    72,
      42,    62,    60,    61,    50,    66,    65,    64,    40,    43,
      44,    27,    46,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   102,   -78,    -8,   -78,    29,    50,   -78,
     -78,   -78,    90,   -78,    84,   -78,   -78,   -78,    -5,   -14,
     -78,   -77,   -78,   -78,   -78,   -78,   -78,    34,   -78,   -42,
     -78,     7,   -62,   -61,   -78,   -78,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    85,     9,    11,    12,    13,    36,    17,
      18,    19,    20,    21,    39,    40,    58,    22,    86,    47,
      48,    49,    50,    51,    52,    53,    54,    88,    89,    90,
     106,    72,    73,    74,    75,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    71,    78,    30,    24,   113,    92,    94,    95,     1,
     129,    63,    64,    81,    25,    26,   130,    63,    64,   120,
      91,    65,    66,    26,    97,     3,    93,    65,    66,   117,
      57,    82,    67,   128,    68,   121,   104,   105,    67,     4,
      68,     5,   122,   123,     6,    42,   125,   126,   127,    69,
      70,    29,    61,    55,    10,   107,   134,    43,   108,    44,
      34,    35,    45,    46,    62,    15,    16,    55,    83,    84,
     109,   115,    14,    23,    27,   132,   114,    97,    28,    29,
      32,    55,    37,    98,    99,   100,   101,   102,   103,   104,
     105,    33,    38,    56,    60,    59,    96,   116,    79,    80,
      61,   110,   117,   118,    55,   119,   133,     8,   111,    31,
      87,   131,    41,   124,   112
};

static const yytype_uint8 yycheck[] =
{
      29,    43,    44,    17,    12,    82,    67,    69,    70,     5,
      27,     3,     4,    10,    39,    40,    27,     3,     4,    96,
      62,    13,    14,    40,    23,     3,    68,    13,    14,    40,
      38,    28,    24,   110,    26,    97,    35,    36,    24,     0,
      26,    28,   104,   105,     8,     3,   107,   108,   109,    35,
      36,     9,    26,    82,     3,    22,   133,    15,    25,    17,
      11,    12,    20,    21,    38,     6,     7,    96,    27,    28,
      37,    85,    41,    28,     3,   117,    84,    23,     3,     9,
      28,   110,     3,    29,    30,    31,    32,    33,    34,    35,
      36,    28,    26,    28,    39,    28,    16,    28,    26,    26,
      26,    18,    40,    27,   133,    27,    19,     5,    79,    19,
      60,   116,    28,   106,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    43,     3,     0,    28,     8,    44,    45,    46,
       3,    47,    48,    49,    41,     6,     7,    51,    52,    53,
      54,    55,    59,    28,    47,    39,    40,     3,     3,     9,
      61,    54,    28,    28,    11,    12,    50,     3,    26,    56,
      57,    56,     3,    15,    17,    20,    21,    61,    62,    63,
      64,    65,    66,    67,    68,    78,    28,    47,    58,    28,
      39,    26,    38,     3,     4,    13,    14,    24,    26,    35,
      36,    71,    73,    74,    75,    76,    77,    78,    71,    26,
      26,    10,    28,    27,    28,    45,    60,    50,    69,    70,
      71,    71,    75,    71,    74,    74,    16,    23,    29,    30,
      31,    32,    33,    34,    35,    36,    72,    22,    25,    37,
      18,    49,    69,    63,    47,    61,    28,    40,    27,    27,
      63,    74,    74,    74,    73,    75,    75,    75,    63,    27,
      27,    60,    71,    19,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    58,    58,    59,    60,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    76,    77,    77,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     1,     2,     3,     2,     3,
       1,     3,     1,     1,     0,     1,     1,     2,     3,     1,
       1,     5,     0,     1,     3,     1,     3,     7,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     6,     4,     4,     4,     1,     3,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     2,     3,     1,     1,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: TK_PROGRAM ID TK_PTVG bloco TK_PT  */
#line 95 "rascal.y"
    {
        raiz = new Programa((yyvsp[-3].sval), (yyvsp[-1].ptr_bloco));
    }
#line 1258 "rascal.tab.c"
    break;

  case 3: /* bloco: possivel_secao_variaveis possivel_secao_subrotinas comando_composto  */
#line 102 "rascal.y"
    {
        (yyval.ptr_bloco) = new Bloco();
        if ((yyvsp[-2].vec_decl_var)) (yyval.ptr_bloco)->vars = *(yyvsp[-2].vec_decl_var);
        if ((yyvsp[-1].vec_decl_sub)) (yyval.ptr_bloco)->subrotinas = *(yyvsp[-1].vec_decl_sub);
        if ((yyvsp[0].vec_comando)) (yyval.ptr_bloco)->comandos = *(yyvsp[0].vec_comando);
        
        delete (yyvsp[-2].vec_decl_var); delete (yyvsp[-1].vec_decl_sub); delete (yyvsp[0].vec_comando);
    }
#line 1271 "rascal.tab.c"
    break;

  case 4: /* possivel_secao_variaveis: %empty  */
#line 114 "rascal.y"
    { 
        (yyval.vec_decl_var) = new std::vector<DeclaracaoVar*>(); 
    }
#line 1279 "rascal.tab.c"
    break;

  case 5: /* possivel_secao_variaveis: secao_declaracao_variaveis  */
#line 118 "rascal.y"
    { 
        (yyval.vec_decl_var) = (yyvsp[0].vec_decl_var); 
    }
#line 1287 "rascal.tab.c"
    break;

  case 6: /* secao_declaracao_variaveis: TK_VAR lista_declaracao_variaveis  */
#line 125 "rascal.y"
    {
        (yyval.vec_decl_var) = (yyvsp[0].vec_decl_var);
    }
#line 1295 "rascal.tab.c"
    break;

  case 7: /* declaracao_tipada: lista_identificadores TK_DOISPT tipo  */
#line 132 "rascal.y"
    {
        (yyval.ptr_decl_var) = new DeclaracaoVar((yyvsp[0].tipo_var), *(yyvsp[-2].vec_str));
        delete (yyvsp[-2].vec_str);
    }
#line 1304 "rascal.tab.c"
    break;

  case 8: /* lista_declaracao_variaveis: declaracao_tipada TK_PTVG  */
#line 140 "rascal.y"
    {
        (yyval.vec_decl_var) = new std::vector<DeclaracaoVar*>();
        (yyval.vec_decl_var)->push_back((yyvsp[-1].ptr_decl_var));
    }
#line 1313 "rascal.tab.c"
    break;

  case 9: /* lista_declaracao_variaveis: lista_declaracao_variaveis declaracao_tipada TK_PTVG  */
#line 145 "rascal.y"
    {
        (yyval.vec_decl_var) = (yyvsp[-2].vec_decl_var);
        (yyval.vec_decl_var)->push_back((yyvsp[-1].ptr_decl_var));
    }
#line 1322 "rascal.tab.c"
    break;

  case 10: /* lista_identificadores: ID  */
#line 153 "rascal.y"
    {
        (yyval.vec_str) = new std::vector<std::string>();
        (yyval.vec_str)->push_back((yyvsp[0].sval));
    }
#line 1331 "rascal.tab.c"
    break;

  case 11: /* lista_identificadores: lista_identificadores TK_VG ID  */
#line 158 "rascal.y"
    {
        (yyval.vec_str) = (yyvsp[-2].vec_str);
        (yyval.vec_str)->push_back((yyvsp[0].sval));
    }
#line 1340 "rascal.tab.c"
    break;

  case 12: /* tipo: TK_BOOLEAN  */
#line 165 "rascal.y"
                 { (yyval.tipo_var) = TipoVar::Boolean; }
#line 1346 "rascal.tab.c"
    break;

  case 13: /* tipo: TK_INTEGER  */
#line 166 "rascal.y"
                 { (yyval.tipo_var) = TipoVar::Integer; }
#line 1352 "rascal.tab.c"
    break;

  case 14: /* possivel_secao_subrotinas: %empty  */
#line 171 "rascal.y"
    { 
        (yyval.vec_decl_sub) = new std::vector<DeclaracaoSub*>(); 
    }
#line 1360 "rascal.tab.c"
    break;

  case 15: /* possivel_secao_subrotinas: secao_declaracao_subrotinas  */
#line 175 "rascal.y"
    { 
        (yyval.vec_decl_sub) = (yyvsp[0].vec_decl_sub); 
    }
#line 1368 "rascal.tab.c"
    break;

  case 16: /* secao_declaracao_subrotinas: lista_declaracao_subrotinas  */
#line 181 "rascal.y"
                                  { (yyval.vec_decl_sub) = (yyvsp[0].vec_decl_sub); }
#line 1374 "rascal.tab.c"
    break;

  case 17: /* lista_declaracao_subrotinas: declaracao_subrotina TK_PTVG  */
#line 186 "rascal.y"
    {
        (yyval.vec_decl_sub) = new std::vector<DeclaracaoSub*>();
        (yyval.vec_decl_sub)->push_back((yyvsp[-1].ptr_decl_sub));
    }
#line 1383 "rascal.tab.c"
    break;

  case 18: /* lista_declaracao_subrotinas: lista_declaracao_subrotinas declaracao_subrotina TK_PTVG  */
#line 191 "rascal.y"
    {
        (yyval.vec_decl_sub) = (yyvsp[-2].vec_decl_sub);
        (yyval.vec_decl_sub)->push_back((yyvsp[-1].ptr_decl_sub));
    }
#line 1392 "rascal.tab.c"
    break;

  case 19: /* declaracao_subrotina: declaracao_procedimento  */
#line 198 "rascal.y"
                              { (yyval.ptr_decl_sub) = (yyvsp[0].ptr_decl_sub); }
#line 1398 "rascal.tab.c"
    break;

  case 20: /* declaracao_subrotina: declaracao_funcao  */
#line 199 "rascal.y"
                        { (yyval.ptr_decl_sub) = (yyvsp[0].ptr_decl_sub); }
#line 1404 "rascal.tab.c"
    break;

  case 21: /* declaracao_procedimento: TK_PROCEDURE ID possivel_parametros_formais TK_PTVG bloco_subrotina  */
#line 204 "rascal.y"
    {
        (yyval.ptr_decl_sub) = new DeclaracaoSub((yyvsp[-3].sval), *(yyvsp[-2].vec_decl_var), (yyvsp[0].ptr_bloco_sub)); 
        delete (yyvsp[-2].vec_decl_var);
    }
#line 1413 "rascal.tab.c"
    break;

  case 22: /* possivel_parametros_formais: %empty  */
#line 211 "rascal.y"
                  { (yyval.vec_decl_var) = new std::vector<DeclaracaoVar*>(); }
#line 1419 "rascal.tab.c"
    break;

  case 23: /* possivel_parametros_formais: parametros_formais  */
#line 212 "rascal.y"
                         { (yyval.vec_decl_var) = (yyvsp[0].vec_decl_var); }
#line 1425 "rascal.tab.c"
    break;

  case 24: /* parametros_formais: TK_ABREPAR lista_declaracao_parametros TK_FECHAPAR  */
#line 216 "rascal.y"
                                                         { (yyval.vec_decl_var) = (yyvsp[-1].vec_decl_var); }
#line 1431 "rascal.tab.c"
    break;

  case 25: /* lista_declaracao_parametros: declaracao_tipada  */
#line 222 "rascal.y"
    {
        (yyval.vec_decl_var) = new std::vector<DeclaracaoVar*>();
        (yyval.vec_decl_var)->push_back((yyvsp[0].ptr_decl_var));
    }
#line 1440 "rascal.tab.c"
    break;

  case 26: /* lista_declaracao_parametros: lista_declaracao_parametros TK_PTVG declaracao_tipada  */
#line 227 "rascal.y"
    {
        (yyval.vec_decl_var) = (yyvsp[-2].vec_decl_var);
        (yyval.vec_decl_var)->push_back((yyvsp[0].ptr_decl_var));
    }
#line 1449 "rascal.tab.c"
    break;

  case 27: /* declaracao_funcao: TK_FUNCTION ID possivel_parametros_formais TK_DOISPT tipo TK_PTVG bloco_subrotina  */
#line 236 "rascal.y"
    {
        (yyval.ptr_decl_sub) = new DeclaracaoSub((yyvsp[-5].sval), *(yyvsp[-4].vec_decl_var), (yyvsp[-2].tipo_var), (yyvsp[0].ptr_bloco_sub));
        delete (yyvsp[-4].vec_decl_var);
    }
#line 1458 "rascal.tab.c"
    break;

  case 28: /* bloco_subrotina: possivel_secao_variaveis comando_composto  */
#line 244 "rascal.y"
    {
        (yyval.ptr_bloco_sub) = new BlocoSub();
        if((yyvsp[-1].vec_decl_var)) (yyval.ptr_bloco_sub)->locais = *(yyvsp[-1].vec_decl_var);
        if((yyvsp[0].vec_comando)) (yyval.ptr_bloco_sub)->comandos = *(yyvsp[0].vec_comando);
        delete (yyvsp[-1].vec_decl_var); delete (yyvsp[0].vec_comando);
    }
#line 1469 "rascal.tab.c"
    break;

  case 29: /* comando_composto: TK_BEGIN lista_comandos TK_END  */
#line 253 "rascal.y"
                                     { (yyval.vec_comando) = (yyvsp[-1].vec_comando); }
#line 1475 "rascal.tab.c"
    break;

  case 30: /* lista_comandos: comando  */
#line 258 "rascal.y"
    {
        (yyval.vec_comando) = new std::vector<Comando*>();
        (yyval.vec_comando)->push_back((yyvsp[0].ptr_comando));
    }
#line 1484 "rascal.tab.c"
    break;

  case 31: /* lista_comandos: lista_comandos TK_PTVG comando  */
#line 263 "rascal.y"
    {
        (yyval.vec_comando) = (yyvsp[-2].vec_comando);
        (yyval.vec_comando)->push_back((yyvsp[0].ptr_comando));
    }
#line 1493 "rascal.tab.c"
    break;

  case 32: /* comando: atribuicao  */
#line 270 "rascal.y"
                 { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1499 "rascal.tab.c"
    break;

  case 33: /* comando: chamada_geral  */
#line 271 "rascal.y"
                    {
        ChamadaFuncao* call = (ChamadaFuncao*)(yyvsp[0].ptr_expr);
        
        (yyval.ptr_comando) = new ChamadaProcedimentoCmd(call->id);
        ((ChamadaProcedimentoCmd*)(yyval.ptr_comando))->args = call->args;
        call->args.clear();
        delete call; 
    }
#line 1512 "rascal.tab.c"
    break;

  case 34: /* comando: condicional  */
#line 279 "rascal.y"
                  { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1518 "rascal.tab.c"
    break;

  case 35: /* comando: repeticao  */
#line 280 "rascal.y"
                { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1524 "rascal.tab.c"
    break;

  case 36: /* comando: leitura  */
#line 281 "rascal.y"
              { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1530 "rascal.tab.c"
    break;

  case 37: /* comando: escrita  */
#line 282 "rascal.y"
              { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1536 "rascal.tab.c"
    break;

  case 38: /* comando: comando_composto  */
#line 284 "rascal.y"
    {
        (yyval.ptr_comando) = new ComandoComposto(*(yyvsp[0].vec_comando)); 
        delete (yyvsp[0].vec_comando);
    }
#line 1545 "rascal.tab.c"
    break;

  case 39: /* atribuicao: ID TK_ATRIB expressao  */
#line 292 "rascal.y"
    {
        (yyval.ptr_comando) = new AtribuicaoCmd((yyvsp[-2].sval), (yyvsp[0].ptr_expr));
    }
#line 1553 "rascal.tab.c"
    break;

  case 40: /* condicional: TK_IF expressao TK_THEN comando  */
#line 300 "rascal.y"
    {
        (yyval.ptr_comando) = new IfCmd((yyvsp[-2].ptr_expr), (yyvsp[0].ptr_comando), NULL);
    }
#line 1561 "rascal.tab.c"
    break;

  case 41: /* condicional: TK_IF expressao TK_THEN comando TK_ELSE comando  */
#line 304 "rascal.y"
    {
        (yyval.ptr_comando) = new IfCmd((yyvsp[-4].ptr_expr), (yyvsp[-2].ptr_comando), (yyvsp[0].ptr_comando));
    }
#line 1569 "rascal.tab.c"
    break;

  case 42: /* repeticao: TK_WHILE expressao TK_DO comando  */
#line 311 "rascal.y"
    {
        (yyval.ptr_comando) = new WhileCmd((yyvsp[-2].ptr_expr), (yyvsp[0].ptr_comando));
    }
#line 1577 "rascal.tab.c"
    break;

  case 43: /* leitura: TK_READ TK_ABREPAR lista_identificadores TK_FECHAPAR  */
#line 318 "rascal.y"
    {
        (yyval.ptr_comando) = new LeituraCmd(*(yyvsp[-1].vec_str));
        delete (yyvsp[-1].vec_str);
    }
#line 1586 "rascal.tab.c"
    break;

  case 44: /* escrita: TK_WRITE TK_ABREPAR lista_expressoes_nao_vazia TK_FECHAPAR  */
#line 326 "rascal.y"
    {
        (yyval.ptr_comando) = new EscritaCmd();
        ((EscritaCmd*)(yyval.ptr_comando))->exprs = *(yyvsp[-1].vec_expr);
        delete (yyvsp[-1].vec_expr);
    }
#line 1596 "rascal.tab.c"
    break;

  case 45: /* lista_expressoes_nao_vazia: expressao  */
#line 335 "rascal.y"
    {
        (yyval.vec_expr) = new std::vector<Expressao*>();
        (yyval.vec_expr)->push_back((yyvsp[0].ptr_expr));
    }
#line 1605 "rascal.tab.c"
    break;

  case 46: /* lista_expressoes_nao_vazia: lista_expressoes_nao_vazia TK_VG expressao  */
#line 340 "rascal.y"
    {
        (yyval.vec_expr) = (yyvsp[-2].vec_expr);
        (yyval.vec_expr)->push_back((yyvsp[0].ptr_expr));
    }
#line 1614 "rascal.tab.c"
    break;

  case 47: /* lista_expressoes: %empty  */
#line 347 "rascal.y"
                  { (yyval.vec_expr) = new std::vector<Expressao*>(); }
#line 1620 "rascal.tab.c"
    break;

  case 48: /* lista_expressoes: lista_expressoes_nao_vazia  */
#line 348 "rascal.y"
                                 { (yyval.vec_expr) = (yyvsp[0].vec_expr); }
#line 1626 "rascal.tab.c"
    break;

  case 49: /* expressao: expressao_simples  */
#line 352 "rascal.y"
                        { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1632 "rascal.tab.c"
    break;

  case 50: /* expressao: expressao_simples relacao expressao_simples  */
#line 354 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria((yyvsp[-1].op_bin), (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1640 "rascal.tab.c"
    break;

  case 51: /* relacao: TK_IGUAL  */
#line 360 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::Equal; }
#line 1646 "rascal.tab.c"
    break;

  case 52: /* relacao: TK_DIF  */
#line 361 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::NotEqual; }
#line 1652 "rascal.tab.c"
    break;

  case 53: /* relacao: TK_MENOR  */
#line 362 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::Less; }
#line 1658 "rascal.tab.c"
    break;

  case 54: /* relacao: TK_MENOR_IG  */
#line 363 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::LessEq; }
#line 1664 "rascal.tab.c"
    break;

  case 55: /* relacao: TK_MAIOR  */
#line 364 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::Greater; }
#line 1670 "rascal.tab.c"
    break;

  case 56: /* relacao: TK_MAIOR_IG  */
#line 365 "rascal.y"
                    { (yyval.op_bin) = OperadorBinario::GreaterEq; }
#line 1676 "rascal.tab.c"
    break;

  case 57: /* expressao_simples: termo  */
#line 369 "rascal.y"
            { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1682 "rascal.tab.c"
    break;

  case 58: /* expressao_simples: TK_ADD termo  */
#line 370 "rascal.y"
                   { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); /* Unario positivo eh ignorado ou tratado */ }
#line 1688 "rascal.tab.c"
    break;

  case 59: /* expressao_simples: TK_SUB termo  */
#line 372 "rascal.y"
    { 
        (yyval.ptr_expr) = new ExpressaoUnaria(OperadorUnario::Negativo, (yyvsp[0].ptr_expr));
    }
#line 1696 "rascal.tab.c"
    break;

  case 60: /* expressao_simples: expressao_simples TK_ADD termo  */
#line 376 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::Add, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1704 "rascal.tab.c"
    break;

  case 61: /* expressao_simples: expressao_simples TK_SUB termo  */
#line 380 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::Sub, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1712 "rascal.tab.c"
    break;

  case 62: /* expressao_simples: expressao_simples TK_OR termo  */
#line 384 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::Or, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1720 "rascal.tab.c"
    break;

  case 63: /* termo: fator  */
#line 390 "rascal.y"
            { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1726 "rascal.tab.c"
    break;

  case 64: /* termo: termo TK_MUL fator  */
#line 392 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::Mul, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1734 "rascal.tab.c"
    break;

  case 65: /* termo: termo TK_DIV fator  */
#line 396 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::Div, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1742 "rascal.tab.c"
    break;

  case 66: /* termo: termo TK_AND fator  */
#line 400 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoBinaria(OperadorBinario::And, (yyvsp[-2].ptr_expr), (yyvsp[0].ptr_expr));
    }
#line 1750 "rascal.tab.c"
    break;

  case 67: /* fator: variavel  */
#line 406 "rascal.y"
               { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1756 "rascal.tab.c"
    break;

  case 68: /* fator: NUM  */
#line 407 "rascal.y"
          { (yyval.ptr_expr) = new IntConstExpr((yyvsp[0].ival)); }
#line 1762 "rascal.tab.c"
    break;

  case 69: /* fator: logico  */
#line 408 "rascal.y"
             { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1768 "rascal.tab.c"
    break;

  case 70: /* fator: chamada_geral  */
#line 409 "rascal.y"
                    { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1774 "rascal.tab.c"
    break;

  case 71: /* fator: TK_NOT fator  */
#line 411 "rascal.y"
    {
        (yyval.ptr_expr) = new ExpressaoUnaria(OperadorUnario::Not, (yyvsp[0].ptr_expr));
    }
#line 1782 "rascal.tab.c"
    break;

  case 72: /* fator: TK_ABREPAR expressao TK_FECHAPAR  */
#line 414 "rascal.y"
                                       { (yyval.ptr_expr) = (yyvsp[-1].ptr_expr); }
#line 1788 "rascal.tab.c"
    break;

  case 73: /* variavel: ID  */
#line 418 "rascal.y"
         { (yyval.ptr_expr) = new VarExpr((yyvsp[0].sval)); }
#line 1794 "rascal.tab.c"
    break;

  case 74: /* logico: TK_FALSE  */
#line 422 "rascal.y"
               { (yyval.ptr_expr) = new BoolConstExpr(ValorBool::False); }
#line 1800 "rascal.tab.c"
    break;

  case 75: /* logico: TK_TRUE  */
#line 423 "rascal.y"
               { (yyval.ptr_expr) = new BoolConstExpr(ValorBool::True); }
#line 1806 "rascal.tab.c"
    break;

  case 76: /* chamada_geral: ID TK_ABREPAR lista_expressoes TK_FECHAPAR  */
#line 428 "rascal.y"
    {
        ChamadaFuncao* call = new ChamadaFuncao((yyvsp[-3].sval));
        call->args = *(yyvsp[-1].vec_expr);
        delete (yyvsp[-1].vec_expr);
        (yyval.ptr_expr) = call;
    }
#line 1817 "rascal.tab.c"
    break;


#line 1821 "rascal.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 437 "rascal.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro Sintatico na linha %d: %s (próximo de '%s')\n", yylineno, s, yytext);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Uso: ./rascal <arquivo_entrada.ras> <arquivo_saida.mepa>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    yyparse();
    
    if (yyin) fclose(yyin);

    if (raiz) {
        AnalisadorSemantico semantico;
        if (semantico.analyze(raiz)) {
            if (freopen(argv[2], "w", stdout) == NULL) {
                perror(argv[2]);
                delete raiz;
                return 1;
            }

            GeradorCodigo gerador;
            gerador.gerar(raiz);
            
            fclose(stdout);

        } else {
            std::cerr << "Erros semanticos encontrados. Compilacao abortada." << std::endl;
            delete raiz;
            return 1;
        }
        delete raiz;
    }
    return 0;
}
