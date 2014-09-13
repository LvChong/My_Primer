#include"stringHandle.h"
#include<iostream>
int main()
{
	string l = "lkjsdaA3";
	cout << l << endl;
	cout << if_exist_upper(l) << endl;
	to_lower(l);
	cout << l << endl;
	system("pause");
	return 0;
}