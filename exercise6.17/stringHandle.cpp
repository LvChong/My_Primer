#include"stringHandle.h"
bool if_exist_upper(const string &s)
{
	for (auto c:s)
	if (isupper(c))
		return true;
	return false;
}
void to_lower(string &s)
{
	for (auto &c : s)
		c = tolower(c);
}