#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "expression.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

extern string newTemp();

class AddExpression: public Expression {
private:
	Expression *e1,*e2;
	string location;
public:
	AddExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	int evaluate() override {
		return e1->evaluate() + e2->evaluate();
	}
	string generateCode() override {
		
		stringstream ss;
		ss << e1->generateCode() << endl
			<< e2->generateCode() << endl
			<< "mov eax, " << e1->getLocation() << endl
			<< "add eax, " << e2->getLocation() << endl
			<< "mov " << this->getLocation() << ", eax" << endl;
		return ss.str();
	}
	
	string getLocation() override {
		if( this->location.empty() ) {
			this->location = newTemp();
		}
		return this->location;
	}
};


#endif //ADD_EXPRESSION_H