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
	
	int evaluate() override { 
		return value; 
	}
	string generateCode() override {
		return "";
	}
	string getLocation() override {
		return to_string(this->value);
	}
};


#endif //NUMBER_EXPRESSION_H