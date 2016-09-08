%{
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <stack>
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
#define YYERROR_VERBOSE 1
using namespace std;

int yylex();
void yyerror(const char *str);
string newTemp();
int line;
map<string,Expression *> symbolTable;
list<Statement *> statements;
stack<int> tabStack;
stack<int> buffer;
int tempCount;
%}
%union {
    Expression *expression_t;
    Statement *statement_t;
	list<Statement *> *statement_list_t;
}

%token <expression_t> TK_NUM
%token <expression_t> TK_ID
%token <statement_t> TK_IF
%token <statement_t> TK_ELSE
%token <statement_t> TK_PRINT

%token TK_INDENT
%token TK_DEDENT
%type <expression_t> E
%type <statement_t> S
%type <statement_list_t> LS
%type <statement_t> IF_STATEMENT
%type <statement_list_t> ELSE_OPTIONAL

%nonassoc TK_GTE
%nonassoc TK_LTE
%nonassoc TK_ET
%nonassoc '<'
%nonassoc '>'

%left '+'
%left '*'

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
							 &symbolTable);
	}
| IF_STATEMENT 
;
IF_STATEMENT: TK_IF E ':' TK_INDENT LS TK_DEDENT ELSE_OPTIONAL {
	$$ = new IfStatement($2,*$5,*$7);
}
;
ELSE_OPTIONAL: TK_ELSE ':' TK_INDENT LS TK_DEDENT { $$ = $4; }
| { $$ = new list<Statement *>; }
;
E: E '+' E { $$ = new AddExpression($1, $3); }
  | E '*' E { $$ = new MultiplyExpression($1, $3); }
  | E '<' E { $$ = new LessThanExpression($1, $3); }
  | E '>' E { $$ = new GreaterThanExpression($1, $3); }
  | E TK_LTE E { $$ = new LessOrEqualToExpression($1, $3); }
  | E TK_GTE E { $$ = new GreaterOrEqualToExpression($1, $3); }
  | E TK_ET E { $$ = new EqualToExpression($1, $3); }
  | '(' E ')' { $$ = $2; }
  | TK_NUM { $$ = $1; }
  | TK_ID { $$ = $1 ;}
;

%%

int main()
{
	tempCount = 1;
  tabStack.push(0);
  yyparse();
  cout << "Execution Start: " << endl;
  for(auto statement : statements){
	  statement->execute();
  }
  return 0;
}

void yyerror(const char *str)
{
    cout << str << " line: " << line << endl;
}

string newTemp(){
	int tempOffset = tempCount * 4;
	stringstream ss;
	ss << "[ebp -" << tempOffset << "]";
	tempCount++;
	return ss.str();
}