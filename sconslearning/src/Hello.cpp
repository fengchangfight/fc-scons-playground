#include <iostream>
#include "add.h"
#include "minus.h"
int main()
{
	int a = 1;
	int b = 2;
	int c = add(a, b);
	int d = minus(a, b);
	std::cout << "add result:" << c << "\n";
	std::cout << "minus result4:" << d << "\n";

	return 0;
}
