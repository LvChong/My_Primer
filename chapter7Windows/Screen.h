#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<iostream>
#include"Window_mgr.h"
using namespace std;

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	void do_display(ostream &os) const { os << contents; }
public:
	//构造函数
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd),
		contents(ht * wd, c){}
	Screen(pos ht, pos wd) :height(ht), width(wd),
		contents(ht*wd, ' '){}
	//成员函数
	char get() const { return contents[cursor]; }
	char get(pos, pos) const;
	Screen &move(pos, pos);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os){ do_display(os); return *this; }
	const Screen &display(ostream &os) const { do_display(os); return *this; }
	pos size() const;

};

inline
Screen & Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}
inline
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline
Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
#endif