#ifndef MULTIPLY_EXPRESSION_H
#define MULTIPLY_EXPRESSION_H

#include "expression.h"

class MultiplyExpression: public Expression {
private:
	Expression *e1,*e2;
public:
	MultiplyExpression(Expression *e1,Expression *e2)
	: e1(e1), e2(e2)
	{}
	string location;
	int evaluate() override { 
		return e1->evaluate() * e2->evaluate(); 
	}
	
	string generateCode() override {
		
		stringstream ss;
		ss << e1->generateCode() << endl
			<< e2->generateCode() << endl
			<< "mov eax, " << e1->getLocation() << endl
			<< "imul eax, " << e2->getLocation() << endl
			<< "mov " << this->getLocation() << ", eax" << endl;
			releaseTemp(e1->getLocation());
			releaseTemp(e2->getLocation());
		return ss.str();
	}
	
	string getLocation() override {
		if( this->location.empty() ) {
			this->location = newTemp();
		}
		return this->location;
	}
	
};


#endif //MULTIPLY_EXPRESSION_H