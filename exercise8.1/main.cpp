#include<iostream>
using namespace std;
istream &read_and_print(istream &is)
{
	char s;
	while (is >> s)
	{
		cout << s;
	}
	is.clear();
	return is;
}
int main()
{
	read_and_print(cin);
	system("pause");
	return 0;
}