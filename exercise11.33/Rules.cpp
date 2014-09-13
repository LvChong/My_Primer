#include"Rules.h"
#include<iostream>
#include<fstream>
#include<sstream>
void word_transform(const string&rules_file,const string &input_file)
{
	Rules my_rules(rules_file);
	ifstream input(input_file);
	string text;
	while (getline(input, text))
	{
		istringstream words(text);
		string w;
		bool firstword = true;
		while (words >> w)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			string result;
			my_rules.translate(w, result);
			cout << result;
			
		}
		cout << endl;
	}
}
Rules::Rules(const string &filename)
{
	ifstream in(filename);
	string orig, result;
	while (in >> orig)
	{
		if (getline(in, result))
		{
			remove_spaces(result);
			if (!result.empty())
			{
				// cout << orig << " ***** " << result << endl;
				rules.insert({ orig, result });
			}
			else
				break;
		}
		else
			break;
	}
}

bool Rules::translate(const string &orig, string &result)
{
	auto iter = rules.find(orig);
	if (iter != rules.end())
	{
		result = iter->second;
		return true;
	}
	else
	{
		result = orig;
		return false;
	}
}

void Rules::print_rules()
{
	for (auto rule : rules)
	{
		cout << rule.first << " ***** " << rule.second << endl;
	}
}