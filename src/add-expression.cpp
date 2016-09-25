#include "add-expression.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
extern string newTemp();
extern void releaseTemp(string temp);
string AddExpression::generateCode(){
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "add eax, " << e2->getLocation() << endl
	<< "mov " << this->getLocation() << ", eax" << endl;
	releaseTemp(e1->getLocation());
	releaseTemp(e2->getLocation());
	return ss.str();
}

string AddExpression::getLocation() {
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}