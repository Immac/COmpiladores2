#include "assign-statement.h"
#include <sstream>
using namespace std;

string AssignStatement::generateCode(){
	stringstream ss;
	ss << e->generateCode()
	<< "mov eax, " << e->getLocation() << endl
	<< "mov " << id->getLocation() << ", eax" << endl;
	return ss.str();
}
