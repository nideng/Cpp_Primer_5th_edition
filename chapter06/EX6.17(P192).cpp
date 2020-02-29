/*
Not the same. For the first one "const" was used, since no change need to do for the 
argument. 
For the second function,
"const" can't be used, because the content of the agument should be changed.
*/
#include<iostream>
#include<string>
using namespace std;

bool is_upper(const string& s)
{
	for (auto e : s)
		if(isupper(e)) return true;
	return false;
}

void to_lower(string& s)
{
	for (auto& e : s)
		e = tolower(e);
}

int main()
{
	string s("heLlo");
	cout << is_upper(s) << endl;
	to_lower(s);
	cout << s << endl;
}