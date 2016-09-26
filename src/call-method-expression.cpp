#include "call-method-expression.h"
#include "id-expression.h"
#include <sstream>
extern string newTemp();

CallMethodExpression
::CallMethodExpression(Expression *name,list<Argument*>*args)
:args(args){
	this->key = static_cast<IdExpression*>(name)->getKey();
}

string CallMethodExpression::generateCode(){
		string temp = newTemp();
		stringstream ss;
		for(auto arg : *args){
			ss << arg->generateCode();
		}
		ss << "call " << key << endl
		<< "add esp, " << (to_string(args->size() * 4))
		<< "mov " << temp << "eax" << endl;
		this->location = temp;
	}