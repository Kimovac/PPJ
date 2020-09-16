%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "angle.hpp"
#include "parser.ypp.tab.h"

%}

%%

"[" 				{	return OB; }
"]" 				{	return CB; }
"==" 				{	return EQ; }
"!=" 				{	return NEQ; }
">=" 				{	return GEQ; }
"<=" 				{	return LEQ; }
"<" 				{	return LES; }
">" 				{	return GRE; }
max 				{	return MAX; }
min 				{	return MIN; }
prosek 				{	return AVG; }
rad 				{	return RAD; }
"=" 				{	return ASSIGN; }
[a-z][a-zA-Z0-9]* 	{
						yylval.name = new string(yytext);
						return ID;
					}
[0-9]+ 				{
						yylval.num = atoi(yytext);
						return NUM;
					}

0x[0-9ABCDEF]+		{
						yylval.num = stoul(yytext, nullptr, 16);
					}
[()+*.,/\n-] 		{	return *yytext; }
[ \t] 				{	}
. 					{	
						cerr << "Lex error: " << yytext << endl;
						exit(EXIT_FAILURE);
					}

%%