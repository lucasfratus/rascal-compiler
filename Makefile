CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: rascal

rascal: rascal.tab.o lex.yy.o ast.o semantico.o gerador.o symbols.o
	$(CXX) $(CXXFLAGS) -o rascal rascal.tab.o lex.yy.o ast.o semantico.o gerador.o symbols.o -lfl

rascal.tab.c rascal.tab.h: rascal.y
	bison -d -v rascal.y

lex.yy.c: rascal.l
	flex rascal.l

rascal.tab.o: rascal.tab.c ast.hpp semantico.hpp gerador.hpp symbols.hpp
	$(CXX) $(CXXFLAGS) -c rascal.tab.c

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
	rm -f rascal *.o rascal.tab.c rascal.tab.h lex.yy.c rascal.output
