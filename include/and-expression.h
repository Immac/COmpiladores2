#ifndef AND_EXPRESSION_H
#define AND_EXPRESSION_H

#include "expression.h"
using std::string;

class AndExpression : public Expression {
	private:
	Expression *e1,*e2;
	string location;
public:
	AndExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	
	string generateCode() override; 
	
	string getLocation() override;
};

#endif // AND_EXPRESSION_H