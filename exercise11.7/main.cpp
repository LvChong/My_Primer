#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

class family_children
{
	map<string, vector<string>> kids;
public:
	void add_family(const string&);
	void add_child(const string&, const string&);
	void output();
};

void family_children::add_family(const string &fami_name)
{
	kids[fami_name];
}

void family_children::add_child(const string &fami_name, const string &kid_name)
{
	kids[fami_name].push_back(kid_name);
}
void family_children::output()
{
	for (const auto&w : kids)
	{
		cout << w.first << " ******* ";
		for (const auto&s : w.second)
			cout << s << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	family_children fami_chil;
	fami_chil.add_family("James");
	fami_chil.add_child("Green", "John");
	fami_chil.output();
	system("pause");
	return 0;
}