#include "if-statement.h"
#include <sstream>
using namespace std;
extern string newLabel();

string IfStatement::generateCode(){
	string label_else = newLabel();
	string label_endif = newLabel();
	stringstream ss;
	stringstream ifCode;
	stringstream elseCode;
	for(auto statement : ifStatements){
		ifCode << statement->generateCode() << endl;
	}
	for(auto statement : elseStatements){
		elseCode << statement->generateCode() << endl;
	}
	
	ss << condition->generateCode()
	<< "cmp " << condition->getLocation() << ", 0" << endl
	<< "je " << label_else << endl
	<< ifCode.str() << endl
	<< "jmp " << label_endif << endl
	<< label_else << ":" << endl
	<< elseCode.str() << endl
	<< label_endif << ":";
	
	return ss.str();
}