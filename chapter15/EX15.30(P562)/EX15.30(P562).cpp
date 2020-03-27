#include"Basket.h"

int main()
{
	Basket b;
	//b.add_item(Quote("978-7-121-15535-2", 128.0));
	b.add_item(Bulk_Quote("978-7-121-15535-2", 128.0, 2, 0.2));
	b.add_item(Bulk_Quote("978-7-121-15535-2", 128.0, 2, 0.2));
	b.add_item(Bulk_Quote("978-7-121-15535-3", 98.0, 3, 0.5));
	b.add_item(Bulk_Quote("978-7-121-15535-3", 98.0, 3, 0.5));
	b.total_recepit(std::cout);
	return 0;
}
