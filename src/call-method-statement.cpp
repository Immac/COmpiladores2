#include "call-method-statement.h"
#include <sstream>
using namespace std;

string CallMethodStatement::generateCode(){
	string temp = newTemp();
	stringstream ss;
	for(auto arg : *args){
		ss << arg->generateCode();
	}
	ss << "call " << key << endl
	<< "add esp, " << to_string(args->size() * 4);
}