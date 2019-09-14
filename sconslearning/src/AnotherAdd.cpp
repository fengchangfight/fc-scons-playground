#include <iostream>
#include "add.h"
#include "minus.h"
int main()
{
    int a = 3;
    int b = 5;
    int c = add(a, b);
    int d = minus(a, b);
    std::cout << "add result:" << c << "\n";
    std::cout << "minus result:" << d << "\n";

    return 0;
}
