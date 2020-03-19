#include"StrVec.h"
#include"String.h"
#include"Message.h"
#include<vector>
#include<iostream>
using namespace std;
StrVec func(StrVec& s)
{
	return s;
}
int main()
{
	//the test of StrVec
	StrVec vec{ "hello","world" };
	StrVec vec1 = func(vec);
	for (auto e : vec1)
		cout << e << endl;
	cout << "========================" << endl;
	//the test of String
	vector<String>vec2;
	String s1("hello"), s2("world"), s3("why");
	vec2.push_back(s1);
	vec2.push_back(s2);
	vec2.push_back(s3);
	for (auto e : vec2)
		std::cout << e << std::endl;
	cout << "============================" << endl;
	//the test of Message and Folder;
	string ss1("contents1");
	string ss2("contents2");
	string ss3("contents3");
	string ss4("contents4");
	string ss5("contents5");
	string ss6("contents6");

	// all new messages, no copies yet
	Message m1(ss1);
	Message m2(ss2);
	Message m3(ss3);
	Message m4(ss4);
	Message m5(ss5);
	Message m6(ss6);

	Folder f1;
	Folder f2;

	m1.save(f1); m3.save(f1); m5.save(f1);
	m1.save(f2);
	m2.save(f2); m4.save(f2); m6.save(f2);

	m1.print_debug();
	f2.print_debug();

	// create some copies
	Message c1(m1);
	Message c2(m2), c4(m4), c6(m6);

	m1.print_debug();
	f2.print_debug();

	// now some assignments
	m2 = m3;
	m4 = m5;
	m6 = m3;
	m1 = m5;

	m1.print_debug();
	f2.print_debug();

	// finally, self-assignment
	m2 = m2;
	m1 = m1;

	m1.print_debug();
	f2.print_debug();

	vector<Message> vm;
	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m1);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m2);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m3);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m4);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m5);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m6);

	vector<Folder> vf;
	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(f1);

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(f2);

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder(f1));

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder(f2));

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder());
	return 0;
}