%{

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <stack>

using namespace std;

#include "add-expression.h"
#include "multiply-expression.h"
#include "number-expression.h"
#include "id-expression.h"
#include "assign-statement.h"
#include "print-statement.h"
#include "parser.hpp"

extern map<string,Expression *> symbolTable;
extern map<string,string> symbolTableGen;
extern int line;
extern stack<int> tabStack;
extern stack<int> buffer;
%}

%option noyywrap
%x STRING_S
%x NEWLINE_S
%x TOKENS_IN_BUFFER_S
ID [a-zA-Z][_a-zA-Z0-9]*|[_]+[a-zA-Z0-9][_a-zA-Z0-9]*

%%
<NEWLINE_S>\n //Ignore
<NEWLINE_S>^" "+ {
	cout << yytext <<"NEWLINE_S" << endl;
	BEGIN(INITIAL);
	if(yyleng % 4){
		cout << "Error en linea:" << line << " Identacion invalida." << endl;
		throw "Syntax Error";
	}
	int tabs = yyleng / 4;
	int currentIdentationSize = tabStack.top();
	if(currentIdentationSize + 1 < tabs)
	{
		cout << "Error en linea:" << line << " Identacion invalida." << endl 
		<< "Hay demasiada identacion." << endl;
		throw "Syntax Error";
	}
	if(currentIdentationSize == tabs)
	{
		BEGIN(INITIAL);
		cout << "NO INDENT:" << " CR:" << currentIdentationSize
			<< " NEW:" << tabs  << endl;
		//return TK_INDENT;
	}
	else if(currentIdentationSize < tabs)
	{
		BEGIN(INITIAL);
		cout << "INDENT:" << " CR:" << currentIdentationSize
			<< " NEW:" << tabs  << endl;
		tabStack.push(tabs);
		return TK_INDENT;
	}
	else if(tabs < currentIdentationSize)
	{
		tabStack.pop();
		BEGIN(INITIAL);
		while (tabStack.top() > tabs)
		{
			BEGIN(TOKENS_IN_BUFFER_S);
			tabStack.pop();
			buffer.push(TK_DEDENT);
		}
		return TK_DEDENT;
	}
}
<NEWLINE_S><<EOF>> {
	cout << yytext << "nline eof" <<endl;
	int tabs = 0;
	int currentIdentationSize = tabStack.top();
	if(currentIdentationSize + 1 < tabs)
	{
		cout << "Error en linea:" << line << " Identacion invalida." << endl 
		<< "Hay demasiada identacion." << endl;
		throw "Syntax Error";
	}
	if(currentIdentationSize == tabs)
	{
		BEGIN(INITIAL);
		cout << "NO_INDENT" << tabs  << endl;
		yyterminate();
	}
	if(currentIdentationSize < tabs)
	{
		BEGIN(INITIAL);
		tabStack.push(tabs);
		cout << "INDENT" << tabs  << endl;
		return TK_INDENT;
	}
	else if(tabs < currentIdentationSize)
	{
		tabStack.pop();
		BEGIN(INITIAL);
		while (tabStack.top() > tabs)
		{
			cout << "hola" << endl;
			BEGIN(TOKENS_IN_BUFFER_S);
			tabStack.pop();
			buffer.push(TK_DEDENT);
		}
		return TK_DEDENT;
	}
}
<NEWLINE_S>. {
	cout << yytext << "^[^ ]" <<endl;
	
	yyless(0);
	int tabs = 0;
	int currentIdentationSize = tabStack.top();
	if(currentIdentationSize + 1 < tabs)
	{
		cout << "Error en linea:" << line << " Identacion invalida." << endl 
		<< "Hay demasiada identacion." << endl;
		throw "Syntax Error";
	}
	if(currentIdentationSize == tabs)
	{
		BEGIN(INITIAL);
		cout << "NO_INDENT" << tabs  << endl;
		//return TK_INDENT;
	}
	if(currentIdentationSize < tabs)
	{
		BEGIN(INITIAL);
		tabStack.push(tabs);
		cout << "INDENT" << tabs  << endl;
		return TK_INDENT;
	}
	else if(tabs < currentIdentationSize)
	{
		tabStack.pop();
		BEGIN(INITIAL);
		while (tabStack.top() > tabs)
		{
			cout << "hola" << endl;
			BEGIN(TOKENS_IN_BUFFER_S);
			tabStack.pop();
			buffer.push(TK_DEDENT);
		}
		return TK_DEDENT;
	}
}

<TOKENS_IN_BUFFER_S>. {
	cout << yytext << " TOKENS_IN_BUFFER_S" <<endl;
	yyless(0);
	int count = buffer.size();
	if(count){
		int value = buffer.top();
		buffer.pop();
		return value;
	}
	BEGIN(INITIAL);
}

<<EOF>> {
	cout << yytext << "eof" <<endl;
	int tabs = 0;
	int currentIdentationSize = tabStack.top();
	if(currentIdentationSize + 1 < tabs)
	{
		cout << "Error en linea:" << line << " Identacion invalida." << endl 
		<< "Hay demasiada identacion." << endl;
		throw "Syntax Error";
	}
	if(currentIdentationSize == tabs)
	{
		yyterminate();
	}
	if(currentIdentationSize < tabs)
	{
		BEGIN(INITIAL);
		tabStack.push(tabs);
		cout << "INDENT" << tabs  << endl;
		return TK_INDENT;
	}
	else if(tabs < currentIdentationSize)
	{
		tabStack.pop();
		BEGIN(INITIAL);
		while (tabStack.top() > tabs)
		{
			cout << "hola" << endl;
			BEGIN(TOKENS_IN_BUFFER_S);
			tabStack.pop();
			buffer.push(TK_DEDENT);
		}
		return TK_DEDENT;
	}
}

print { cout << "print" ; return TK_PRINT; }
if { return TK_IF; }
else { cout << "else" << endl; return TK_ELSE; }
elif { cout << "elif" << endl; return TK_ELIF; }
while { cout << "while" << endl; return TK_WHILE; }
{ID} { 
	cout << "TK_ID" << endl;
	string key(yytext);
	yylval.expression_t 
		= new IdExpression(key,&symbolTable,&symbolTableGen);
	return TK_ID;
}


">=" { return TK_GTE;}
"<=" { return TK_LTE;}
"==" { return TK_ET;}
"<" { return '<';}
">" { return '>';}
"+" { return '+'; }
"*" { return '*'; }
"-" { return '-'; }
"/" { return '/'; }
"(" { cout << "(" << endl; return '('; }
")" { cout << ")" << endl; return ')'; }
"=" { cout << "=" << endl; return '='; }
";" { return ';'; }
":" { cout << ":" << endl; return ':'; }
[0-9]+ { 
	cout << "TK_NUM: " << yytext << endl;
	yylval.expression_t = new NumberExpression(stoi(yytext));
	return TK_NUM; 
}

[ \t]+ /*whitespace*/
\n { cout<< "newline" << endl;line++; BEGIN(NEWLINE_S);}
. { cout << "Caracter no valido: " << yytext << "line " << line << endl; throw 1; }
