parser: lex.yy.o parser.ypp.tab.o nums.o
	g++ -std=c++11 lex.yy.o parser.ypp.tab.o nums.o -o parser

nums.o: nums.cpp nums.hpp
	g++ -std=c++11 -c nums.cpp -o nums.o

lex.yy.o: lex.yy.c parser.ypp.tab.h
	g++ -std=c++11 -c lex.yy.c -o lex.yy.o

parser.ypp.tab.o: parser.ypp.tab.c parser.ypp.tab.h nums.cpp nums.hpp
	g++ -std=c++11 -c parser.ypp.tab.c -o parser.ypp.tab.o

lex.yy.c: lexer.l parser.ypp.tab.h
	flex -l lexer.l

parser.ypp.tab.c parser.ypp.tab.h: parser.ypp nums.cpp nums.hpp
	bison -d -v parser.ypp

.PHONY: clean

clean:
	rm -f parser *.tab.* *.o *.yy.* *.output