#ifndef SUB_EXPRESSION_H
#define SUB_EXPRESSION_H

#include "expression.h"

#include <string>

using namespace std;



class SubExpression: public Expression {
private:
	Expression *e1,*e2;
	string location;
public:
	SubExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	
	string generateCode() override;
	
	string getLocation() override;
};


#endif //SUB_EXPRESSION_H