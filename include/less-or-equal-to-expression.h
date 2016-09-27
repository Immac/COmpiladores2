#ifndef LESS_OR_EQUAL_TO_EXPRESSION_H
#define LESS_OR_EQUAL_TO_EXPRESSION_H

#include "expression.h"
#include <string>
using namespace std;

class LessOrEqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
	string location;
public:
	LessOrEqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	
	int evaluate() override {
		return lValue->evaluate() <= rValue->evaluate();
	}
	
	string generateCode() override;
	
	string getLocation() override;
};

#endif //LESS_OR_EQUAL_TO_EXPRESSION_H