#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;
class book
{
private:
	string isbn ;
	string bookName;
	string author ;
	string edition ;
	string pubdate ;
	double price;
public:
	book();
	book(const string& is, const string& bn,
		const string& au, const string& ed, const string& pu, double pr)
		:isbn(is), bookName(bn), author(au), edition(ed), pubdate(pu), price(pr) {}
	book(istream& = cin);
	//other funcitons;
};
book::book() :book("", "", "", "", "", 0.0) 
{}
book::book(istream& is):book()
{
	getline(is, isbn);
	getline(is, bookName);
	getline(is, author);
	getline(is, edition);
	getline(is, pubdate);
	is >> price;
}
#endif // !BOOK_H
