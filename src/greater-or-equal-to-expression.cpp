#include "greater-or-equal-to-expression.h"
#include <sstream>
using namespace std;
extern string newTemp();
extern void releaseTemp(string temp);
string GreaterOrEqualToExpression::generateCode() {
	stringstream ss;
	ss  << lValue->generateCode()
	<< rValue->generateCode()
	<< "mov eax," << lValue->getLocation() << endl
	<< "cmp eax, " << rValue->getLocation() << endl
	<< "setge al" << endl
	<< "movzx " << this->getLocation() << ", al" << endl;
	
	releaseTemp(lValue->getLocation());
	releaseTemp(rValue->getLocation());
	return ss.str();
}

string GreaterOrEqualToExpression::getLocation() {
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
};