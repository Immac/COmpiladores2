#ifndef BOOLEAN_LITERAL_H
#define BOOLEAN_LITERAL_H

#include "expression.h"
#include <string>
using std::string;
class BooleanLiteral : public Expression {
private:
	int value;
public:
	BooleanLiteral(int value) : value(value) {}
	string generateCode() override;
	string getLocation() override;
};

#endif //BOOLEAN_LITERAL_H