#ifndef RULES_H
#define RULES_H

#include<string>
#include<map>
using namespace std;

class Rules
{
	map<string, string> rules;
public:
	Rules() = default;
	Rules(const string &filename);
	bool translate(const string&, string&);
	void print_rules();
private:
	void remove_spaces(string &);
};
void word_transform(const string&rules_file, const string &input_file);

inline void Rules::remove_spaces(string &s)
{
	for (auto iter = s.begin(); iter != s.end(); )
	{
		if (isspace(*iter))
		{
			iter = s.erase(iter);
		}
		else
			break;
	}
}
#endif