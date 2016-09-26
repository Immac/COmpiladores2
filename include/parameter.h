#ifndef PARAMETER_H
#define PARAMETER_H
#include "expression.h"
#include "id-expression.h"
#include <string>
using std::string;
class Parameter{
public:
	string key;
	string type;
	Parameter(Expression *name,Expression *type)
	{
		this->key = static_cast<IdExpression*>(name)->getKey();
		this->type = static_cast<IdExpression*>(type)->getKey();
	}
};

#endif // PARAMETER_H