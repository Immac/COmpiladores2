#ifndef LEFT_SHIFT_H
#define LEFT_SHIFT_H

#include "expression.h"
#include <string>
using std::string;

class LeftShiftExpression : public Expression {
private:
	Expression *e1,*e2;
public:
	LeftShiftExpression(Expression *e1,Expression *e2)
	:e1(e1),e2(e2)
	{}
	
	string generateCode() override;
	
	string getLocation() override;
};

#endif // LEFT_SHIFT_H