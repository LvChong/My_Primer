#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
//一次读文件的一行
vector<string> &readFileLine(string filename,vector<string> &vec)
{
	ifstream of(filename);
	string s;
	while (getline(of, s))
	{
		vec.push_back(s);
	}
	of.close();
	return vec;
}
//一次从文件中读一个单词
vector<string> &readFileWord(string filename, vector<string> &vec)
{
	ifstream of(filename);
	string s;
	while (of>>s)
	{
		vec.push_back(s);
	}
	of.close();
	return vec;
}
//打印vector<string>
void printVectorString(const vector<string> &vec)
{
	for (auto s : vec)
		cout << s << "*******";
}
int main()
{
	vector<string> vec1, vec2;
	printVectorString(readFileLine("testFile.txt", vec1));
	cout << endl << endl;
	printVectorString(readFileWord("testFile.txt", vec2));
	system("pause");
	return 0;
}
