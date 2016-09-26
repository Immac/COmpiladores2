#ifndef CLASS_NODE_H
#define CLASS_NODE_H

#include <string>
#include <list>
#include "method-node.h"
#include "expression.h"

using std::string;
using std::list;

class ClassVariable {
private:
	Expression * name,*e;
public:
	ClassVariable(Expression *name,Expression *e)
	: name(name),e(e)
	{}
};

class ClassNode {
private:
	Expression *name;
	list<ClassVariable*> *vars;
	list<MethodNode *> *methods;
public:
	ClassNode(Expression *name,list<ClassVariable *>*vars,list<MethodNode*>*methods)
	:name(name),vars(vars),methods(methods)
	{}
	string generateCode();
};

#endif //CLASS_NODE_H