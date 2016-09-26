#ifndef NOT_EXPRESSION_H
#define NOT_EXPRESSION_H

#include "expression.h"
using std::string;

class NotExpression : public Expression {
	private:
	Expression *e1;
	string location;
public:
	NotExpression(Expression *e1)
	: e1(e1)
	{}
	
	string generateCode() override; 
	
	string getLocation() override;
};

#endif // NOT_EXPRESSION_H