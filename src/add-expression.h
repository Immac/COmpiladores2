#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "expression.h"

class AddExpression: public Expression {
private:
	Expression *e1,*e2;
public:
	AddExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	int evaluate() override {
		return e1->evaluate() + e2->evaluate(); 
	}
};


#endif //ADD_EXPRESSION_H