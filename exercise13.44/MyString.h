#ifndef MYSTRING_H
#define MYSTRING_H

#include<memory>
#include<string>
using namespace std;

class String
{
public:

private:
	static allocator<string> alloc;
	string *sp;
};
#endif