#include "method-node.h"
#include "id-expression.h"
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;
extern vector<map<string,string>> contexts;
extern int tempCount;

string MethodNode::generateCode(){
		stringstream ss;
		map<string,string> context;
		int paramOffset = 8;
		for(auto param: *params){
			context[param->key] = "dword[ebp + " + to_string(paramOffset) + "]";
			paramOffset += 4;
		}
		auto key = static_cast<IdExpression*>(name)->getKey();
		contexts.push_back(context);
		ss << key << ":" << endl
		<< "push ebp" << endl
		<< "mov ebp, esp" << endl;
		
		stringstream statementsCode;
		for(auto statement: *block) {
			statementsCode << statementsCode;
		}
		ss << "sub esp, " << to_string(tempCount * 4 - 4 ) << endl
		<< statementsCode.str();
		tempCount = 1;
		contexts.pop_back();
		return ss.str();
	}