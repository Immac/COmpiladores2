#include "id-expression.h"
extern string resolveId(string id);

string IdExpression::generateCode(){
	return "";
}

string IdExpression::getLocation() {
	return resolveId(this->key);
}