#ifndef METHOD_NODEP_H
#define METHOD_NODEP_H

#include "parameter.h"
#include "statement.h"
#include "expression.h"
#include <string>
#include <list>

using namespace std;
class MethodNode {
private:
	Expression *name;
	list<Parameter*> *params;
	list<Statement*> *block;
public:
	MethodNode(Expression *name,list<Parameter*> *params,list<Statement*> *block)
	:name(name),params(params),block(block)
	{}
	
	string generateCode();
};

#endif // METHOD_NODEP_H