%{
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include "boolean-literal.h"
#include "while-statement.h"
#include "greater-or-equal-to-expression.h"
#include "greater-than-expression.h"
#include "less-than-expression.h"
#include "less-or-equal-to-expression.h"
#include "equal-to-expression.h"
#include "add-expression.h"
#include "multiply-expression.h"
#include "number-expression.h"
#include "id-expression.h"
#include "assign-statement.h"
#include "print-statement.h"
#include "if-statement.h"
#include "sub-expression.h"
#include "div-expression.h"
#define YYERROR_VERBOSE 1
using namespace std;

int yylex();
void yyerror(const char *str);
void releaseTemp(string location);
string newTemp();
string resolveId();
map<string,Expression *> symbolTable;
map<string,string> symbolTableGen;
list<Statement *> statements;
stack<int> tabStack;
stack<int> buffer;
stack<string> freeTemporaries;
int line;
int tempCount;
int labelNumber;
%}
%union {
    Expression *expression_t;
    Statement *statement_t;
	list<Statement *> *statement_list_t;
}

%token <expression_t> TK_NUM
%token <expression_t> TK_ID
%token <expression_t> TK_TRUE
%token <expression_t> TK_FALSE
%token <statement_t> TK_IF
%token <statement_t> TK_ELSE
%token <statement_t> TK_PRINT
%token <statement_t> TK_ELIF
%token <statement_t> TK_WHILE
%token TK_CLASS
%token TK_INDENT
%token TK_DEDENT
%type <expression_t> E
%type <statement_t> S
%type <statement_list_t> LS
%type <statement_t> IF_STATEMENT
%type <statement_t> WHILE_STATEMENT
%type <statement_list_t> ELSE_OPTIONAL

%nonassoc TK_GTE  TK_LTE TK_ET '<' '>' TK_LBS TK_RBS TK_OR TK_NOT TK_AND

%left '+' '-'
%left '*' '/'

%%

input: LS { statements = *($1); }
| 
;
LS: LS S { $$ = $1; $$->push_back($2); }
| S { $$ = new list<Statement*>; $$->push_back($1); }
;
S: TK_PRINT '(' E ')'{ $$ = new PrintStatement($3);}
| TK_ID '=' E {
	$$ = new AssignStatement($3, 
							static_cast<IdExpression*>($1),
							&symbolTable,
							&symbolTableGen);
}
| IF_STATEMENT {$$ = $1;}
| WHILE_STATEMENT {$$ = $1;}
;
IF_STATEMENT: TK_IF E ':' TK_INDENT LS TK_DEDENT ELSE_OPTIONAL {
	$$ = new IfStatement($2,*$5,*$7);
}
;
ELSE_OPTIONAL: TK_ELSE ':' TK_INDENT LS TK_DEDENT { $$ = $4; }
| TK_ELIF E ':' TK_INDENT LS TK_DEDENT ELSE_OPTIONAL { 
	$$ = new list<Statement*>; 
	$$->push_back(new IfStatement($2,*$5,*$7));
}
| { $$ = new list<Statement *>; }
;
WHILE_STATEMENT: TK_WHILE E ':' TK_INDENT LS TK_DEDENT {
	$$ = new WhileStatement($2,$5);
}
;
E: E '+' E { $$ = new AddExpression($1, $3); }
  | E '*' E { $$ = new MultiplyExpression($1, $3); }
  | E '-' E { $$ = new SubExpression($1, $3); }
  | E '/' E { $$ = new DivExpression($1, $3); }
  | E '<' E { $$ = new LessThanExpression($1, $3); }
  | E '>' E { $$ = new GreaterThanExpression($1, $3); }
  | E TK_LTE E { $$ = new LessOrEqualToExpression($1, $3); }
  | E TK_GTE E { $$ = new GreaterOrEqualToExpression($1, $3); }
  | E TK_ET E { $$ = new EqualToExpression($1, $3); }
  | E TK_LBS E { $$ = new LeftBitShiftExpression($1,$2); }
  | E TK_RBS E { $$ = new RightBitShiftExpression($1,$2); }
  | '(' E ')' { $$ = $2; }
  | TK_NUM { $$ = $1; }
  | TK_ID { $$ = $1 ;}
  | TK_TRUE { $$ = $1;}
  | TK_FALSE {$$ = $1;}
;

%%



void yyerror(const char *str)
{
    cout << str << " line: " << line << endl;
}

string newTemp(){
	int tempOffset;
	stringstream ss;
	if(freeTemporaries.empty()) {
		ss << "dword[ebp -" << tempCount * 4 << "]";
		tempCount++;
	} else {
		ss << freeTemporaries.top();
		freeTemporaries.pop();
	}
	return ss.str();
}

string resolveId(string id){
	if(symbolTableGen.find(id) != symbolTableGen.end()){
	  return symbolTableGen[id];
	}
	string address = newTemp();
	symbolTableGen[id] = address;
	return address;
}

string newLabel(){
	stringstream ss;
	ss << "label" << labelNumber++;
	return ss.str();
}

void releaseTemp(string temp){
	freeTemporaries.push(temp);
}