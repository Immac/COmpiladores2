#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>

class Statement{
public:
	virtual void execute() = 0;
	virtual std::string generateCode() {return "Not Implemented";}
};

#endif //STATEMENT_H