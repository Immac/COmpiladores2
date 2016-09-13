#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "expression.h"
#include <map>
#include <string>
using namespace std;
extern string resolveId(string id);
class IdExpression: public Expression {
private:
	string key;
	map<string,Expression *> *symbolTable;
	map<string,string> *symbolTableGen;
public:
	IdExpression(string key,
				 map<string,Expression *> *symbolTable,
				 map<string,string> *symbolTableGen
				)
	: key(key),symbolTable(symbolTable),symbolTableGen(symbolTableGen)
	{}
	int evaluate() override {
		return symbolTable->at(key)->evaluate();
	}
	
	string getKey(){
		return key;
	}
	
	string generateCode() {
		return "";
	}
	
	string getLocation() {
		return resolveId(this->key);
	}
};


#endif //ID_EXPRESSION_H