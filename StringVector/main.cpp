#include"StrVec.h"
#include<iostream>
using namespace std;

int main()
{
	StrVec vec = { "aaa", "bbb", "ccc" };
	cout << vec.size() << " " << vec.capacity() << endl;
	vec.push_back("ddd");
	vec.print();
	system("pause");
	return 0;
}