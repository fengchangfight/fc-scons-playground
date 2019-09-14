#include <iostream>
#include "add.h"
int main()
{
    int a = 1;
    int b = 2;
    int c = add(a, b);
    std::cout << "add result:" << c << "\n";

    return 0;
}
