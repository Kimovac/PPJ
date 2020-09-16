parser: parser.ypp.tab.o lex.yy.o 
	g++ -std=c++11 parser.ypp.tab.o lex.yy.o -o parser

lex.yy.o: lex.yy.c parser.ypp.tab.h
	g++ -std=c++11 -c lex.yy.c -o lex.yy.o

parser.ypp.tab.o: parser.ypp.tab.c parser.ypp.tab.h
	g++ -std=c++11 -c parser.ypp.tab.c -o parser.ypp.tab.o

lex.yy.c: parser.ypp.tab.h lexer.l
	flex -l lexer.l

parser.ypp.tab.c parser.ypp.tab.h: parser.ypp
	bison -d -v parser.ypp

.PHONY: clean

clean:
	rm -f parser *.tab.* *.o *.yy.* *.output