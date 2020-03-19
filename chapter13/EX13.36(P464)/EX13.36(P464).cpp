#include"EX13.36(P464).h"
#include <iostream>
using std::cerr; using std::endl; using std::cout;

#include <set>
using std::set;

#include <string>
using std::string;

#include<vector>
using std::vector;

void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	lhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.
	rhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	lhs.add_to_Folders(lhs); // Use existing member function to avoid duplicate code.
	rhs.add_to_Folders(rhs); // Use existing member function to avoid duplicate code.
}

// Message Implementation

void Message::save(Folder& f)
{
	addFldr(&f); // Use existing member function to avoid duplicate code.
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	remFldr(&f); // Use existing member function to avoid duplicate code.
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

Message::Message(const Message& m)
	: contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

// Folder Implementation

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}

Folder::Folder(const Folder& f)
	: msgs(f.msgs)
{
	add_to_Message(f);
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

void Folder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}


int main()
{
	string s1("contents1");
	string s2("contents2");
	string s3("contents3");
	string s4("contents4");
	string s5("contents5");
	string s6("contents6");

	// all new messages, no copies yet
	Message m1(s1);
	Message m2(s2);
	Message m3(s3);
	Message m4(s4);
	Message m5(s5);
	Message m6(s6);

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
