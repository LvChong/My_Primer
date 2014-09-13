#include"HasPtr.h"

//copy constructor
HasPtr::HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i){}

//copy assignment operator
HasPtr& HasPtr::operator=(const HasPtr & hp)
{
	*ps = *hp.ps;
	i = hp.i;
}