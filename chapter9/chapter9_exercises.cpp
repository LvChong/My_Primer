#include"chapter9_exercises.h"
#include<iostream>
#include<deque>
#include<list>
#include<string>
using namespace std;

//exercise 9.4
bool find1(vector<int>::const_iterator first, vector<int>::const_iterator last, const int &val)
{
	for (auto iter = first; iter != last; ++iter)
	{
		if (*iter == val)
			return true;
	}
	return false;
}

//exercise 9.5
vector<int>::iterator find2(vector<int>::iterator first, vector<int>::iterator last, const int &val)
{
	for (auto iter = first; iter != last; ++iter)
	{
		if (*iter == val)
			return iter;
	}
	return last;
}

//exercise 9.18
