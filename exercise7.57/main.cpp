#include<string>
#include<iostream>
#include"Account.h"
using namespace std;

int main()
{
	Account account("lv",100);
	double d = account.rate();
	cout << d << endl;
	system("pause");
	return 0;
}