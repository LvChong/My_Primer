#include<iostream>
#include"chapter9_exercises.h"
using namespace std;
int main()
{
	//exercise 9.4
	vector<int> vec0 = { 1, 2, 3, 4, 5, 6 };
	bool result;
	result = find1(vec0.begin(), vec0.end(), 1);
	cout << result << endl;
	//exercise 9.5
	vector<int>::iterator iter = find2(vec0.begin(), vec0.end(), 2);
	cout << *iter << endl;
	
	system("pause");
	return 0;
}