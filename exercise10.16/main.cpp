#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,string::size_type sz)
{
	return s.size() >= sz;
}

void biggies(const vector<string> &words,vector<string>::size_type sz)
{
	auto num = count_if(words.begin(), words.end(),
		bind(check_size, _1, sz));
	cout << "���ȴ���sz�ĵ����У�" << num << "����" << endl;
	cout << "���水ԭ��˳���ӡ��Щ���ȴ���" << sz << "�ĵ���:" << endl;
	for_each(words.begin(), words.end(),
		[sz](const string &s){if (s.size() >= sz) cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> words = { "are", "am", "love", "you", "vector"
		, "string", "ambitious", "basketball", "air", "fuck" };
	for_each(words.begin(), words.end(),
		[](const string &s){cout << s << " "; });
	cout << endl;
	biggies(words, 5);

	for_each(words.begin(), words.end(),
		[](const string &s){cout << s << " "; });
	cout << endl;
	system("pause");
	return 0;
}