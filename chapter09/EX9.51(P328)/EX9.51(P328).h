#ifndef DATE_H
#define DATE_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
struct MONTHES
{
	string MONTHES_SHORT;
	string MONTHES_LONG;
	unsigned MONTHES_VALUE;
};
const vector<MONTHES>MONTHE{ {"Jan","January",1},{"Feb","February",2},{"Mar","March",3},
							 {"Apr","April",4},{"May","May",5},{"Jun","June",6},
						     {"Jul","July",7},{"Aug","August",8},{"Sept","September",9},
						     {"Oct","October",10},{"Nov","November",11}, {"Dec","December",12}
                            };
const string MARKER(" ,/");
class Date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
	vector<string> split(const string& s, vector<size_t>v);//split the whold string and reserve to the vector
	vector<size_t> findmark(const string& s, const string&);//find the pos of all marks and reserve to the vector;
	bool belongs(const string&,const vector<MONTHES>&,unsigned &);
public:
	Date(const string&);
	void getDate();
};
Date::Date(const string& s)
{
	unsigned u=0;
	vector<string> vec = split(s, findmark(s, MARKER));
	if (vec.size() != 3)
		cerr << "The type is wrong" << endl;
	else
	{
		if (belongs(vec[0], MONTHE,u))//The first element 
		{
			if (vec[1].find_first_not_of("0123456789") == vec[1].npos
				&& vec[2].find_first_not_of("0123456789") == vec[2].npos)
			{
				month = u;
				day = stoi(vec[1]);
				year = stoi(vec[2]);
			}
			else
				cerr << "The type is wrong" << endl;
		}
		else
			cerr << "The type is wrong" << endl;
	}
}
vector<string> Date::split(const string& s, vector<size_t>v)
{
	vector<string>vec;
	size_t  p = 0, q = 0;
	while (p < v.size())
	{
		string s1(s, q, v[p] - q);
		vec.push_back(s1);
		q = v[p] + 1;
		++p;
	}
	string s1(s, v.back() + 1);
	vec.push_back(s1);
	return vec;
}
vector<size_t> Date::findmark(const string& s, const string& m)
{
	vector<size_t>vec;
	size_t p = 0;
	while ((p = s.find_first_of(m, p)) != s.npos)
	{
		vec.push_back(p);
		++p;
	}
	return vec;
}
bool Date::belongs(const string& s, const vector<MONTHES>& vec,unsigned&u)
{
	for (const auto& e : vec)
	{
		if ((e.MONTHES_SHORT == s)|| (e.MONTHES_LONG == s)||(to_string(e.MONTHES_VALUE)==s))
		{
			u = e.MONTHES_VALUE;
			return true;
		}
		
	}
	return false;
}
void Date::getDate()
{
	cout << "Year:" << year << '\t' << "Month:" << month << '\t' << "Date:" << day<< endl;
}
#endif // !DATE_H