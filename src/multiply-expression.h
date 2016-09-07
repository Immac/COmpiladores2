#ifndef MULTIPLY_EXPRESSION_H
#define MULTIPLY_EXPRESSION_H

#include "expression.h"

class MultiplyExpression: public Expression {
private:
	Expression *e1,*e2;
public:
	MultiplyExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	int evaluate() override { 
		return e1->evaluate() * e2->evaluate(); 
	}
};


#endif //MULTIPLY_EXPRESSION_H