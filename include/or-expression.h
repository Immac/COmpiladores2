#ifndef OR_EXPRESSION_H
#define OR_EXPRESSION_H

#include "expression.h"
using std::string;

class OrExpression : public Expression {
	private:
	Expression *e1,*e2;
	string location;
public:
	OrExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	
	string generateCode() override; 
	
	string getLocation() override;
};

#endif // OR_EXPRESSION_H