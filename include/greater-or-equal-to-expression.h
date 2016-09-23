#ifndef GREATER_OR_EQUAL_TO_EXPRESSION_H
#define GREATER_OR_EQUAL_TO_EXPRESSION_H

#include "expression.h"

class GreaterOrEqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
public:
	GreaterOrEqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	
	string generateCode() override;
	string getLocation() override;
};


#endif //GREATER_OR_EQUAL_TO_EXPRESSION_H