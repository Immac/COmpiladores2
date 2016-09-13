#ifndef WHILE_EXPRESSION_H
#define WHILE_EXPRESSION_H

#include "statement.h"
#include <string>

class WhileStatement : public Statement {
	public:
		void execute() {}
		std::string generateCode() override;
};

#endif //WHILE_EXPRESSION_H