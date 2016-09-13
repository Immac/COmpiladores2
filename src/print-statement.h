#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "statement.h"
#include "expression.h"
#include <iostream>
using namespace std;
class PrintStatement: public Statement {
private:
	Expression *e;
public:
	PrintStatement(Expression *e) 
	: e(e)
	{}
	void execute() override { 
		cout << e->evaluate() << endl; 
	}
	
	string generateCode() override;
};

#endif //PRINT_STATEMENT_H