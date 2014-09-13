#include"Screen.h"

char Screen::get(pos ht, pos wd) const
{
	pos row = ht*width;
	return contents[row + wd];
}

Screen::pos Screen::size() const
{
	return height * width;
}

