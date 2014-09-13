#include <iostream>
#include<string>
using namespace std;
int main()
{
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned int num = 0;
	char ch;
	char pro = ' ';
	while ((ch = getchar()) != 10)
	{
		switch (ch)
		{
		case 'A':
		case 'a' :
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case 'f':
			if (pro == 'f')
				++num;
			break;
		default:
			break;
		}
		pro = ch;
	}
	cout << "a: " << aCnt << endl;
	cout << "e: " << eCnt << endl;
	cout << "i: " << iCnt << endl;
	cout << "o: " << oCnt << endl;
	cout << "u: " << uCnt << endl;
	cout << "num: " << num << endl;
	system("pause");
	return 0;
}