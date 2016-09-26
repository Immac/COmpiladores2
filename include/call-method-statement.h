#ifndef CALL_METHOD_STATEMENT
#define CALL_METHOD_STATEMENT
#include "id-expression.h"
#include "statement.h"
#include "argument.h"
#include <list>
using namespace std;
extern string newTemp();
class CallMethodStatement : public Statement{
private:
	string key, temp;
	list<Argument*> *args;
public:
	CallMethodStatement(Expression *name,list<Argument*> *args)
	:args(args){
		this->key = static_cast<IdExpression*>(name)->getKey();
	}
	void execute() override {}
	string generateCode() override ;
};

#endif // CALL_METHOD_STATEMENT