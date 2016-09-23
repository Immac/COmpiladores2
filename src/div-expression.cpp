#include "div-expression.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string DivExpression::generateCode() {
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "xor edx, edx" << endl
	<< "idiv " << e2->getLocation() << endl
	<< "mov " << this->getLocation() << ", eax" << endl;
	releaseTemp(e1->getLocation());
	releaseTemp(e2->getLocation());
	return ss.str();
}

string DivExpression::getLocation() {
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}