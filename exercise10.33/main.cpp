#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	ifstream in("numbers.txt");
	istream_iterator<int> in_iter(in), eof;
	vector<int> vec(in_iter, eof);
	
	auto iter = stable_partition(vec.begin(), vec.end(),
		[](int i){return i % 2; });

	
	ofstream odd("oddIntegers.txt"),
		even("evenIntegers.txt");
	ostream_iterator<int> odd_iter(odd, " "), even_iter(even, " ");
	copy(vec.begin(), iter, odd_iter);
	copy(iter, vec.end(), even_iter);
	cout << "end of the program!" << endl;
	system("pause");
	return 0;
}