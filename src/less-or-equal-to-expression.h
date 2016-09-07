#ifndef LESS_OR_EQUAL_TO_EXPRESSION_H
#define LESS_OR_EQUAL_TO_EXPRESSION_H

#include "expression.h"

class LessOrEqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
public:
	LessOrEqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	
	int evaluate() override {
		return lValue->evaluate() <= rValue->evaluate();
	}
};


#endif //LESS_OR_EQUAL_TO_EXPRESSION_H