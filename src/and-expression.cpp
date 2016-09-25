#include "and-expression.h"
#include <sstream>
#include <string>
using std::stringstream;
using std::string;

extern string newTemp();
extern void releaseTemp(string temp);

string AndExpression::generateCode(){
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "and eax, " << e2->getLocation() << endl
	<< "mov " << this->getLocation() << ", eax" << endl;
	releaseTemp(e1->getLocation());
	releaseTemp(e2->getLocation());
	return ss.str();
}

string AndExpression::getLocation() {
	if(this->location.empty() ) {
		this->location = newTemp();
	}
	return this->location;
}