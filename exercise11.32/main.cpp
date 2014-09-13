#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

void print_books_order(const multimap<string,string> &books)
{
	auto first_iter = books.begin();
	while (first_iter != books.end())
	{
		auto last_iter = books.upper_bound(first_iter->first);
		vector<pair<string,string>> vec(first_iter, last_iter);
		stable_sort(vec.begin(), vec.end(),
			[](const pair<string, string> &p1,
			const pair<string, string> &p2)
		{return p1.second < p2.second; });
		for (auto p : vec)
		{
			cout << p.first << " : " << p.second << endl;
		}
		first_iter = last_iter;
	}
}
void print_books(const multimap<string, string> &books)
{
	for (auto book : books)
	{
		cout << book.first << " : " << book.second << endl;
	}
}
int main()
{
	multimap<string, string> book_info=
	{ { "Mike", "A love story" }, 
	  { "John", "Happiness" },
	  { "Brown", "Java programing" },
	  { "Brown", "C++ programing" },
	  {"Mike","Love"},
	  {"Brown","April"}
	};
	cout << "Ô­Ê¼Ë³Ðò´òÓ¡" << endl;
	print_books(book_info);
	cout << "ÅÅÐòºóË³Ðò´òÓ¡" << endl;
	print_books_order(book_info);
	

	system("pause");
	return 0;
}