all:
	bison -d -v rascal.y
	flex rascal.l
	gcc -o rascal rascal.tab.c lex.yy.c -lfl

clean:
	rm -f rascal rascal.tab.c rascal.tab.h lex.yy.c rascal.output