%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "nums.hpp"
#include "parser.ypp.tab.h"

%}

%%

"~" 					{	return NEG; }
"[" 					{	return OB; }
"]" 					{	return CB; }
"<<"					{	return SHL; }
">>" 					{	return SHR; }
"=" 					{	return ASSIGN; }
"==" 					{	return EQ; }
print 					{	return PRINT; }
int 					{ 	return INT; }
list 					{ 	return LIST; }
_[a-z]+ 				{ 	yylval.name = new string(yytext);
							return ID;
						}
l[a-z]+ 				{
							yylval.name = new string(yytext);
							return LID;
						}
-?0x[ABCDEF0-9]+ 			{ 	yylval.num = stoi(yytext, nullptr, 16);
							return NUM;
						}
-?0[0-7]+ 				{	yylval.num = stoi(yytext, nullptr, 8);
							return NUM;
						}
-?[1-9]+[0-9]* 			{
							yylval.num = stoi(yytext);
							return NUM;
						}
[0-9]+ 					{
							yylval.num = stoi(yytext);
							return NUM;	
						}
[~;,\n()&\|\^\~\*\+\/-]	{	return *yytext; }
[ \t] 					{ }
. 						{
							cerr << "Lex error: " << yytext << endl;
							exit(EXIT_FAILURE);
						}
%%