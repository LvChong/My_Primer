#include"Window_mgr.h"
#include"Screen.h"
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}

Window_mgr::Window_mgr(const Screen &s) :screens(vector<Screen>{s})
{
}

Screen & Window_mgr::theScreen(ScreenIndex i)
{
	Screen &s = screens[i];
	return s;
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}