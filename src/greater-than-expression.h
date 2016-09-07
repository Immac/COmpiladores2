#ifndef GREATER_THAN_EXPRESSION_H
#define GREATER_THAN_EXPRESSION_H

#include "expression.h"

class GreaterThanExpression: public Expression {
private:
	Expression *lValue, *rValue;
public:
	GreaterThanExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	
	int evaluate() override {
		return lValue->evaluate() > rValue->evaluate();
	}
};


#endif //GREATER_THAN_EXPRESSION_H