#include"EX15.26(P557).h"
int main()
{
	Bulk_Quote b;
	Bulk_Quote br(std::move(b));
	Bulk_Quote b1;
	b1 = std::move(br);
	return 0;
}