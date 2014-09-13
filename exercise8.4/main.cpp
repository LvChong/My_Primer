#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
//һ�ζ��ļ���һ��
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
//һ�δ��ļ��ж�һ������
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
//��ӡvector<string>
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
