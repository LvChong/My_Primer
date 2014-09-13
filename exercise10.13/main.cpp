#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_words(const vector<string> &vec)
{
	for (const auto &w : vec)
		cout << w << " ";
	cout << endl;
}
bool string_size(const string &s)
{
	return s.size() >= 5 ? true : false;
}

int main()
{
	vector<string> vec = { "the", "quik", "red", "fox", "jump",
		"over", "the", "slow", "red", "turtle" };

	vector<string>::iterator iter= 
		partition(vec.begin(), vec.end(), string_size);
	print_words(vec);
	cout << *iter << endl;
	system("pause");
	return 0;
}