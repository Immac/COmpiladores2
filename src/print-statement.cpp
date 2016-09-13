#include "print-statement.h"
#include <sstream>
using namespace std;
string PrintStatement::generateCode() {
	stringstream ss;
	ss << e->generateCode() 
	<< "push " << e->getLocation() << endl
	<< "push paddr(0x10000000)" << endl
	<< "call @libc.printf" << endl
	<< "add esp, 8" << endl;
	return ss.str();
}