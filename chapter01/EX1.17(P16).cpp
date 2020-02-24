#include<iostream>
int main()
{
	int currval = 0, val = 0;
	if (std::cin >> currval)
	{
		int cnt = 1;
		while (std::cin>>val)
		{
			if (val == currval)
				++cnt;
			else
			{
				std::cout << currval << " occurs "
					<< cnt << " times" << std::endl;
				currval = val;
				cnt = 1;
			}
		}
		std::cout << currval << " occurs "
			<< cnt << " times" << std::endl;
	}
	return 0;
}

/*
如果输入值是相等的，最后会输出该值出现次数，如果没有重复值，每次输出当前值出现1次信息
*/
