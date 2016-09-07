#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "expression.h"
#include <map>
using namespace std;

class IdExpression: public Expression {
private:
	string key;
	map<string,Expression *> *symbolTable;
public:
	IdExpression(string key,
				 map<string,Expression *> *symbolTable)
	: key(key),symbolTable(symbolTable)
	{}
	int evaluate() override {
		return symbolTable->at(key)->evaluate();
	}
	
	string getKey(){
		return key;
	}
};


#endif //ID_EXPRESSION_H