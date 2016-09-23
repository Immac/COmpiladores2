#include "multiply-expression.h"
#include <sstream>
#include <string>

using namespace std;
extern void releaseTemp(string location);
extern string newTemp();

string MultiplyExpression::generateCode(){
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

string MultiplyExpression::getLocation(){
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}