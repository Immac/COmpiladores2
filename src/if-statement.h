#ifndef IF_STATEMENT
#define IF_STATEMENT
#include "statement.h"
#include <list>
using namespace std;
class IfStatement : public Statement{
	Expression *condition;
	list<Statement *> ifStatements;
	list<Statement *> elseStatements;
public:
	IfStatement(
			Expression *condition,
			list<Statement *> ifStatements,
			list<Statement *> elseStatements
			)
	:condition(condition),
	ifStatements(ifStatements),
	elseStatements(elseStatements)
	{}
	
	void execute() override{
		if(condition->evaluate()) {
			for(auto statement : ifStatements) {
				statement->execute();
			}
		}
		else {
			for(auto statement : elseStatements) {
				statement->execute();
			}
		}
	}
};

#endif // IF_STATEMENT