#ifndef HASPTR_H
#define HASPTR_H

#include<string>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)), i(0) { }
	HasPtr(const HasPtr&); //copy constructor
	HasPtr& operator=(const HasPtr&);  // copy-assignment operator
	~HasPtr(){ delete ps; }    //destructor
private:
	string *ps;
	int i;
};

#endif