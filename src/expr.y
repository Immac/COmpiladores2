%{
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include "method-node.h"
#include "argument.h"
#include "call-method-statement.h"
#include "call-method-expression.h"
#include "class-node.h"
#include "parameter.h"
#include "not-expression.h"
#include "and-expression.h"
#include "or-expression.h"
#include "left-shift-expression.h"
#include "right-shift-expression.h"
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
vector<map<string,string>> contexts;
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
	ClassNode * class_t;
	MethodNode *method_t;
	list<MethodNode *> *method_list_t;
	list<ClassVariable *> *class_variable_list_t;
	ClassVariable *class_variable_t;
	list<Parameter *> *parameter_list_t;
	Parameter *parameter_t;
	list<Argument*> *argument_list_t;
	Argument * argument_t;
}

%token <expression_t> TK_NUM TK_ID TK_FALSE TK_TRUE
%token <statement_t> TK_IF TK_ELSE TK_PRINT TK_ELIF TK_WHILE
%token TK_CLASS TK_DEDENT TK_DEF TK_INDENT
%type <class_variable_list_t> VARIABLE_LIST
%type <class_variable_t> VARIABLE
%type <parameter_list_t> PARAMETER_LIST
%type <parameter_t> PARAMETER
%type <expression_t> E
%type <statement_list_t> LS
%type <statement_t> IF_STATEMENT WHILE_STATEMENT S
%type <statement_list_t> ELSE_OPTIONAL
%type <class_t> CLASS
%type <method_list_t> METHOD_LIST
%type <method_t> METHOD
%type <argument_list_t> ARGUMENT_LIST

%nonassoc TK_GTE  TK_LTE TK_ET '<' '>' TK_LBS TK_RBS TK_OR TK_NOT TK_AND

%left '+' '-'
%left '*' '/'

%%


/*input: LS { statements = *($1); }
| 
;*/
input: CLASS { $1->generateCode(); }
;
CLASS: TK_CLASS TK_ID ':' TK_INDENT VARIABLE_LIST METHOD_LIST TK_DEDENT {
	$$ = new ClassNode($2,$5,$6);
}
| TK_CLASS TK_ID ':' TK_INDENT METHOD_LIST TK_DEDENT {
	$$ = new ClassNode($2,new list<ClassVariable*>,$5);
}
;
VARIABLE_LIST: VARIABLE_LIST VARIABLE {$$ = $1; $$->push_back($2);}
| VARIABLE {$$ = new list<ClassVariable *>;}
;
VARIABLE: TK_ID '=' E { $$ = new ClassVariable($1,$3); }
;
METHOD: TK_DEF TK_ID '(' PARAMETER_LIST ')' ':' TK_INDENT LS TK_DEDENT {
	$$ = new MethodNode($2,$4,$8);
}
| TK_DEF TK_ID '(' ')' ':' TK_INDENT LS TK_DEDENT {$$ = new MethodNode($2,new list<Parameter*>,$7);}
| TK_DEF TK_ID '(' ')' ':' {$$ = new MethodNode($2,new list<Parameter*>,new list<Statement*>);}
;
METHOD_LIST: METHOD_LIST METHOD {$$ = $1; $$->push_back($2);}
| METHOD {$$ = new list<MethodNode*>; $$->push_back($1);}
;
PARAMETER: TK_ID ':' TK_ID {$$ = new Parameter($1, $3);}
;
PARAMETER_LIST: PARAMETER_LIST ',' PARAMETER { $$ = $1; $1->push_back($3); }
| PARAMETER { $$ = new list<Parameter *> ; $$->push_back($1);}
;
ARGUMENT_LIST: ARGUMENT_LIST ',' E {$$ = $1; $$->push_back(new Argument($3));}
| E {$$ = new list<Argument*>; $$->push_back(new Argument($1));}
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
| TK_ID '(' ARGUMENT_LIST ')' {$$ = new CallMethodStatement($1,$3);}
| TK_ID '(' ')' {$$ = new CallMethodStatement($1,new list<Argument*>);}
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
  | E TK_LBS E { $$ = new LeftShiftExpression($1,$3); }
  | E TK_RBS E { $$ = new RightShiftExpression($1,$3); }
  | E TK_AND E { $$ = new AndExpression($1,$3); }
  | TK_NOT E {$$ = new NotExpression($2);}
  | '(' E ')' { $$ = $2; }
  | TK_NUM { $$ = $1; }
  | TK_ID { $$ = $1 ;}
  | TK_TRUE { $$ = $1;}
  | TK_FALSE {$$ = $1;}
  | TK_ID '(' ARGUMENT_LIST ')' {$$ = new CallMethodExpression($1,$3);}
| TK_ID '(' ')' {$$ = new CallMethodExpression($1,new list<Argument*>);}
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
	for(auto context : contexts)
	{
		if(context.find(id) != context.end()){
			return context.at(id);
		}
	}

	auto context = contexts.back();
	string address = newTemp();
	context[id] = address;
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