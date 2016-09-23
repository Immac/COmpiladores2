#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
using namespace std;
class Expression {
public:
	virtual int evaluate(){return 0;};
	virtual string generateCode() {return "NOT IMPLEMENTED \n";};
	virtual string getLocation() {return "NOT IMPLEMENTED \n";};
};

#endif //EXPRESSION_H