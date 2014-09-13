#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include<vector>
using namespace std;
class Screen;
class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
	Window_mgr(const Screen &);
	Screen &theScreen(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	vector<Screen> screens;
};

#endif