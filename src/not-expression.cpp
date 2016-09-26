#include "not-expression.h"
#include <sstream>
#include <string>
using std::stringstream;
using std::string;

extern string newTemp();
extern void releaseTemp(string temp);

string NotExpression::generateCode(){
	stringstream ss;
	ss << e1->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "cmp eax, 0" << endl
	<< "sete al" << endl
	<< "movzx " << this->getLocation() << ", al" << endl;
	releaseTemp(e1->getLocation());
	return ss.str();
}

string NotExpression::getLocation() {
	if(this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}