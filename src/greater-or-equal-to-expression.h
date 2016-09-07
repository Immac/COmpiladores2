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
	
	int evaluate() override {
		return lValue->evaluate() >= rValue->evaluate();
	}
};


#endif //GREATER_OR_EQUAL_TO_EXPRESSION_H