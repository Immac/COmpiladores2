#ifndef EQUAL_TO_EXPRESSION_H
#define EQUAL_TO_EXPRESSION_H

#include "expression.h"
#include <string>
using namespace std;
class EqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
	string location;
public:
	EqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	string generateCode() override;
	string getLocation() override;
};


#endif //EQUAL_TO_EXPRESSION_H