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

class CAccumulatorFunctor3
{
public:
    void operator()(const std::vector<int> &v,
                    unsigned int beginIndex, unsigned int endIndex)
    {
        _acm = 0;
        for (unsigned int i = beginIndex; i < endIndex; ++i)
        {
            _acm += v[i];
        }
    }
    unsigned long long _acm;
};

void prepareFakeData(std::vector<int> &v)
{
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        v.push_back(i + 1);
    }
}

int main()
{
    std::cout << "here i am multithreading...\n";
    std::vector<int> v;
    prepareFakeData(v);

    unsigned long long acm1 = 0;
    unsigned long long acm2 = 0;
    std::thread t1([&acm1, &v] {
        for (unsigned int i = 0; i < v.size() / 2; ++i)
        {
            acm1 += v[i];
        }
    });
    std::thread t2([&acm2, &v] {
        for (unsigned int i = v.size() / 2; i < v.size(); ++i)
        {
            acm2 += v[i];
        }
    });
    t1.join();
    t2.join();

    std::cout << "acm1: " << acm1 << std::endl;
    std::cout << "acm2: " << acm2 << std::endl;
    std::cout << "acm1 + acm2: " << acm1 + acm2 << std::endl;

    return 0;
}