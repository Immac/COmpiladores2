#include "greater-than-expression.h"
#include <sstream>
using namespace std;
extern string newTemp();
extern void releaseTemp(string temp);
string GreaterThanExpression::generateCode(){
	stringstream ss;
	ss  << lValue->generateCode()
	<< rValue->generateCode()
	<< "mov eax," << lValue->getLocation() << endl
	<< "cmp eax, " << rValue->getLocation() << endl
	<< "setg al" << endl
	<< "movzx " << this->getLocation() << ", al" << endl;
	
	releaseTemp(lValue->getLocation());
	releaseTemp(rValue->getLocation());
	return ss.str();
}

string GreaterThanExpression::getLocation(){
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
};