CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: rascal

rascal: parser.tab.o lex.yy.o ast.o semantico.o gerador.o symbols.o
	$(CXX) $(CXXFLAGS) -o rascal parser.tab.o lex.yy.o ast.o semantico.o gerador.o symbols.o -lfl

parser.tab.c parser.tab.h: parser.y
	bison -d -v parser.y

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.o: parser.tab.c ast.hpp semantico.hpp gerador.hpp symbols.hpp
	$(CXX) $(CXXFLAGS) -c parser.tab.c

lex.yy.o: lex.yy.c ast.hpp
	$(CXX) $(CXXFLAGS) -c lex.yy.c

ast.o: ast.cpp ast.hpp
	$(CXX) $(CXXFLAGS) -c ast.cpp

semantico.o: semantico.cpp semantico.hpp ast.hpp symbols.hpp
	$(CXX) $(CXXFLAGS) -c semantico.cpp

gerador.o: gerador.cpp gerador.hpp ast.hpp symbols.hpp
	$(CXX) $(CXXFLAGS) -c gerador.cpp

symbols.o: symbols.cpp symbols.hpp
	$(CXX) $(CXXFLAGS) -c symbols.cpp

clean:
	rm -f rascal *.o parser.tab.c parser.tab.h lex.yy.c parser.output
