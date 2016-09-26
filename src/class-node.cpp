#include "class-node.h"
#include <sstream>
#include <fstream>
#include <iostream>

using std::fstream;
using std::stringstream;
using std::cout;
string ClassNode::generateCode()	{
	stringstream ss;
	ss << "call main \n#stop\n";
	for(auto method : *methods){
		ss << method->generateCode();
	}
	
	fstream file ("output.asm", ios::in|ios::out|ios::trunc | ios::ate); 
	if(!file.is_open()){ 
		cout<< "error when opening file" << endl; exit(22); 
	} file.write(ss.str().c_str(), ss.str().length()); 
	file.close();
	
	return ss.str();
}