#include<iostream>
using namespace std;
int main()
{
	int num1, num2;
	while (cout<<"please input two integers\n"&&cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
				throw runtime_error("The second number can not be zero!");
			cout << num1 / num2 << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			cout << "Enter y to try again!" << endl;
			char c;
			cin >> c;
			if (c == 'y')
				continue;
			else
				break;
		}
	}
	cout << "out" << endl;
	system("pause");
	return 0;
}