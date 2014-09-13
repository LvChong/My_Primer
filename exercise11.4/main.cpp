#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;
void string_to_lower(string &s)
{
	for (auto &c : s)
		c = tolower(c);
}
void remove_punct(string &s)
{
	auto iter = s.begin();
	while (iter!=s.end())
	{
		if (ispunct(*iter))
		{
			iter = s.erase(iter);
		}
		else
			++iter;
	}
}
int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		string_to_lower(word);
		remove_punct(word);
		++word_count[word];
	}
	cout << endl;
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;
	system("pause");
	return 0;
}