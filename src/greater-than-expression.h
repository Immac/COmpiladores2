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
	
	string generateCode() override;
	string getLocation() override;
};


#endif //GREATER_THAN_EXPRESSION_H