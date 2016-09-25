#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "expression.h"
#include <string>
#include <sstream>
using namespace std;


class AddExpression: public Expression {
private:
	Expression *e1,*e2;
	string location;
public:
	AddExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	
	string generateCode() override; 
	
	string getLocation() override;
};


#endif //ADD_EXPRESSION_H