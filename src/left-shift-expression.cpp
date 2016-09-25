#include "left-shift-expression.h"
#include <sstream>

using std::stringstream;
using std::string;
extern string newTemp();
extern void releaseTemp(string temp);

string LeftShiftExpression::generateCode(){
	stringstream ss;
	ss << e1->generateCode() << endl
	<< e2->generateCode() << endl
	<< "mov eax, " << e1->getLocation() << endl
	<< "mov ecx" << e2->getLocation() << endl
	<< "shl eax, cl" << endl
	<< "mov " << this->getLocation() << ",eax " << endl;
	releaseTemp(e1->getLocation());
	releaseTemp(e2->getLocation());
	return "NOTIMPLEMENTED";
}

string LeftShiftExpression::getLocation(){
	return "NOTIMPLEMENTED";
}