#ifndef ASSIGN_STATEMENT_H
#define ASSIGN_STATEMENT_H

#include "expression.h"
#include "statement.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;
class AssignStatement : public Statement {
private:
	Expression *e;
	IdExpression *id;
	map<string,Expression *> *symbolTable;
public:
	AssignStatement(Expression *e, 
					IdExpression *id, 
					map<string,Expression*> *symbolTable)
	: e(e), id(id), symbolTable(symbolTable)
	{}
	
	void execute() override {
		(*symbolTable)[id->getKey()] = e;
		cout << e->generateCode(); // Generate code test
	}
};

#endif // ASSIGN_STATEMENT_H