#ifndef ARGUMENT_H
#define ARGUMENT_H
#include "expression.h"
#include <sstream>
using std::stringstream;
class Argument{
public:
	Expression *param;
	Argument(Expression *param)
	:param(param)
	{}
	
	string generateCode(){
		stringstream ss;
		ss << param->generateCode()
		<< "push " << param->getLocation() << endl;
	}
};

#endif // ARGUMENT_H