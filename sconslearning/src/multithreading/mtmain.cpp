#include <iostream>
#include <vector>
#include <thread>

void accumulator_function2(const std::vector<int> &v, unsigned long long &acm,
                           unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
}

int main()
{
    std::cout << "here i am multithreading...";
    std::vector<int> v;

    int size = 10;
    for (int i = 0; i < size; i++)
    {
        v.push_back(i);
    }

    unsigned long long acm1 = 0;
    unsigned long long acm2 = 0;
    std::thread t1(accumulator_function2, std::ref(v),
                   std::ref(acm1), 0, v.size() / 2);
    std::thread t2(accumulator_function2, std::ref(v),
                   std::ref(acm2), v.size() / 2, v.size());
    t1.join();
    t2.join();

    std::cout << "acm1: " << acm1 << std::endl;
    std::cout << "acm2: " << acm2 << std::endl;
    std::cout << "acm1 + acm2: " << acm1 + acm2 << std::endl;

    return 0;
}