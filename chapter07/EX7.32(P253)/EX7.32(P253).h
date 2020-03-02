#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<vector>
using namespace std;

class Screen;
//Window_mgr
class Window_mgr
{
public:
	Window_mgr();
	Window_mgr(initializer_list<Screen>i) :screens(i) {}
	using ScreenIndex = vector<Screen>::size_type;
	Screen& getElement(ScreenIndex i);
	void clear(ScreenIndex);

private:
	vector<Screen>screens;
};


//class Screen
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, '\0') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd),
		contents(ht* wd, c) {}
	char get()const { return contents[cursor]; }
	inline char get(pos ht, pos wd)const;
	Screen set(char);
	Screen set(pos, pos, char);
	Screen move(pos r, pos c);
	Screen display(ostream& os);
	const Screen display(ostream& os)const;
	friend void Window_mgr::clear(ScreenIndex);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(ostream& os)const { os << contents; }
};

//functions in Screen
inline Screen Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c)const
{
	pos row = r * width;
	return contents[row + c];
}
inline Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}
Screen Screen::display(ostream& os)
{
	do_display(os);
	return *this;
}
const Screen Screen::display(ostream& os)const
{
	do_display(os);
	return *this;
}

//functions in Window_mgr
Window_mgr::Window_mgr() :screens{ Screen(5,5,'A') }{}
void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Screen& Window_mgr::getElement(ScreenIndex i)
{
	return screens[i];
}

#endif // !SCREEN_H