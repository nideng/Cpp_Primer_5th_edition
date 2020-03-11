#include<iostream>
#include<memory>
using namespace std;
int main()
{
	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
	typedef unique_ptr<int>IntP;
	//IntP p0(ix);
	//invalid conversion from 'int' to 'std::unique_ptr<int>::pointer
	
	IntP p1(pi);
	//code can compile, but will cause error at run time.
	//The reason is that when the unique_ptr p1 is out of scope,
	//delete will be called
	//to free th object.But the object is not allocate using new.Thus, an error
	//would be thrown by operating system.
	
	IntP p2(pi2);
	//code can compile, but cause a dangling pointer at run time.
	//The reason is that the unique_ptr will free the object the raw pointer
    //is pointing to.
	
	IntP p3(&ix);
	//When the unique_ptr goes out of scope, it will call delete to free an
	//obeject not allocated using new.
	
	IntP p4(new int(2048));
	//legal

	IntP p5(p2.get());
	//double free or corruption at run time
	//two unique_ptr are pointing to the same object.Thus, when both are out of
	//scope, Operating system will throw double free or corruption.

	return 0;
}