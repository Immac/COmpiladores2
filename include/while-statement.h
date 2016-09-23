#ifndef WHILE_STATEMENT_H
#define WHILE_STATEMENT_H

#include <string>
#include <list>
#include "statement.h"
#include "expression.h"

class WhileStatement : public Statement {
private:
	Expression *condition;
	list<Statement *> *block;
public:
	WhileStatement(Expression *condition,list<Statement *> *block):
	condition(condition),block(block){}
	void execute() {}
	std::string generateCode() override;
};

#endif //WHILE_STATEMENT_H