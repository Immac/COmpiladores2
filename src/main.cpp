#include "statement.h"
#include <stack>
#include <list>
#include <iostream>
using namespace std;
extern int tempCount;
extern int labelNumber;
extern int line;
extern stack<int> tabStack;
extern list<Statement *> statements;
void yyparse();
int main()
{
	tempCount = 1;
	line = 1;
	labelNumber = 1;
	tabStack.push(0);
	yyparse();
	cout << "Code Start: " << endl;
	for(auto statement : statements){
	 cout << statement->generateCode();
}
	return 0;
}