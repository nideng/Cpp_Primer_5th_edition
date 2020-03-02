#ifdef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;
	string address;
public:
	Person()=default;
	Person(const Person&)=default;
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, Person&);
};


istream& operator>>(istream& is, Person&p)
{
	getline(is, p.name);
	getline(is, p.address);
	return is;
}
ostream& operator<<(ostream& os, Person& p)
{
	os << p.name << endl;
	os << p.address << endl;
	return os;
}
#endif // PERSON_H


