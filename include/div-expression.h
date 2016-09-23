#ifndef DIV_EXPRESSION_H
#define DIV_EXPRESSION_H

#include "expression.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

extern string newTemp();
extern void releaseTemp(string temp);
class DivExpression: public Expression {
private:
	Expression *e1,*e2;
	string location;
public:
	DivExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	
	string generateCode() override;
	
	string getLocation() override;
};


#endif //DIV_EXPRESSION_H