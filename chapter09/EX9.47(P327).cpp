//find first of

/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string numbers("0123456789");
	string alphas("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string name("ab2c3d7R4E6");
	size_t p = 0;
	cout << "numbers in the stirng:" << endl;
	while ((p=name.find_first_of(numbers,p))!= name.npos)
	{
		cout << "position: "<<p<<'\t'<<"element: "<<name[p] << endl;
		++p;
	}
	cout << "===========================" << endl;
	cout << "char in the string: " << endl;
	p = 0;
	while ((p=name.find_first_of(alphas,p))!=name.npos)
	{
		cout << "position: " << p << '\t' << "element: " << name[p] << endl;
		++p;
	}
	return 0;
}
*/

//find_first_not of

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string numbers("0123456789");
	string alphas("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string name("ab2c3d7R4E6");
	size_t p = 0;
	cout << "numbers in the stirng:" << endl;
	while ((p = name.find_first_not_of(alphas, p)) != name.npos)
	{
		cout << "position: " << p << '\t' << "element: " << name[p] << endl;
		++p;
	}
	cout << "===========================" << endl;
	cout << "char in the string: " << endl;
	p = 0;
	while ((p = name.find_first_not_of(numbers, p)) != name.npos)
	{
		cout << "position: " << p << '\t' << "element: " << name[p] << endl;
		++p;
	}
	return 0;
}

