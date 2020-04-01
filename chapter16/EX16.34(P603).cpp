template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)return -1;
	else if (rhs < lhs)return 1;
	return 0;
}
int main()
{
	//compare("hi", "world");
	compare("bye", "dad");
}
/*
(a): illegal, as two types are different, the first type being const char[3] ,second const char[6]
(b): legal, the type is const char(&)[4].
*/