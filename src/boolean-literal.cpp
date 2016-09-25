#include "boolean-literal.h"
#include <string>
using std::string;
string BooleanLiteral::generateCode(){
	return string();
}

string BooleanLiteral::getLocation(){
	return to_string(this->value);
}