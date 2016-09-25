#ifndef RIGHT_SHIFT_EXPRESSION_H
#define RIGHT_SHIFT_EXPRESSION_H

#include "expression.h"
#include <string>
using std::string;

class RightShiftExpression : public Expression {
private:
	Expression *e1,*e2;
	string location;
public:
	RightShiftExpression(Expression *e1,Expression *e2)
	:e1(e1),e2(e2)
	{}
	
	string generateCode() override;
	
	string getLocation() override;
};

#endif //RIGHT_SHIFT_EXPRESSION_H