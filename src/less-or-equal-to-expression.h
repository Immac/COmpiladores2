#ifndef LESS_OR_EQUAL_TO_EXPRESSION_H
#define LESS_OR_EQUAL_TO_EXPRESSION_H

#include "expression.h"
#include <string>
#include <sstream>
using namespace std;
extern string newTemp();
extern void releaseTemp(string temp);
class LessOrEqualToExpression: public Expression {
private:
	Expression *lValue, *rValue;
	string location;
public:
	LessOrEqualToExpression(Expression *lValue,Expression *rValue)
	: lValue(lValue), rValue(rValue)
	{}
	
	int evaluate() override {
		return lValue->evaluate() <= rValue->evaluate();
	}
	
	string generateCode() override {
		stringstream ss;
		ss  << lValue->generateCode()
		<< rValue->generateCode()
		<< "mov eax," << lValue->getLocation() << endl
		<< "cmp eax, " << rValue->getLocation() << endl
		<< "setle al" << endl
		<< "movzx " << this->getLocation() << ", al" << endl;
		
		releaseTemp(lValue->getLocation());
		releaseTemp(rValue->getLocation());
		return ss.str();
	}
	
	string getLocation() override {
		if( this->location.empty() ) {
			this->location = newTemp();
		}
		return this->location;
	}
};

#endif //LESS_OR_EQUAL_TO_EXPRESSION_H