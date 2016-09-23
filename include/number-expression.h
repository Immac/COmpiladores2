#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "expression.h"

class NumberExpression: public Expression {
private:
	int value;
public:
	NumberExpression(int value)
	: value(value)
	{}
	
	string generateCode() override;
	string getLocation() override;
};


#endif //NUMBER_EXPRESSION_H