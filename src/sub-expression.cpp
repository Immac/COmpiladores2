#include "sub-expression.h"
#include <sstream>
#include <iostream>

extern string newTemp(string temp);
extern void releaseTemp(string location);
extern string newTemp();
string SubExpression::generateCode(){
	
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "sub eax, " << e2->getLocation() << endl
	<< "mov " << this->getLocation() << ", eax" << endl;
	releaseTemp(e1->getLocation());
	releaseTemp(e2->getLocation());
	return ss.str();
}

string SubExpression::getLocation(){
	if( this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}