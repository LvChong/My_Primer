#include<vector>
#include<iostream>
using namespace std;

typedef int Func(const int&, const int&);
vector<Func*> vec;
int add(const int &a, const int &b)
{
	return a + b;
}
int sub(const int &a, const int &b)
{
	return a - b;
}
int div(const int &a, const int &b)
{
	return a / b;
}
int mul(const int &a, const int &b)
{
	return a * b;
}

int main()
{
	vec.push_back(add);
	vec.push_back(sub);
	vec.push_back(mul);
	vec.push_back(div);
	int a = 8, b = 4;
	int i = vec[0](a, b);
	int j = vec[1](a, b);
	int k = vec[2](a, b);
	int l = vec[3](a, b);
	cout << i << " " << j << " " << k << " " << l << endl;
	system("pause");
	return 0;
}