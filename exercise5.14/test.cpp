#include<iostream>
#include<string>
using namespace std;
int main()
{
	string max, cur, pro, repeat;
	unsigned int maxNum = 0, repNum = 0;
	while (cin >> cur)
	{
		if (cur == pro)
			++repNum;
		else
		{
			if (repNum > maxNum)
			{
				maxNum = repNum;
				max = repeat;
			}
			repeat = cur;
			repNum = 1;
		}
		pro = cur;
	}
	cout << max << " " << maxNum << endl;
	system("pause");
	return 0;
}