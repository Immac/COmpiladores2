#ifndef EQUAL_TO_EXPRESSION_H
#define EQUAL_TO_EXPRESSION_H

#include "expression.h"

class EqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
public:
	EqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	string generateCode() override;
	string getLocation() override;
};


#endif //EQUAL_TO_EXPRESSION_H