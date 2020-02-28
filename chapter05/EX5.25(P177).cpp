
#include<iostream>
#include<stdexcept>
using namespace std;
runtime_error err("The second number should not be zero!");
int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		try {
			if (j == 0)
				throw err;
			cout << i / j << endl;
		}
		catch (runtime_error err) {
			cout << err.what()
				<< "\nTry again? Enter y or n" << endl;
		}

		char c;
		cin >> c;
		if (!cin || c == 'n')
			break;
	}
	return 0;
}
