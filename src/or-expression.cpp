#include "or-expression.h"
#include <sstream>
#include <string>
using std::stringstream;
using std::string;

extern string newTemp();
extern void releaseTemp(string temp);

string OrExpression::generateCode(){
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "or eax, " << e2->getLocation() << endl
	<< "mov " << this->getLocation() << ", eax" << endl;
	releaseTemp(e1->getLocation()); 
	releaseTemp(e2->getLocation());
	return ss.str();
}

string OrExpression::getLocation() {
	if(this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}