#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;
class book
{
private:
	string isbn = "";
	string bookName = "";
	string author = "";
	string edition = "";
	string pubdate = "";
	double price = 0.0;
public:
	book() = default;
	book(const string& is, const string& bn,
		const string& au, const string& ed, const string& pu, double pr)
		:isbn(is), bookName(bn), author(au), edition(ed), pubdate(pu), price(pr) {}
	book(istream&);
	//other funcitons;
	friend bool operator==(const book&, const book&);
	friend bool operator!=(const book&, const book&);
	friend ostream& operator<<(ostream&, const book&);
	friend istream& operator>>(istream&, book&);
	friend bool operator<(const book&, const book&);
	friend bool operator>(const book&, const book&);
};
book::book(istream& is)
{
	getline(is, isbn);
	getline(is, bookName);
	getline(is, author);
	getline(is, edition);
	getline(is, pubdate);
	is >> price;
}
bool operator==(const book& lhs, const book& rhs)
{
	return lhs.isbn == rhs.isbn;
}
bool operator!=(const book& lhs, const book& rhs)
{
	return !(lhs==rhs);
}
ostream& operator<<(ostream& os, const book& b)
{
	os << b.isbn << " " << b.bookName << " " << b.author << " "
		<< b.edition << " " << b.price << " " << b.pubdate;
	return os;
}
istream& operator>>(istream& is, book& s)
{
	getline(is, s.isbn);
	getline(is, s.bookName);
	getline(is, s.author);
	getline(is, s.edition);
	getline(is, s.pubdate);
	is >> s.price;
	if (is)
		s = book();
	return is;
}
bool operator<(const book& lhs, const book& rhs)
{
	return (lhs.isbn < rhs.isbn) ? true : false;
}
bool operator>(const book& lhs, const book& rhs)
{
	return (lhs.isbn > rhs.isbn) ? true : false;
}
#endif // !BOOK_H
