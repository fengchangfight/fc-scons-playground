#include <iostream>
#include "add.h"
int main()
{
    int a = 3;
    int b = 5;
    int c = add(a, b);
    std::cout << "add result:" << c << "\n";
    return 0;
}
