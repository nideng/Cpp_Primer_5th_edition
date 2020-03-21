#ifndef STRING_H
#define STRING_H
#include<memory>
#include<utility>
#include<iostream>
using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::istream;
using std::ostream;
class String
{
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator<=(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream&, const String&);
	//friend istream& operator>>(istream&, String&);
	//friend String operator+(const String&, const String&);
public:
	String() :elements(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String(String&&)noexcept;
	String& operator=(const String&);
	String& operator=(String&&)noexcept;
	~String();
	char& operator[](size_t n);
	const char& operator[](size_t n)const;
	size_t size()const { return cap - elements; }
	char* begin()const { return elements; }
	char* end()const { return cap; }
private:
	allocator<char>alloc;
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
	char* elements;
	char* cap;
};
pair<char*, char*>
String::alloc_n_copy(const char* b, const char* e)
{
	auto data = alloc.allocate(e - b);
	return{ data,uninitialized_copy(b,e,data) };
}
void String::free()
{
	if (elements) {
		for (auto p = cap; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
String::String(const String& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	cap = newdata.second;
	std::cout << "call String(const String&)" << std::endl;
}
String::String(String&& s)noexcept
	:elements(s.elements), cap(s.cap)
{
	s.elements = s.cap = nullptr;
}
String& String::operator=(String&& s)noexcept
{
	if (this != &s)
	{
		free();
		elements = s.elements;
		cap = s.cap;
		s.elements = s.cap = nullptr;
	}
	return *this;
}
String::~String() { free(); }
String& String::operator=(const String& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	cap = data.second;
	std::cout << "call String& operator=(const String&)" << std::endl;
	return *this;
}
String::String(const char* ch)
{
	auto end = const_cast<char*>(ch);
	while (*end)
		++end;
	auto data = alloc_n_copy(ch, end);
	elements = data.first;
	cap = data.second;
}
ostream& operator<<(ostream& os, const String& s)
{
	for (const auto& e : s)
		os << e;
	return os;
}
bool operator==(const String& lhs, const String& rhs)
{
	return ((lhs.size() == rhs.size()) && std::equal(lhs.begin(), rhs.begin(), rhs.begin()));
}
bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}
bool operator<(const String& lhs, const String& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String& lhs, const String& rhs)
{
	return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

char& String::operator[](size_t n)
{
	return *(elements + n);
}
const char& String::operator[](size_t n)const
{
	return *(elements + n);
}
#endif // !STRING_H