#include "while-statement.h"
#include <sstream>
#include <string>
extern string newLabel();
using namespace std;
string WhileStatement::generateCode(){
	stringstream ss;
	string label_while = newLabel();
	string label_endwhile = newLabel();
	stringstream blockCode;
	for(Statement * s : *(this->block)){
		blockCode << s->generateCode();
	}
	ss << "while_start" << endl
	<< condition->generateCode() 
	<< label_while << ":" << endl
	<< "cmp " << condition->getLocation() << ", 0" << endl
	<< "je " << label_endwhile << endl
	<< blockCode.str()
	<< "jmp " << label_while << endl
	<< label_endwhile << ":" << endl;
	return ss.str();
}