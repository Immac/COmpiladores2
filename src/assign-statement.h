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
	map<string,string> *symbolTableGen;
public:
	AssignStatement(Expression *e, 
					IdExpression *id, 
					map<string,Expression*> *symbolTable,
					map<string,string> *symbolTableGen
   				)
	: e(e), id(id), symbolTable(symbolTable), symbolTableGen(symbolTableGen)
	{}
	
	void execute() override {
		//(*symbolTable)[id->getKey()] = e;
		
		cout << e->generateCode(); // Generate code test
	}
	
	string generateCode() override;
};

#endif // ASSIGN_STATEMENT_H