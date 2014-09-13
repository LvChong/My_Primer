#include"Screen.h"
#include"Window_mgr.h"
#include<iostream>
using namespace std;
int main()
{
	Screen myScreen(5, 5, '5');
	Window_mgr window(myScreen);
	window.theScreen(0).display(cout);
	window.clear(0);
	cout << endl;
	window.theScreen(0).display(cout);
	system("pause");
	return 0;
}