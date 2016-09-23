#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "expression.h"
#include <map>
#include <string>
using namespace std;

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
	
	string getKey(){return key;}
	
	string generateCode() override;
	
	string getLocation() override;
};


#endif //ID_EXPRESSION_H