parser: angle.o lex.yy.o parser.ypp.tab.o
	g++ -std=c++11 angle.o lex.yy.o parser.ypp.tab.o -o parser

angle.o: angle.cpp angle.hpp
	g++ -std=c++11 -c angle.cpp -o angle.o

lex.yy.o: lex.yy.c parser.ypp.tab.h
	g++ -std=c++11 -c lex.yy.c -o lex.yy.o

parser.ypp.tab.o: parser.ypp.tab.c parser.ypp.tab.h angle.cpp angle.hpp
	g++ -std=c++11 -c parser.ypp.tab.c -o parser.ypp.tab.o

lex.yy.c: lexer.l parser.ypp.tab.h
	flex -l lexer.l

parser.ypp.tab.c parser.ypp.tab.h: parser.ypp angle.cpp angle.hpp
	bison -d -v parser.ypp

.PHONY: clean

clean:
	rm -f parser *.tab.* *.o *.yy.* *.output