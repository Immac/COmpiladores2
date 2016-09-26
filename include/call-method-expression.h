#ifndef CALL_METHOD_EXPRESSION
#define CALL_METHOD_EXPRESSION
#include "expression.h"
#include "argument.h"
#include <string>
#include <list>
using namespace std;

class CallMethodExpression : public Expression{
private:
	string key;
	string location;
	list<Argument*>*args;
	string temp;
public:
	CallMethodExpression(Expression *name,list<Argument*>*args);
	string generateCode() override ;
	
	string getLocation() override {
		return location;
	}
};

#endif // CAll_METHOD_EXPRESSION