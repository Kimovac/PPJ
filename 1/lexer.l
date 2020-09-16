%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "parser.ypp.tab.h"


%}

%%

x 						{ 	return CON; }
print 					{ 	return PRINT; }
$[a-zA-Z]+[a-zA-Z0-9]* 	{ 
							yylval.str = new string(yytext);
							return VAR;
						}
[0-9]+ 					{ 	
							yylval.num = atoi(yytext);
							return NUM;
						}
[a-zA-Z]+ 				{
							yylval.str = new string(yytext);
							return STR;
						}
[\[\]=x().,*/+;\n-] 			{
							return *yytext;
						}
[ \t] 					{ }
. 						{
							cerr << "Lexer error: " << yytext << endl;
							exit(EXIT_FAILURE);
						}

%%