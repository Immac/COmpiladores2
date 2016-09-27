#ifndef LESS_THAN_EXPRESSION_H
#define LESS_THAN_EXPRESSION_H

#include "expression.h"
#include <string>
using namespace std;

class LessThanExpression: public Expression {
private:
	Expression *lValue, *rValue;
	string location;
public:
	LessThanExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	string generateCode() override;
	
	string getLocation() override;
};


#endif //LESS_THAN_EXPRESSION_H