#include<iostream>
#include<vector>
using namespace std;
//�ݹ����vector���������
void output_vector(const vector<int>::iterator beg,const vector<int>::iterator end)
{
	if (beg != end)
	{
		cout << *beg << endl;
		output_vector(beg + 1, end);
	}
	return;
}
int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	output_vector(vec.begin(), vec.end());
	system("pause");
	return 0;
}