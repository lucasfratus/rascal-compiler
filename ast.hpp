#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>

enum class TipoVar { Integer, Boolean };
enum class TipoSubrotina { Procedure, Function };
enum class ValorBool { False, True };

enum class OperadorBinario {
    Equal, NotEqual, Less, LessEq, Greater, GreaterEq,
    Add, Sub, Or,
    Mul, Div, And
};

enum class OperadorUnario {
    Negativo, Not
};


class NoAST {
public:
    virtual ~NoAST() = default;
    virtual void print(int indent = 0) const = 0;
};


// Programa
class Bloco;

class Programa : public NoAST {
public:
    std::string nome;
    Bloco* bloco;

    Programa(const std::string& n, Bloco* b)
        : nome(n), bloco(b) {}

    ~Programa();

    void print(int indent = 0) const override;
};


// Bloco

class DeclaracaoVar;
class DeclaracaoSub;
class Comando;

class Bloco : public NoAST {
public:
    std::vector<DeclaracaoVar*> vars;
    std::vector<DeclaracaoSub*> subrotinas;
    std::vector<Comando*> comandos;

    ~Bloco();

    void print(int indent = 0) const override;
};


// Declaracao de Variaveis
class DeclaracaoVar : public NoAST {
public:
    TipoVar tipo;
    std::vector<std::string> ids;

    DeclaracaoVar(TipoVar t, const std::vector<std::string>& nomes)
        : tipo(t), ids(nomes) {}

    void print(int indent = 0) const override;
};


// Subrotinas
class BlocoSub;

class DeclaracaoSub : public NoAST {
public:
    std::string nome;
    std::vector<DeclaracaoVar*> parametros;
    BlocoSub* corpo;
    TipoSubrotina tipoSub;
    TipoVar tipoRetorno;

    DeclaracaoSub(const std::string& n,
                  const std::vector<DeclaracaoVar*>& params,
                  BlocoSub* c)
        : nome(n), parametros(params), corpo(c),
          tipoSub(TipoSubrotina::Procedure) {}

    DeclaracaoSub(const std::string& n,
                  const std::vector<DeclaracaoVar*>& params,
                  TipoVar ret,
                  BlocoSub* c)
        : nome(n), parametros(params), corpo(c),
          tipoSub(TipoSubrotina::Function), tipoRetorno(ret) {}

    ~DeclaracaoSub();

    void print(int indent = 0) const override;
};

class BlocoSub : public NoAST {
public:
    std::vector<DeclaracaoVar*> locais;
    std::vector<Comando*> comandos;

    ~BlocoSub();

    void print(int indent = 0) const override;
};


// Comandos
class Expressao;

class Comando : public NoAST {};

class AtribuicaoCmd : public Comando {
public:
    std::string id;
    Expressao* expr;

    AtribuicaoCmd(const std::string& i, Expressao* e)
        : id(i), expr(e) {}

    ~AtribuicaoCmd();

    void print(int indent = 0) const override;
};

class ComandoComposto : public Comando {
public:
    std::vector<Comando*> comandos;

    ComandoComposto(const std::vector<Comando*>& c) : comandos(c) {}
    
    ~ComandoComposto();

    void print(int indent = 0) const override; 
};

class ChamadaProcedimentoCmd : public Comando {
public:
    std::string id;
    std::vector<Expressao*> args;

    ChamadaProcedimentoCmd(const std::string& i) : id(i) {}
    ~ChamadaProcedimentoCmd();

    void print(int indent = 0) const override;
};

class IfCmd : public Comando {
public:
    Expressao* cond;
    Comando* thenCmd;
    Comando* elseCmd;

    IfCmd(Expressao* c, Comando* t, Comando* e) 
        : cond(c), thenCmd(t), elseCmd(e) {}

    ~IfCmd();

    void print(int indent = 0) const override;
};

class WhileCmd : public Comando {
public:
    Expressao* cond;
    Comando* corpo;

    WhileCmd(Expressao* cd, Comando* crp)
        : cond(cd), corpo(crp) {}

    ~WhileCmd();

    void print(int indent = 0) const override;
};

class LeituraCmd : public Comando {
public:
    std::vector<std::string> ids;

    LeituraCmd(const std::vector<std::string>& v)
        : ids(v) {}
    
    void print(int indent = 0) const override;
};

class EscritaCmd : public Comando {
public:
    std::vector<Expressao*> exprs;

    ~EscritaCmd();

    void print(int indent = 0) const override;
};


// Expressoes
class Expressao : public NoAST {};

class VarExpr : public Expressao {
public:
    std::string id;

    VarExpr(const std::string& i) : id(i) {}

    void print(int indent = 0) const override;
};

class IntConstExpr : public Expressao {
public:
    int valor;

    IntConstExpr(int v) : valor(v) {}

    void print(int indent = 0) const override;
};

class BoolConstExpr : public Expressao {
public:
    ValorBool valor;

    BoolConstExpr(ValorBool v) : valor(v) {}

    void print(int indent = 0) const override;
};

class ExpressaoBinaria : public Expressao {
public:
    OperadorBinario op;
    Expressao* esq;
    Expressao* dir;

    ExpressaoBinaria(OperadorBinario o, Expressao* e, Expressao* d)
        : op(o), esq(e), dir(d) {}

    ~ExpressaoBinaria();

    void print(int indent = 0) const override;
};

class ExpressaoUnaria : public Expressao {
public:
    OperadorUnario op;
    Expressao* expr;

    ExpressaoUnaria(OperadorUnario o, Expressao* e)
        : op(o), expr(e) {}

    ~ExpressaoUnaria() { delete expr; }

    void print(int indent = 0) const override;
};

class ChamadaFuncao : public Expressao {
public:
    std::string id;
    std::vector<Expressao*> args;

    ChamadaFuncao(const std::string& i) : id(i) {}
    ~ChamadaFuncao();

    void print(int indent = 0) const override;
};

#endif