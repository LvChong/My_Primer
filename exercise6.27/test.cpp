#include<iostream>
#include<vector>
using namespace std;
int sum(initializer_list<int> l)
{
	int s = 0;
	for (auto a : l)
		s += a;
	return s;
}
int main()
{
	int b = sum({ 1, 2, 3, 4, 5 });
	cout<<b<<endl;
	system("pause");
	return 0;
}