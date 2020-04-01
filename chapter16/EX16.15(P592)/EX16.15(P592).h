#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<vector>
using namespace std;
using pos = string::size_type;
template<pos, pos>class Screen;

template<pos H,pos W>
ostream& operator<<(ostream&, const Screen<H, W>&);

template<pos H,pos W>
istream& operator>>(istream&, const Screen<H, W>&);
//class Screen
template<pos H, pos W>class Screen
{
	friend ostream& operator<<<H, W>(ostream&,const Screen<H, W>&);
	friend istream& operator>><H, W>(istream&, Screen<H, W>&);
public:
	Screen() = default;
	Screen(char c) :contents(H* W, c) {}
	inline char get()const { return contents[cursor]; }
	inline char get(pos ht, pos wd)const;
	Screen set(char);
	Screen set(pos, pos, char);
	Screen move(pos r, pos c);
	Screen display(ostream& os);
	const Screen display(ostream& os)const;
private:
	pos cursor = 0;
	std::string contents;
	void do_display(ostream& os)const { os << contents; }
};

template<pos H,pos W>
ostream& operator<<(ostream& os, const Screen<H, W>& s)
{
	os << s.contents;
	return os;
}

template<pos H, pos W>
istream& operator>>(istream& is, Screen<H, W>& s)
{
	string t;
	is >> t;
	s.contents = t.substr(0, H * W);
	return is;
}

//functions in Screen
template<pos H, pos W>
inline Screen<H, W> Screen<H, W>::move(pos r, pos c)
{
	pos row = r * W;
	cursor = row + c;
	return *this;
}
template<pos H, pos W>
char Screen<H, W>::get(pos r, pos c)const
{
	pos row = r * W;
	return contents[row + c];
}
template<pos H, pos W>
inline Screen<H, W> Screen<H, W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}
template<pos H, pos W>
inline Screen<H, W> Screen<H, W>::set(pos r, pos col, char ch)
{
	contents[r * W + col] = ch;
	return *this;
}
template<pos H, pos W>
Screen<H, W> Screen<H, W>::display(ostream& os)
{
	do_display(os);
	return *this;
}
template<pos H, pos W>
const Screen<H, W> Screen<H, W>::display(ostream& os)const
{
	do_display(os);
	return *this;
}
#endif // !SCREEN_H